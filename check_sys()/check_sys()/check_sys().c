#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
check_sys()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("small\n");
	}
	else
	{
		printf("big\n");
	}
	return 0;
}
