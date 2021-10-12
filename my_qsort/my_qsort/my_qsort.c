#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>

struct in {

	char name[30];
	int age;

};

int arr_cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

void swap(char* p1, char* p2, int width)
{
	int i = 0;
	for ( ; i < width; i++)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
}

void my_qsort(void* bs, int sz, int width, int (*p)(const void*, const void*))
{
	int i, j;
	//确定趟数
	for (i = 0; i < sz - 1; i++)
	{
		//交换的对数
		for (j = 0; j < sz - i - 1; j++)
		{
			if (p((char*)bs + j * width, (char*)bs + (j + 1) * width) > 0)
			{
				//交换
				swap((char*)bs + j * width, (char*)bs + (j + 1) * width, width);
			}
		}
	}
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), arr_cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int a_cmp_by_age(const void* p1, const void* p2)
{
	return ((struct in*)p1)->age - ((struct in*)p2)->age;
}

int a_cmp_by_name(const void* p1, const void* p2)
{
	return strcmp(p1, p2);
}

void test2()
{
	struct in a[] = { {"zhangsan",45},{"lisi",25},{"wangwu",30} };
	int sz = sizeof(a) / sizeof(a[0]);
	//my_qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), a_cmp_by_age);
	my_qsort(a, sz, sizeof(a[0]), a_cmp_by_name);
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", a[i].name, a[i].age);
		;
	}

}

int main()
{
	
	test1();
	test2();

	return 0;
}

