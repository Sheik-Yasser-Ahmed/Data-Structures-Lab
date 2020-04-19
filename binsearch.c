#include<stdio.h>
 int bin_search(int Ar[10],int low,int high,int k){
 	int mid;
 	if(low<=high)
 	{
 		mid=(low+high)/2;
 		if(Ar[mid]<k)
 		 return bin_search(Ar,mid+1,high,k);
 		else if(Ar[mid]==k)
		  return mid;
		 else   
		 return bin_search(Ar, low, mid-1,k);
	 }
	 else 
	 return -1;
 }
 void main()
 {
 	int arr[10],n,key,i,r;
 	printf("\nEnter the size : ");
 	scanf("%d",&n);
 	printf("\nEnter the elements of array : ");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	printf("\nEnter key : ");
	scanf("%d",&key);
	r=bin_search(arr,0,n,key);
	if(r==-1)
	{
		printf("\nElement not found ");
	}
	else 
	 printf("\nElement found at psoition : %d",r+1);
 }
