#include<stdio.h>
void main()
{
	int a[]={0,10,12,13,14,15,60,74,83,90}; // Exampler array
	int f=0,l=9,m=(f+l)/2;int c=0;int k=0;int z=83; // f,l,m indicate first last and mid
	for(m;f<=l;m=(f+l)/2) // do this utill all  the array elements traversed. 
	{
		c++;
		if(z==a[m])
		{
			 k=1; // if present 
			break;
		}	
		else if(z>a[m])
		{
			f=m+1; // greater than value at mid
		}
		else
			l=m-1;// less than value at mid
		
		
	}
	if(k==1)
		printf("Successful. present at %d",m);
	else
	 	printf("Unsuccessuful");
	printf("\n%d",c);
}
