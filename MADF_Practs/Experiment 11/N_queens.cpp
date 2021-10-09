#include<iostream>
using namespace std;
int count=0,*x;		//x is solution vector 

void show_soln(int n)
{
	cout<<"( ";
	for(int i=0;i<n;i++)
		cout<<x[i]<<" ";
		
	cout<<")"<<endl;
}

int abs(int num)
{
	if(num<0)
		count++,num*=-1;
	
	count+=2;	
	return num;
}


bool place(int k, int i)
{
	for(int j=0;j<=k-1;j++)
		{ 
			count+=2;	//for and if
			if(x[j] == i  ||  (abs(x[j]-i) == k-j) )		//if the queen to be placed
				{
					count+=2;
					return false;
				}
		}
		
	count++;													//is on the same column or diagonal
	return true;
}													//of prev queen


void Nqueens(int k, int n)		//k is row number and i is column number;
{
	for(int i=0;i<n;i++)
	{
		count+=2;	//for and if
		if(place(k,i))
		{		
			x[k] = i;
			
			count+=2;	//if and assignment	
			if(k == n-1)
				show_soln(n);
				
			else
				Nqueens(k+1,n);
		}
	}
	count++;	//end of for
	
}

int main()
{
	int n;
	cout<<"Enter number of queens:\n";
	cin>>n;
	x = new int[n];
	
	for(int i=0;i<n;i++)
		x[i]=-1;		//initialised solution vector to -1
		
	int k=0;	
	Nqueens(k,n);
	
	cout<<"\nStepcount="<<count<<endl;
	return 0;
}
	
