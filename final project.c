#include<stdio.h>
#include<string.h>
struct showroom
{
	char name[1000];
	int price;
	char type;
	char engine[100];
};
struct showroom input();
int delete(char del[100],struct showroom s);
int getNum(char ty,struct showroom s[100], int n);
int isEmpty(struct showroom s[100], int l);
int isFull(struct showroom s[100], int l);
struct showroom UpdateDetails(struct showroom s, struct showroom s1);
char* getLongestPeriod(struct showroom l[100], int n);
void unique(struct showroom s[100], int n);
void lunion(struct showroom s[100], struct showroom s1[100], int n, int l);
void intersection(struct showroom s[100],struct showroom s1[100], int n, int l);
void difference(struct showroom s[100], struct showroom s1[100],int n, int l);
void symmetricDifference(struct showroom s[100], struct showroom s1[100], int n, int l);
void display(struct showroom s[100], int n);
void main()
{
	int choice, i=0, n, j, l, k, m;
	struct showroom list[100], list1[100], list2[100]; 
	while(i!=1)
	{
		printf("What do you wish to perform?\n1-To insert data\n2-To delete data\n3-Get number of type of cars\n4-To check if the entered list is empty\n5-To check if entered list is full\n6-To update details\n7-To get the longest period of cars used\n8-To find the unique details in list\n9-To find the union of two lists\n10-To find the intersection data of lists\n11-To find the data present only in the 1st list compared to 2nd\n12-To find the list of data present in 1st but not in 2nd and in 2nd but not in 1st\n13-To print the details\n");
	    scanf("%d",&choice);
    	switch(choice)
	    {
		    case 1:printf("Enter the number of cars/bikes whose data is to be entered: \n");
		           scanf("%d",&n);
		           for(j=0;j<n;j++)
		               list[j]=input();
		           break;
	    	case 2:printf("Enter the name of car/bikes whose details are to be deleted : \n");
	    	       char name[100];
	    	       int f=0;
	    	       struct showroom lis;
	    	       fgets(name,sizeof(name),stdin);
	    	       for(j=0;j<n;j++)
	    	       {
	    	       	   if(delete(name,list[j])==1)
	    	       	   {
	    	       	   	   list[j]=lis;
	    	       	   	   f=1;
	    	       	   	   break;
					   }
				   }
				   if(f==1)
				       printf("Data deleted successfully\n");
				   else
				       printf("Data not found\n");
				   break;
		    case 3:printf("No. of hatchback cars = %d\n",getNum('h',list,n));
			       printf("No. of sedan cars = %d\n",getNum('s',list,n));
			       printf("No. of bikes = %d\n",getNum('b',list,n));
			       break;
		    case 4:printf("Enter the number of cars/bikes whose data is to be entered: \n");
		           scanf("%d",&l);
		           for(j=0;j<l;j++)
		               list1[j]=input();
		           if(isEmpty(list1,l)==1)
		               printf("List is empty\n");
		           else
		               printf("List is not empty\n");
		           break;
		    case 5:printf("Enter the number of cars/bikes whose data is to be entered: \n");
		           scanf("%d",&l);
		           for(j=0;j<l;j++)
		               list1[j]=input();
		           if(isFull(list1,l)==1)
		               printf("List is full\n");
		           else
		               printf("List is not full\n");
		           break;
		    case 6:printf("Enter the number of cars/bikes whose details are to be updated: \n");
		           scanf("%d",&l);
		           printf("Create the list of details of the car/bike to be updated: \n");
		           for(j=0;j<l;j++)
		               list1[j]=input();
		           for(k=0;k<l;k++)
		               for(j=0;j<n;j++)
					       list[j]=UpdateDetails(list[j],list1[k]);
		           break;
		    case 7:printf("Car with the longest period of duration for 1st service = %s\n",getLongestPeriod(list, n));
		           break;
		    case 8:printf("Enter the number of cars/bikes in duplicated list: \n");
		           scanf("%d",&l);
		           for(j=0;j<l;j++)
		               list1[j]=input();
		           unique(list1,l);
		           break;
		    case 9:printf("Enter the count of data of 1st list: \n");
		           scanf("%d",&l);
		           for(j=0;j<l;j++)
		               list1[j]=input();
		           printf("Enter the count of data of 2nd list: \n");
		           scanf("%d",&m);
		           for(j=0;j<m;j++)
		               list2[j]=input();
		           lunion(list1,list2,l,m);
		           break;
		    case 10:printf("Enter the count of data of 1st list: \n");
		            scanf("%d",&l);
		            for(j=0;j<l;j++)
		                list1[j]=input();
		            printf("Enter the count of data of 2nd list: \n");
		            scanf("%d",&m);
		            for(j=0;j<m;j++)
		                list2[j]=input();
		            intersection(list1,list2,l,m);
		            break;
		    case 11:printf("Enter the count of data of 1st list: \n");
		            scanf("%d",&l);
		            for(j=0;j<l;j++)
		                list1[j]=input();
		            printf("Enter the count of data of 2nd list: \n");
		            scanf("%d",&m);
		            for(j=0;j<m;j++)
		                list2[j]=input();
		            difference(list1,list2,l,m);
		            break;
		    case 12:printf("Enter the count of data of 1st list: \n");
		            scanf("%d",&l);
		            for(j=0;j<l;j++)
		                list1[j]=input();
		            printf("Enter the count of data of 2nd list: \n");
		            scanf("%d",&m);
		            for(j=0;j<m;j++)
		                list2[j]=input();
		            symmetricDifference(list1,list2, l, m);
		            break;
		    case 13:display(list1,n);
			        break;
		    default:("Invalid Input. Try Again!\n");
	    }
	    printf("If you wish to discontinue then enter 1, else any other number: \n");
	    scanf("%d",&i);
	}
}
struct showroom input()
{
	struct showroom s;
	printf("Enter the name of car(Suzuki/Ciaz/Alto800/WagonR/etc)/bike: \n");
	scanf("%s",&s.name);
	printf("Enter the price: \n");
	scanf("%d",&s.price);
	printf("Enter the type('h' for hatchback/'s' for sedan/'b' for bike): \n");
	scanf("%s",&s.type);
	printf("Enter the engine basic details: \n");
	fgets(s.engine,sizeof(s.engine),stdin);
	return s;
}
int delete(char del[100],struct showroom s)
{
	if(strcmp(del,s.name)==0)
	    return 1;
	else
	    return 0;
}
int getNum(char ty, struct showroom s[100], int n)
{
	int i, c=0;
	for(i=0;i<n;i++)
	    if(ty==s[i].type)
	        c++;
	return c;
}
int isEmpty(struct showroom s[100], int l)
{
	int i;
	for(i=0;i<l;i++)
	    if(strcmp(s[i].name,"\0")!=0)
	        return 0;
	return 1;
}
int isFull(struct showroom s[100], int l)
{
	int i;
	for(i=0;i<l;i++)
	    if(strcmp(s[i].name,"\0")==0)
	        return 0;
	return 1;
}
struct showroom UpdateDetails(struct showroom s, struct showroom s1)
{
	if (strcmp(s.name,s1.name)==0)
        return s1;
    else
	    return s;
}
char* getLongestPeriod(struct showroom l[100], int n)
{
	int i, m=0;
	char* car;
	for(i=0;i<n;i++)
	{
		printf("For %s-\n",l[i].name);
		int y1, y2, y, m1, m2, m, d1, d2, d;
		printf("Enter date of purchase(in dd-mm-yyyy form):");
    	scanf("%02d-%02d-%04d",&d1,&m1,&y1);
    	printf("Enter dat of 1st service(in dd-mm-yyyy form): \n");
        scanf("%02d-%02d-%04d",&d2,&m2,&y2);
        y=y1-y2;
        m=m1-m2;
        if(m<0)
        {
            y--;
            m+=12;
        }
        d=d1-d2;
        if(d<0)
        {
            m--;
            d+=30;
        }
        d=y*365+m*30+d;
        if(m<d)
        {
        	m=d;
        	car=l[i].name;
		}
	}
	return car;
}
void unique(struct showroom s[100],int n)
{
	struct showroom l[100];
	int i, k, f=0, m=0;
	for(i=0;i<n;i++)
	{
		for(k=0;k<m;k++)
		    if(strcmp(l[k].name,s[i].name)==0)
		        f=1;
		if(f==0)
		    l[m++]=s[i];
	}
	s=l;
	display(s,n);
}
void lunion(struct showroom s[100], struct showroom s1[100], int n, int l)
{
	int i, j;
	struct showroom list[200];
	for(i=0;i<n;i++)
		list[i]=s[i];
	for(j=0;j<l;j++)
	    list[i++]=s1[j];
	unique(list,(n+l));
}
void intersection(struct showroom s[100], struct showroom s1[100], int n, int l)
{
	int i, k, f=0, m=0, j;
	struct showroom list[200];
	for(i=0;i<n;i++)
		list[i]=s[i];
	for(j=0;j<l;j++)
	    list[i++]=s1[j];
	struct showroom li[100];
	j=0;
	for(i=0;i<n;i++)
	{
		for(k=0;k<m;k++)
		    if(strcmp(li[k].name,list[i].name)==0)
		        f=1;
		if(f==0)
		    li[m++]=list[i];
	}
	struct showroom finallist[100];
	for(i=0;i<m-j;i++)
	{
		if(strcmp(li[i].name,list[i+j].name)!=0)
		    finallist[j++]=list[i--];
	}
	display(finallist,j);
}
void difference(struct showroom s[100], struct showroom s1[100], int n, int l)
{
	struct showroom list[100];
	int i, j, f, k=0;
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=0;j<l;j++)
		{
			if(strcmp(s[i].name,s1[i].name)==0)
			    f=1;
		}
		if(f==0)
		    list[k++]=s[i];
	}
	display(list, k);
}
void symmetricDifference(struct showroom s[100], struct showroom s1[100], int n, int l)
{
	struct showroom list[100];
	int i, j, f, k=0;
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=0;j<l;j++)
		{
			if(strcmp(s[i].name,s1[i].name)==0)
			    f=1;
		}
		if(f==0)
		    list[k++]=s[i];
	}
	for(i=0;i<l;i++)
	{
		f=0;
		for(j=0;j<n;j++)
		{
			if(strcmp(s[i].name,s1[i].name)==0)
			    f=1;
		}
		if(f==0)
		    list[k++]=s1[i];
	}
	display(list,k);
}
void display(struct showroom s[100], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("Name of model: %s\nPrice of car: %d\nType of car is a bike: %c\nEngine: %s\n",s[i].name,s[i].price,s[i].type,s[i].engine);
}
