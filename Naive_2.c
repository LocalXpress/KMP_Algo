
#include<stdio.h>

int i=0,j=0;
char str[20],sub[20];

int naive(int x,int y)
{
	if(str[i] == sub[j])
	{
		i++;
		j++;
	}
	if(j == y)
	{
		printf("\npattern is matched at: %d\n",i-j+1);
		i=i-j+1;
		j=0;
	}
	else if(i < x && str[i] != sub[j])
	{
		i=i-j+1;
		j=0;
	}
	if(i < x)
		naive(x,y);
	else
		return;
}

int main()
{
	int a,b;

	printf("enter a string: ");
	gets(str);

	printf("enter the substring: ");
	gets(sub);

	a = strlen(str);
	b = strlen(sub);

	naive(a,b);

	return 0;
}

