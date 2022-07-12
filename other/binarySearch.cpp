#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int value)
{
	if (l > r)
		return -1;
	else
	{
		int mid = (l + r) / 2;
		if (value == arr[mid])
			return mid;
		else if (value > arr[mid])
			binarySearch(arr, mid+1, r, value);
		else 
			binarySearch(arr, l, mid - 1, value);
	}

	return -1;
}

int main()
{
	int arr[] = {3, 8, 10, 33, 15, 17, 43, 90, 11};
	int size = sizeof(arr)/ sizeof(arr[0]);

	int searchvalue = 11;

	sort(arr, arr+ size -1);
	for(auto x : arr)
		cout << x << " ";
	cout << endl;
	int result = binarySearch(arr, 0, size, searchvalue);

	if (result != -1)
		cout << "fond at position: " << result << " value : " << arr[result] << endl;
	else
		cout << "not found value : " << searchvalue;

	return 0;
}