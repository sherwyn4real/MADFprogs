#include<iostream>
#include<math.h>

int count=0;
using namespace std;

float compute_UN( float lg, float n)
{
	count++;	//for if else
	if(n>lg)
		{
			n-=lg;	//for case O(n^r) r>0
			count++;
		}
		
	else if((n==0 && n!=lg)  || (n<lg && n!=0))
		{
			n=-1;	//for case O(1)			here h(n) = 1/n^r hence r<0 or h(n)=n^x/n^y where y>x
			count+=2;
		}
	
	else if(n==lg)
		{
			n=0;		//case when h(n)=1 hence r=0; ie i>=0 so logn^(i+1)/i+1
			count+=2;
		}
	count++;	
	return n;
	
}
	

float log_a_base_b(float a, float b)
{
	count++;
	return log(a)/log(b);
}


void compute_RR( float n, float a, float b)
{
	
	float lg;
	
	
	lg = log_a_base_b(a,b);		//this will be power of n while calculating T(n)
	
	n= compute_UN(lg,n);		//computes U(n) based on h(n)
	count+=2;
	
	
	count++;	//if else
	if(lg > n && n<0)
		cout<<"Time Complexity of the recurrence relation is: O(n^"<<lg<<")"<<endl;
		
	else if ((lg > n && n>0) || n>lg )
		{
			cout<<"Time Complexity of the recurrence relation is: O(n^"<<lg+n<<")"<<endl;
			count++;
		}
		
	else if(lg==0 && n==0)
		{
			cout<<"Time Complexity of the recurrence relation is: O(logn)"<<endl;
			count++;
		}
		
	else if (lg>0 && n==0)
		{
			cout<<"Time Complexity of the recurrence relation is: O((n^"<<lg<<")*logn)"<<endl;
			count++;
		}
		
	
}

int main()
{
	cout<<"General form of Recurrence Relation to be solved using Master Theorem is: T(n) = aT(n/b) + f(n)"<<endl;
	cout<<"a>=1 and b>1 are necessary conditions"<<endl;
	
	float n;	//variable n is power of n
	float a,b;		

	
	cout<<"\nEnter values of a,b: ";
	cin>>a>>b;
	
	count++;
	if(a<1 || b<=1 )
		cout<<"This Recurrence Relation cant be solved using Master Theorem"<<endl;
		
	else
		{
			cout<<"Enter power of n in f(n): ";
			cin>>n;
			compute_RR(n,a,b);
		}
		
	cout<<endl<<"STEPCOUNT = "<<count<<endl;	
	return 0;
}
