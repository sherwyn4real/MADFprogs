#include<iostream>
using namespace std;
int count=0;
void sort(float *a,float *w,float *p,int n)
{
	for(int i=1;i<n;i++)
		{
			count++;
			for(int j=0;j<n-i;j++)
				{
					count+=2;
					if(a[j]<a[j+1])
					{
						float t = a[j];
						a[j] = a[j+1];
						a[j+1] = t;
						
						 t = w[j];
						w[j] = w[j+1];
						w[j+1] = t;
						
						t=p[j];
						p[j]=p[j+1];
						p[j+1]=t;
						
						count+=9;
						
					}
				}
			count++;	//inner for
			
}
count++;	//outer for
}

void greedyknapsack(int m,int n)
{
	float *p = new float[n];
	float *w = new float[n];
	int u=m;
	count+=3;	//assign
	
	cout<<"Enter the profits of the "<<n<<" objects\n";
	for(int i=0;i<n;i++)
		cin>>p[i];
		
	cout<<"Enter the weights of the "<<n<<" objects\n";
	for(int i=0;i<n;i++)
		{	
			count+=2;
			cin>>w[i];
		}
		
	count++;	//for
	
	float *pw = new float[n],*x = new float[n];
	count+=2;
	
	for(int i=0;i<n;i++)
		{
			count+=2;
			pw[i] = p[i]/w[i];
		}
	count++;
	
	sort(pw,w,p,n);
		
	cout<<"The new order of objects:"<<endl;
			
	for(int i=0;i<n;i++)
			{
				count+=2;
				cout<<"P"<<i+1<<"="<<p[i]<<" 	"<<"W"<<i+1<<"="<<w[i]<<endl;
			}
	count++;	//for
	
	for(int i=0;i<n;i++)
		{
			count+=2;
			x[i] = 0.0;
		}
	count++;	//for
	
	int i=0; count++;
	for(i=0;i<n;i++)
	{
		count+=2;
		if(w[i]>u)
			{
				count++;
				break;
			}
			
		x[i] = 1.0;
		u-=w[i];
		count+=2;
	}
	count++;
	
	count++;	//if
	if(i<=n)
		{
			count++;
			x[i] = u/w[i];
		}

	cout<<"\nThe solution vector is\n";
	for(int i=0;i<n;i++)
		cout<<x[i]<<" ";
		
	cout<<"\nHence, the maximum possible profit is:";
	float sum=0.0;
	for(int i=0;i<n;i++)
			sum+=x[i]*p[i];
	cout<<sum<<endl;
}

int main()
{
	int n,m;
	cout<<"Enter number of objects and the weight of the bag\n";
	cin>>n>>m;
	
	greedyknapsack(m,n);
	
	cout<<"Count="<<count<<endl;
	return 0;
}
