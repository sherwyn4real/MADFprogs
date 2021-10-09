#include<iostream>
using namespace std;
int n,m,*w,*x;	//soln vector

void show_set(int k)
{
	cout<<"( ";
	for(int i=0;i<=k;i++)
		cout<<x[i]<<" ";
	cout<<")"<<endl;
	
}

void sum_of_sub(int s, int k, int r)
{
	x[k] = 1;
	
	
	
	if(s+w[k] == m)
		show_set(k);
		
	else if(s + w[k] + w[k+1] <=m)		//current sum is less than or equal to m
			
			sum_of_sub(s+w[k],k+1,r-w[k]);
		
	
		
	if( (s + r - w[k] >= m) && (s + w[k+1] <=m))		//bounding function says that
		{												//w obtained so far + remaining w
			x[k] = 0;									//must be >=m
			sum_of_sub(s,k+1,r-w[k]);
		}												//and the w obtained so far + next
														//w must be <=m
}
			 

int main()
{
	int r=0;		//temp sum
	cout<<"Enter number of elements: ";
	cin>>n;
	
	cout<<"\nEnter "<<n<<" elements: ";
	
	w=new int[n];
	
	for(int i=0;i<n;i++)
		cin>>w[i],r+=w[i];
		
	
	x = new int[n];
	
	
	cout<<"\nEnter the sum: ";
	cin>>m;
	
	
	for(int i=0;i<n;i++)
		x[i]=0;
		
	int s=0,k=0;	
	sum_of_sub(s,k,r);
	
	return 0;
}
