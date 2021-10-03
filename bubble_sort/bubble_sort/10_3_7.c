#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <stdlib.h>

bubble_sort(int arr[], int sz)
{
	int i, j;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int arr_cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

struct stu {
	char name[30];
	int age;
};

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,99,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int s_cmp_by_age(const void* p1, const void* p2)
{
	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
}

void test2()
{
	struct stu s[3] = { {"zhangsan", 50},{"lisi",30},{"wangwu",40} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), s_cmp_by_age);
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name,s[i].age);
	}
}

int main()
{

	test1();
	test2();

	return 0;
}