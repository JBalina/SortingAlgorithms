//Jonathan Balina

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
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
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr, n);
	printArray(arr, n);
}



