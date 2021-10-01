#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>

char * casecon(char str[], int sz)
{
	int i = 0;
	char str1[1000] = { 0 };
	for (i = 0; i < sz; i++)
	{
	
		if (str[i] >= 65 && str[i] <= 90)
		{
			str1[i] = str[i] + 32;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			str1[i] = str[i] - 32;
		}
		else
		{
			str1[i] = str[i];
		}
		
	}
	printf("%s", str1);
}

int main()
{
	
	char str[] ="fhj  f jhf";
	int sz = strlen(str);
	
	casecon(str, sz);
	
	return 0;
}

