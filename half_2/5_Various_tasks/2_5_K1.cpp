#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

long long merge(int * a, int first, int last) {
	long long count = 0;
	int left = first;
	int right = (first + last) / 2 + 1;
	int * t = new int[last - first + 1];
	for (int i = 0; i < last - first + 1; i++) {
		if (left <= (first + last) / 2 && (right > last || a[left] <= a[right])) {
			t[i] = a[left];
			left++;
		}
		else {
			t[i] = a[right];
			count += right - (first + i);
			right++;
		}
	}
	for (int i = 0; i < last - first + 1; i++) {
		a[first + i] = t[i];
	}
	return count;
}

long long mergeSort(int * a, int first, int last) {
	if (first >= last) return 0;
	return mergeSort(a, first, (last + first) / 2) + mergeSort(a, (last + first) / 2 + 1, last) + merge(a, first, last);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << mergeSort(arr, 0, n - 1) << endl;
	return 0;
}
