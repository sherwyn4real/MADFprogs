#include<iostream>
using namespace std;

int binarysearch(int *,int,int,int);
int count=0;
int main()
{
	int n,x,*a,p;
	cout<<"Enter number of elements\n";
	count++;
	cin>>n;
	count++;
	a = new int[n];
	count++;
	
	cout<<"Enter "<<n<<" elements in ascending order\n";
	count++;
	for(int i=0;i<n;i++)
		{
			count++;//for
			cin>>a[i];
			count++;
		}
	count++;//for
	
	cout<<"Enter element to be searched\n";
	count++;
	
	cin>>x;
	count++;
	
	p=binarysearch(a,0,n-1,x);	
	count++;	//for assignment 
	
	count++; //if
	if(p==-1)
		cout<<"Element does not exist\n";
	
	else
		cout<<"Element is present at position "<<p<<endl;
	
	cout<<"Count="<<count<<endl;
	
	return 0;
}
	
int binarysearch(int *a,int low, int high,int x)
{
	count++; //if
	if(low>high)
		{	
			count++;
			return -1;
		}
		
	int mid = (low+high)/2;
	count++;
	
	count++;//if
	if(x==a[mid])
		{	count++;
			return mid+1;
		}
	
	else if(x<a[mid])
		{
			count++;//return
			return binarysearch(a,low,mid-1,x);
		}
	
	else
		{	
			count++; 	//for else if condition
			count++;//return
			return binarysearch(a,mid+1,high,x);
		}
	
}
			
