#include<iostream>
using namespace std;
int count=0;

void swap(int &a, int &b)
{
	int t=a;
		a=b;
		b=t;
		count+=3;
} 

int partition(int *a, int low, int high)
{
	int pivot = a[high];
	int i = low-1;
	count+=2;
	
	for(int j=low;j<=high-1;j++)
		{
			count+=2;	//for and if
			if(a[j]<pivot)
			{
				i++;
				count++;
				swap(a[j],a[i]);
			}
		}
		count++;
		
	swap(a[i+1],a[high]);
	count++;
	return (i+1);
}
				

void quicksort(int *a, int low, int high)
{
	count++; //if
	if(low<high)
	{
		int pi = partition(a,low,high);
		count++;	//assign
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}

int main()
{
	int n,*a;
	cout<<"Enter number of elements\n";
	count++;
	cin>>n;
	count++;
	a = new int[n];
	count++;
	
	cout<<"Enter "<<n<<" elements to be sorted\n";
	count++;
	for(int i=0;i<n;i++)
		{
			count++;//for
			cin>>a[i];
			count++;
		}
	count++;//for
	
	
	quicksort(a,0,n-1);
	
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	cout<<"Count="<<count<<endl;
	//count++;//return
	return 0;
}

