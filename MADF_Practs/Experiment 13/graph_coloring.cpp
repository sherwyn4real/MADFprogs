#include<iostream>
using namespace std;
int n,m,graph[10][10],*x,count=0;

void showset()
{
	cout<<"( ";
	for(int i=0;i<n;i++)
		cout<<x[i]<<" ";
	cout<<")"<<endl;
	
	count++;
}

void nextValue(int k)
{
	int j;
	do
	{
		x[k] = (x[k]+1)%(m+1);
		if(x[k] == 0)
			return;
		
		for(j=0;j<n;j++)
			if((graph[k][j] != 0) && (x[k] == x[j]))	
						break;
					
			
		if(j==n)
			return;
			
	}while(true);
}
				

void mColoring(int k)
{
	do
	{
		nextValue(k);
		if(x[k] == 0)
			return;
			
		if(k == n-1)
			showset();
			
		else
			mColoring(k+1);
			
			
	}while(true);
	
}

int main()
{
	cout<<"Enter number of vertices: ";
	cin>>n;
	
	x = new int[n];
	for(int i=0;i<n;i++)
		x[i]=0;
		
	
	char ans;
	
	cout<<"Hit 'y' if there is an edge between the corresponding vertices, else hit 'n'\n\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]==1 || i>j)
				continue;
				
			graph[i][j]=0;
				
			if(i!=j)
				{
				cout<<"Edge between "<<i<<" and "<<j<<" ? : ";
				cin>>ans;
				if(ans == 'y')
					graph[i][j]=graph[j][i]=1;
				}
		}
		
	int k=0;
	
	cout<<"\nEnter number of colors: ";
	cin>>m;
	
	
	mColoring(k);
	
	if(count == 0)
		cout<<"No solutions."<<endl;
	return 0;
}


/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<graph[i][j]<<" ";
			cout<<endl;
		}*/
