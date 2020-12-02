//Jonathan Balina

#include<iostream>

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
/*
void mergeSort() {

}
*/
int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printArray(arr, n);
}



