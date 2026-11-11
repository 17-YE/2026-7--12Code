//≈–∂œ¥Û–°∂À≈≈–Ú 
#include<stdio.h>
int check_sys()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	if(check_sys() == 1)
	{
		printf("¥Û∂À");
	}
	else
	{
		printf("–°∂À"); 
	}
	return 0;
 } 
