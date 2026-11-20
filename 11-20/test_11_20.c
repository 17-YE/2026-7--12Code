//X01 成绩等级评定
#include <stdio.h>
int main()
{
	int s = 0;
	scanf("%d",&s);
	if(0 <= s&&s <= 100)
	{
		switch(s / 10)
		{
			case 10:case 9:
				printf("A\n");
				break;
			case 8:
				printf("B\n");
				break;
			case 7:
				printf("C\n");
				break;
			case 6:
				printf("D\n");
				break;
			default:
				printf("E\n");
		}
	}
	else
	{
		printf("Error");
	}	
	return 0;
}
