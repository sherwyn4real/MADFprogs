/*#include <bits/stdc++.h>*/
#include<iostream>
#include<iomanip>
using namespace std;
static int ctr;
#define N INT_MAX;
#define v 10
static float c[v][v], w[v][v];
static int r[v][v];
int n;
void tree(int r[v][v],int n,int i, int j)
{
	ctr++;
	int k= r[i][j];		ctr++;
	ctr++;
	if(i==j)
	{
		ctr++;
		return;
	}
	cout<<"\n\nLeft Child of "<<k<<" : "<<r[i][k-1];	ctr++;
	cout<<"\tRight Child of "<<k<<" : "<<r[k][j];	ctr++;
	tree(r,n,i,k-1);	
	tree(r,n,k,j);
}

int Find(float c[v][v], int r[v][v], int i, int j)
{
	ctr++;
	float min = N; int index;
//	cout<<"\n i = "<<i<<" : j = "<<j;
	ctr++;
	for(int m= i+1; m<=j; m++)
	{
		ctr++;
		//cout<<"\nc["<<i<<"]["<<m-1<<"] + c["<<m<<"]["<<j<<"] = "<<c[i][m-1] + c[m][j];
		ctr++;
		if((c[i][m-1] + c[m][j])<min)
		{
			ctr++;
			min = c[i][m-1] + c[m][j];	ctr++;
			index = m;	ctr++;
		}
	}
//	cout<<"\nmin="<<min<<" for K= "<<index;
	ctr++;
	return index;
}

void OBST(float p[v], float q[v], int n)
{
	ctr++;
	int j, k;
	//initialise
	ctr++;
	for(int i=0; i<n; i++)
	{
		ctr++;
		w[i][i] = q[i];	ctr++;
		r[i][i] = 0; c[i][i]=0.0;	ctr++;
		//for optimal trees with 1 node
		w[i][i+1] = q[i+1] + p[i+1] + q[i];	ctr++;
		c[i][i+1] = q[i+1] + p[i+1] + q[i];	ctr++;
		r[i][i+1] = i+1;	ctr++;
	}
	w[n][n]= q[n];	ctr++;
	c[n][n]= 0.0;	ctr++;
	r[n][n]= 0;		ctr++;
	//for optimal tree with 'm' nodes
	ctr++;
	for(int m=2; m<=n; m++)
	{
		ctr++;
		ctr++;
		for(int i=0; i<=n-m; i++)
		{
			ctr++;
			j=i+m;	ctr++;
			w[i][j]= w[i][j-1] + p[j] + q[j];	ctr++;
		//	cout<<"\nw["<<i<<"]["<<j<<"] : "<<w[i][j];
			k = Find(c, r, i, j);	ctr++;
			c[i][j] = w[i][j] + c[i][k-1] + c[k][j];	ctr++;
			r[i][j]=k;	ctr++;
		}
	}
	//printing table
	cout<<"\n";ctr++;
    cout<<" |";
    for (int i = 0; i <= n; i++){
    	cout<<setw(13)<<i<<" |";ctr++;
    	cout<<" ";
    	
    }
    	ctr++;
    	cout<<"\n"<<"---------------------------------------------------------------------------------"<<"\n";
    	for(int m=0;m<=n;m++){
    		ctr++;
    		cout<<m<<"|";ctr++;
    		for(int i=0,j=m;i<=n && j<=n;i++,j++){
    			ctr++;
    			cout<<"w(" << i << "," << j << ")= " << w[i][j]<<"\t"<<"|";ctr++;
    		}
    		ctr++;
    		cout<<"\n";ctr++;
    		cout<<" |";ctr++;
    		for(int i=0,j=m;i<=n && j<=n;i++,j++){
    			ctr++;
    			cout<<"c(" << i << "," << j << ")= " << c[i][j]<<"\t"<<"|";ctr++;
    		}
    		ctr++;
    		cout<<"\n";ctr++;
    		cout<<" |";ctr++;
    		for(int i=0,j=m;i<=n && j<=n;i++,j++){
    			ctr++;
    			cout<<"r(" << i << "," << j << ")= " << r[i][j]<<"\t"<<"|";ctr++;
    		}
    		ctr++;
    		cout<<"\n"<<"---------------------------------------------------------------------------------\n";ctr++;
    	}
    ctr++;
    cout<<"\nMinimum Cost: "<<c[0][n];ctr++;
    cout<<"\nRoot of OBST: "<<r[0][n];ctr++;
    tree(r,n,0,n);ctr++;
   
    //cout<<"\nNOTE: 0(which is empty) == NULL(which is also empty)\nP.S. we tried a lot but we couldn't replace 0 by NULL";
}

int main()
{
	ctr++;
	cout << "Enter number of identifiers: ";ctr++;
    cin >> n;ctr++;
    float p[n + 1], q[n + 1];
    p[0]=-1;ctr++;
    cout << "\nEnter probabilities of successful search(p): ";ctr++;
    for (int i = 1; i <= n; i++)
    {
    	ctr++;
        cin >> p[i];ctr++;
    }
    ctr++;
    cout << "\nEnter probabilities of unsuccessfull search(q): ";ctr++;
    for (int i = 0; i <= n; i++)
    {
    	ctr++;
        cin >> q[i];ctr++;
    }
    OBST(p, q, n);ctr++;
    cout<<"\n\nStepcount: "<<ctr<<endl;
}






/*#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	
	char ch;
	int T;
	cin>>T;
	
	while(T--)
	{
	    long int N,M,Q,temp;
	    cin>>N>>M>>Q;
	    
	    int sum = 0;
	    long int a[N+1];
	    for(int i=1;i<=N;i++)
	        a[i]=0;
	   
	   
	    while(Q>0 && sum<=M)
	    {
			cout<<"Q="<<Q<<endl;
	        cin>>ch>>temp;
	        
	        if(ch == '-')
	        {
	            if(a[temp] == 0)
	            {
	                cout<<"Inconsistent"<<endl;
	                break;
	            }
	            
	            else
	                sum--;
	        }
	        
	        else
	        {
	            a[temp]=1;
	            sum++;
	        }
	        Q--;
	        
	        
	        
	    }
	    
	    if(Q!=0)
	        {
	            while(Q>=1)
	                {
	                    cout<<"Q="<<Q<<endl;
	                    cin>>ch>>temp;
	                    Q--;
	                }
	            cout<<"Inconsistent"<<endl;
	        }
	        
	   else
	       cout<<"Consistent"<<endl;
	       
	}
	return 0;
}*/
