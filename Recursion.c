// Recursion 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 
#include<stdio.h>
#include<conio.h>

int fun(int a)
{
	int s;
	if(a==1)
	{
		return (a);
	}
	s=a+fun(a-1);
	return (s);
}

  



main()
{
	
	int k;
	k=fun(10);
	printf("%d",k);
	
	
	
	
	
	
	
}
