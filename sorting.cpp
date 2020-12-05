//Jonathan Balina

#include<iostream>
#include<array>
#include<algorithm>
#include<chrono>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if((i+1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

void swap(int* item_a, int* item_b) {
	int temp = *item_a;
	*item_a = *item_b;
	*item_b = temp;
}

void bubbleSort(int arr[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void insertionSort(int arr[], int n) {
	int i, j, cur;
	for(i = 1; i < n; i++) {
		cur = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > cur) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = cur;
	}
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int partition(int arr[], int l, int h) {
	int pivot = arr[h]; //use the last element as the pivot
	int i = (l - 1);
		for (int j = l; j <= h-1; j++) {
			if (arr[j] <= pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i+1], &arr[h]);
		return (i+1);
}

void quickSort(int arr[], int l, int h) {
	if (l < h) {

		int pivot = partition(arr, l, h);

		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, h);
	}
}

void quickSort(int arr[], int n) {
	quickSort(arr, 0, n-1);
}

void merge(int arr[], int l, int m, int r) {
	int size1 = m - l + 1;
	int size2 = r - m;
	int tempArr1[size1], tempArr2[size2];

	for (int i = 0; i < size1; i++) {
		tempArr1[i] = arr[l + i];
	}
	for (int j = 0; j < size2; j++) {
		tempArr2[j] = arr[m + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while(i < size1 && j < size2) {
		if(tempArr1[i] <= tempArr2[j]) {
			arr[k] = tempArr1[i];
			i++;
		}
		else {
			arr[k] = tempArr2[j];
			j++;
		}
		k++;
	}
	while(i < size1) {
		arr[k] = tempArr1[i];
		i++;
		k++;
	}
	while(j < size2) {
		arr[k] = tempArr2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if(l>=r)
		return;
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
}

void mergeSort(int arr[], int n) {
	mergeSort(arr, 0, n-1);
}

int main() {
	srand(time(NULL));
	const int n = 100000;
	//const int n = 100;
	int arr[n];
	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 200000 + 1;
		//arr[i] = rand() % 200 + 1;
	}
	int arrCopy[n];
	copy(begin(arr), end(arr), begin(arrCopy));
	cout << "Original array with " << n << " elements:" << endl;
	printArray(arr, n);
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	bubbleSort(arr, n);
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	cout << "Sorted array:" << endl;
	printArray(arr, n);
	cout << "Bubble Sort: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
	copy(begin(arrCopy), end(arrCopy), begin(arr));
	t1 = chrono::steady_clock::now();
	insertionSort(arr, n);
	t2 = chrono::steady_clock::now();
	cout << "Insertion Sort: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
	copy(begin(arrCopy), end(arrCopy), begin(arr));
	t1 = chrono::steady_clock::now();
	heapSort(arr, n);
	t2 = chrono::steady_clock::now();
	cout << "Heap Sort: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
	copy(begin(arrCopy), end(arrCopy), begin(arr));
	t1 = chrono::steady_clock::now();
	mergeSort(arr, n);
	t2 = chrono::steady_clock::now();
	cout << "Merge Sort: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
	copy(begin(arrCopy), end(arrCopy), begin(arr));
	t1 = chrono::steady_clock::now();
	quickSort(arr, n);
	t2 = chrono::steady_clock::now();
	cout << "Quick Sort: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;


	//printArray(arrCopy, n);
}



