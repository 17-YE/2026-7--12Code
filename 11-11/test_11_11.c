//判断大小端排序
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
		printf("大端");
	}
	else
	{
		printf("小端"); 
	}
	return 0;
 } 
