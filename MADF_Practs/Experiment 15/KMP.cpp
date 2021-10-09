#include<iostream>
using namespace std;
char p[20];

int * failure(char *p,int m)
{
	int *f = new int[m];
	
	int j=0,i=1;
	f[0] = 0;
	while(i<m)
	{
		if(p[j] == p[i])
			{
				f[i] = j+1;
				j = j+1;
				i= i+1;
			}
			
		else if(j>0)
			j = f[j-1];
			
		else
		{
			i = i+1;
			f[i] = 0;
		}
	}
	
	return f;			
}


int KMP_match(char *t)
{
	int n = strlen(t);
	int m = strlen(p);
	
	int *f = failure(p,m);
	
	int i=0,j=0;
	
	while(i<n)
	{
		if(p[j] == t[i])
		{
			if(j == m-1)
				return i - m+1;
				
			else
			{
				i = i+1;
				j=j+1;
			}
		}
		
		else if(j>0)
			j = f[j-1];
			
		else
			i=i+1;
			
	}
	
	return -1;
	
}			
			


int main()
{
	char t[20];
	int i;
	cout<<"Enter a string: ";
	cin.getline(t,20);
	cout<<"\nEnter the pattern: ";
	cin.getline(p,20);

	i = KMP_match(t);
	if(i!=-1)
		cout<<"\nThe substring starts from index "<<i<<endl;
	
	else
		cout<<"\nThere is no substring of T matching P\n";
	return 0;

}
