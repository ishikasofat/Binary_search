// Maximize Kth largest element after splitting the given Array at most C times

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the K-th maximum
// element after upto C operations
double maxKth(int arr[], int N,
			int C, int K)
{
	// Check for the base case
	if (N + C < K) {
		return -1;
	}
	// Stores the count iterations of BS
	int iter = 300;

	// Create the left and right bounds
	// of binary search
	double l = 0, r = 1000000000.0;

	// Perform binary search
	while (iter--) {

		// Find the value of mid
		double mid = (l + r) * 0.5;
		double a = 0;
		double b = 0;

		// Traverse the array
		for (int i = 0; i < N; i++) {
			a += int((double)arr[i] / mid);
			if ((double)arr[i] >= mid) {
				b++;
			}
		}

		// Update the ranges
		if (a >= K && b + C >= K) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	// Return the maximum value obtained
	return l;
}

// Driver Code
int main()
{
	int arr[] = { 5, 8 };
	int K = 1, C = 1;
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << maxKth(arr, N, C, K);

	return 0;
}
