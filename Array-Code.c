// Q.1
  
  
#include<stdio.h>
main()
{
	int a[5],b[5],c[5],i,sum=0,avg;
	
	printf("Enter five values for 1st array=");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("Enter five values for 2st array=");
		for(i=1;i<=5;i++)
	{
		scanf("%d",&b[i]);
		
	}
	
	for(i=1;i<=5;i++)
	{
		c[i]=a[i]+b[i];
		
	}
		for(i=1;i<=5;i++)
	{
		sum=sum+c[i];
		
	}
		printf("The sum of two 1-d arrays are=");
	for(i=1;i<=5;i++)
	{
	
	printf("\n%d+%d=%d",a[i],b[i],c[i]);
}
	avg=sum/5;
	
	printf("\nThe average of third is=%d",avg);
}   
