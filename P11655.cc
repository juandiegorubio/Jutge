#include <iostream>
#include <vector>
using namespace std;


int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end; 
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end) {
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}



void printSums(int arr[], int start, int end) {
	int newArr[end-start-1];
	for(int i=0; start+i<end; ++i) 
		newArr[i] = arr[start+i];
	
}



int main() {
	// Get the values
	int s, n;
	cin >> s >> n;
	int x[n];
	for(int i=0; i<n; ++i) cin >> x[i];

	// Sort the values
	quickSort(x, 0, n-1);

	int i=0; while(x[i]<=s) i++;

	printSums(x, 0, i);
	
}
