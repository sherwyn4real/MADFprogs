#include<iostream>
using namespace std;
int count=0;

struct record
{
	float p;
	float w;
}pairs[100];

void show_tuple(int N)
{
	for(int i=0;i<N;i++)
	cout<<"("<<pairs[i].p<<","<<pairs[i].w<<")";
}

void Dknapsack(int n, float W, float *pt, float *wt)
{
	
	pairs[0].p=pairs[0].w=0.0;		//S0;
	int N=1;	//Number of tuples currently in pairs
	int j=1;	//start index to fill up more tuples are S0;
	
	count+=4;	//assignments above
	
	cout<<"\n\nThe tuples are:\n";
	
	for(int i=0;i<n;i++)
	{
		int c=0;	//start index of pairs[]
		count+=2;	//for loop and c
		
		while(c<N)
			{
						pairs[j].p = pairs[c].p + pt[i];
						pairs[j].w = pairs[c].w + wt[i];
						j++; c++;	
						count+=5;	//while loop and assingments	
		
			}
			count++;	//end while condition
		show_tuple(N);
		N=j;count++;
		cout<<endl;
	}
	
	count++;	//end of for loop
	show_tuple(N);
	cout<<endl;
	
	int num = N,soln[n],m=n;	//num is number of tuples. soln[] is the solution vector and n is no of objs
	float large;
	
	for(int i=0;i<num;i++)
	{
		count+=2;	//if and for
		
			if(pairs[i].p>large && pairs[i].w<=W)
				large = pairs[i].p,count++;
	}
	count++;	//end of for
	
	
	while(num>0)
	{
		
		num/=2;
		count+=2;	//while and num
		
		int i;
		for(i=0;i<num && pairs[i].p!=large;i++);
	
		count++;	//if
		if(i==num)
			{
				soln[--m]=1;
				large = large - pt[m];
				count+=2;
			}
			
		else
				soln[--m]=0;	
			
	}
	
	cout<<"\nThe solution vector: ( ";
	
	for(int i=0;i<n;i++)
		cout<<soln[i]<<" ";
	cout<<")";
			 
	float max=0;
	for(int i=0;i<n;i++)
		if(soln[i])
			max+=pt[i];
			
	cout<<"\nThe Maximum profit is:"<<max<<endl<<endl;
			 
}		
		


int main()
{
	int n;
	cout<<"Enter number of objects:";
	cin>>n;
	float W, pt[n], wt[n];
	
	cout<<"\nEnter the "<<n<<" profits: ";
	for(int i=0;i<n;i++)
		cin>>pt[i];
		
	cout<<"\nEnter the "<<n<<" weights: ";
	for(int i=0;i<n;i++)
		cin>>wt[i];
	
	cout<<"\nEnter the capacity of the knapsack:";
	cin>>W;
	
	
	Dknapsack(n,W,pt,wt);
	cout<<"\nStepCount="<<count<<endl;
	return 0;
}

	
	

//Code to exclude the tuples having higher weight than the capacity
/*for(int i=0;i<n;i++)
	{
		int k=0,c=0;	//start index of pairs[]
		
		while(k<N)
			{
				if(pairs[c].w + wt[i] <= W)
					{
						pairs[j].p = pairs[c].p + pt[i];
						pairs[j].w = pairs[c].w + wt[i];
						j++; c++;		//increment j(last index that was filled) and c(index range from 0 to N)
					}
				k++;
			}
		N=j;
	}*/
