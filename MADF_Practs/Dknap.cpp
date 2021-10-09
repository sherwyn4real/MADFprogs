#include<iostream>
using namespace std;
const int MAX=50;
struct PW
{
	float p,w;	
};

int Largest(struct PW pair[MAX],int w[MAX],int t,int h,int i,int m)
{
	int low=t, high=h;
	int mid, res;
	while(low<=high)
	{
		mid=(low+high)/2;
		if((pair[mid].w+w[i])<=m)
		{
			res=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return res;
}

void TraceBack(int p[MAX],int w[MAX], PW pair[MAX],int x[MAX],int b[MAX],int m,int n)
{
	int last=b[n+1]-1;
	float pp=pair[last].p;
	float ww=pair[last].w;
	for(int i=n-1;i>=0;i--)
	{
		bool s=false;
		for(int j=b[i];j<=b[i+1]-1;j++)
		{
			if((pair[j].p==pp) && (pair[j].w==ww))
			{
				s=true;
				break;
			}
		}
		if(s==false)
		{
			x[i+1]=1;
			pp=pp-p[i+1];
			ww=ww-w[i+1];
		}
		else
		{
			x[i+1]=0;
		}
	}
	cout<<endl<<"Solution vector:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<"x["<<i<<"]="<<x[i]<<"\t";
	}
}

void Dknap(int p[MAX],int w[MAX],int x[MAX],int n,int m)
{
	struct PW pair[MAX];
	int b[n+1];
	b[0]=1; 
	pair[1].p=0.0;
	pair[1].w=0.0;
	int t,h,k,next;
	t=1; h=1;
	b[1]=2; 
	next=2;
	int pp,ww;
	for(int i=1;i<=n;i++)
	{
		k=t;
		int u=Largest(pair,w,t,h,i,m);
		for(int j=t;j<=u;j++)
		{
			pp=pair[j].p+p[i];
			ww=pair[j].w+w[i];	//(pp,ww) is the next element in S^i-1
			while((k<=h) && (pair[k].w<=ww))
			{
				pair[next].p=pair[k].p; 
				pair[next].w=pair[k].w;
				next=next+1; k=k+1;
			}
			if((k<=h) && (pair[k].w==ww))
			{
				if(pp<pair[k].p)
				{
					pp=pair[k].p;	
				}	
				k=k+1;
			}
			if(pp>pair[next-1].p)
			{
				pair[next].p=pp;
				pair[next].w=ww;
				next=next+1;	
			}
			while((k<=h) && (pair[k].p<=pair[next-1].p))
			{
				k=k+1;
			} 
		}
		while(k<=h)
		{
			pair[next].p=pair[k].p;
			pair[next].w=pair[k].w;
			next=next+1; k=k+1;
		}
		//Intialize for S^i+1
		t=h+1;
		h=next-1;
		b[i+1]=next;
	}
	cout<<"\nSubsets are:\n";
	for(int i=0;i<=n;i++)
	{
		for(int j=b[i];j<b[i+1];j++)
		{
			cout<<"("<<pair[j].p<<","<<pair[j].w<<") ";
		}
		cout<<endl;
	}
	TraceBack(p,w,pair,x,b,m,n);
}

int main()
{
	int n,m;
	cout<<"Enter number of items: "; cin>>n;
	cout<<"\nEnter weight of knapsack: "; cin>>m;
	int p[n+1],w[n+1];
	cout<<"\nEnter profit and weight of "<<n<<" items:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>w[i];
	}
	int x[n+1];
	Dknap(p,w,x,n,m);
	return 0;
}
