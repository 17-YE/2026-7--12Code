//P02 数位统计与逆序
#include <stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int a = 0;
	scanf("%d",&n);
	if(n == 0)
	{
		printf("1\n");
	}
	else
	{
		while(n > 0)
		{
			i++;
			a = a * 10 + n % 10;
			n /= 10;
		}
		printf("%d\n",i);
	}
	printf("%d\n",a);
	return 0;
}
