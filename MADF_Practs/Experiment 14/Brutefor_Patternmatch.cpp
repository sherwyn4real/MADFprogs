#include<iostream>
using namespace std;


int bruteforce(char *t, char *p)
{
	int j,n=strlen(t),m=strlen(p);
	
	for(int i=0;i<n-m;i++)
		{
			j=0;
			while(j<m && t[i+j] == p[j])
				j+=1;
				
			if(j==m)
				return i;
				
		}
		
		return -1;
	
}

int main()
{
	char t[20],p[20];
	int i;
	cout<<"Enter a string: ";
	cin>>t;
	cout<<"\nEnter the pattern: ";
	cin>>p;
	
	i = bruteforce(t,p);
	if(i!=-1)
		cout<<"\nThe substring starts from index "<<i<<endl;
	
	else
		cout<<"\nThere is no substring of T matching P\n";
	return 0;
}
