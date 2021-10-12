#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>

//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7
//1 3 5 7 2 4 6
//1 3 5 7 9




void swap_parity(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		while (arr[left] % 2 == 1)
		{
			left++;
		}

		while (arr[right] % 2 == 0)
		{
			right--;
		}

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}

int main()
{

	int arr[10] = { 1,5,6,7,8,9,10 };
	int i = 0;

	int sz = sizeof(arr) / sizeof(arr[0]);

	swap_parity(arr, sz);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
