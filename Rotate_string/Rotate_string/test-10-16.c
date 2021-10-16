#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

void rotate_string1(char* arr,int k)
{
	int len = strlen(arr);
	int i = 0;

	for (i = 0; i < k; i++)
	{
		char temp = *arr;
		int j = 0;

		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + len - 1) = temp;
	}
}

void revers(char* left, char* right)
{

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void rotate_string2(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k < len);
	revers(arr, arr + k - 1);
	revers(arr+k, arr + len - 1);
	revers(arr, arr + len - 1);
}

int main()
{
	char arr[] = "abcdef";
	int k = 2;
	int j = 0;
	printf("逆转前的arr：%s\n", arr);

	rotate_string1(arr,j);
	rotate_string2(arr, k);

	printf("逆转后的arr：%s\n",arr);
	return 0;
}