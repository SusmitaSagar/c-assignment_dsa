// recursive function of Quicksort

#include <bits/stdc++.h>

using namespace std;

void swap(int* num1, int* num2) //swap
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
 
int partition(int arr[], int starting_index, int ending_index)
{
	int x = arr[ending_index];
	int i = (starting_index - 1);

	for (int j = starting_index; j <= ending_index - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[ending_index]);
	return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSort(int A[], int starting_index, int ending_index)
{
	if (starting_index < ending_index) {
		/* Partitioning index */
		int p = partition(A, starting_index, ending_index);
		quickSort(A, starting_index, p - 1);
		quickSort(A, p + 1, ending_index);
	}
}

// Driver code
int main()
{

	int n = 3;
	int arr[n] = { 8, 3, 6, 4, 1 };

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
