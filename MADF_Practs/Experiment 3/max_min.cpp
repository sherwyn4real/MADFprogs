#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int *a,count,mid;

void maxmin(int i,int j, int &max, int &min)
{	
	
	count++;	//if
	if(i==j)
	{
		max=min=a[i];
		count+=2;	//assign
	}
	
	else if(i==j-1)
	{
		count++;	//if
		if(a[i]<a[j])
		{
			max=a[j];
			min=a[i];
			count+=2;
		}
		
		else
		{
			max=a[i];
			min=a[j];
			count+=2;
		}
	}

	else
	{
		mid = (i+j)/2;
		count++;	//assign
		
		maxmin(i,mid,max,min);
		int max1,min1;
		maxmin(mid+1,j,max1,min1);
		
		count++;	//if
		if(max<max1)
		{
			count++;
			max=max1;
		}
		
		count++;	//if
		if(min>min1)
		{
			count++;
			min=min1;
		}
	}
	count++;
	return;
}


int main()
{
	int n,max,min;
	cout<<"Enter number of elements\n";
	count++;
	cin>>n;
	count++;
	a = new int[n];
	count++;
	
	cout<<"Enter "<<n<<" element(s) \n";
	count++;
	for(int i=0;i<n;i++)
		{
			count++;	//for
			cin>>a[i];
			count++;
		}

	maxmin(0,n-1,max,min);
	
	cout<<"The largest element:"<<max<<endl;
	cout<<"The smallest element:"<<min<<endl;
	
	cout<<"Count="<<count<<endl;
	return 0;
}

