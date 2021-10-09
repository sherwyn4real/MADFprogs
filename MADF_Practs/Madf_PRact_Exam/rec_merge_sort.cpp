#include<iostream>
using namespace std;

void mergesort(int,int);
void merge(int,int,int);
int count=0;
int *a,*b;
int main()
{
	int n;
	cout<<"Enter number of elements\n";
	//count++;
	cin>>n;
	//count++;
	a = new int[n];
	b = new int[n];
	//count++;
	
	cout<<"Enter "<<n<<" elements to be sorted\n";
	//count++;
	for(int i=0;i<n;i++)
		{
			//count++;//for
			cin>>a[i];
			//count++;
		}
	//count++;//for
	
	
	mergesort(0,n-1);
	//count++;
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	cout<<"Count="<<count<<endl;
	//count++;//return
	return 0;
}

void mergesort(int low, int high)
{
	count++;
	if(low<high)
	{
	
	int mid = (low+high)/2;
	count++;
	
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,mid,high);
	}

}

void merge(int low, int mid, int high)
{
	int i=low,j=mid+1,k=low;
	
	
	while(i<=mid && j<=high)
	{	
		count++;  //while
		count++; //if
		if(a[i]<a[j])
			{	
				count+=3;
				b[k++] = a[i++];
			}
		
		else
			{
				b[k++] = a[j++];
				count+=3;
			}
	}
	count++; //while
	
	
	while(i<=mid)
		{	
			count++;	//while statement
			count++;
			b[k++] = a[i++];
		}
	count++;	//Last while 
		
	
	while(j<=high)
	{
		count++;	//while statement
		count++; //for
		b[k++] = a[j++];
	}
	count++;	//Last while 
		
	for(k=low;k<=high;k++)
	{
		count++; //for
		a[k]=b[k];
		count++;
	}
}
	
	
	
		
