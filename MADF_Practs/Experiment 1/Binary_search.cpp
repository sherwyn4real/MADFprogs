#include<iostream>
using namespace std;

int binarysearch(int *,int,int);
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
			count++;	//for
			cin>>a[i];
			count++;
		}
	count++;//for
	
	cout<<"Enter element to be searched\n";
	count++;
	
	cin>>x;
	count++;
	
	p=binarysearch(a,n,x);
	count++;	//for assignment
	
	count++; //if
	if(p==-1)
		cout<<"Element does not exist\n";
	
	else
		cout<<"Element is present at position "<<p<<endl;
	
	cout<<"Count="<<count<<endl;
	return 0;
}
	
int binarysearch(int *a,int n,int x)
{
	int low=0,high=n-1;
	count+=2;	//2 assignments
	
	while(low<=high)
	{
		count++; //while
		
		int mid = (low+high)/2; 
		count++; //mid
		
		count++; //if
		if(x==a[mid])
		{	count++;
			return mid+1;
		}
		
		else if(x<a[mid])
		{
			
			high=mid-1;
			count++;	//assign
		}
		
		else
		{
			count++;	//else if
			low=mid+1;
			count++;	//for assign
		}
	}
	count++; //while
	
	count++; //return
	return -1;
}
			
