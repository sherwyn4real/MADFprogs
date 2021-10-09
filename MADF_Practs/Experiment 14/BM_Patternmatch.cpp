#include<iostream>
#include<map>
using namespace std;

typedef map<char,int> letterMap;	//last occurrence map
char p[20];

letterMap lastOcc;

int last(char c)
{
	/*for(int i=pos-1;i>=0;i--)
		if(p[i] == c)
			return i;*/
			
	/*lastOcc::iterator i;
	for(i = lastOcc.begin();i!=lastOcc.end();i++)
		if(*/
			
	
	auto iterator = lastOcc.find(c);
	
	if(iterator != lastOcc.end())
		return iterator->second;
	
	return -1;
}
	

int BM(char *t)
{
	
	int m=strlen(p),n=strlen(t);
	
	int i=m-1,j=m-1;
	
	for(int k=m-1;k>=0;k--)
		lastOcc[p[k]] = -1;
		
	
	for(int k=m-1;k>=0;k--)
		if(lastOcc[p[k]] == -1)
			lastOcc[p[k]] = k;
	
	//displaying map
	
	//letterMap :: iterator itr;
	
	/*for(itr=lastOcc.begin();itr!=lastOcc.end();itr++)
		cout<<itr->first<<"  "<<itr->second<<endl;*/
	
	
	do
	{
		if(p[j] == t[i])
			{
				if(j==0)
					return i;
					
				else
				{
					j-=1;
					i-=1;
				}
			}
			
		else
		{
			i = i + m - min(j, 1+last(t[i]));
			j=m-1;
		}
		
	}while(i<n);
	
	return -1;
}

int main()
{
	char t[30];
	int i;
	cout<<"Enter a string: ";
	cin.getline(t,30);
	cout<<"\nEnter the pattern: ";
	cin.getline(p,20);

	i = BM(t);
	if(i!=-1)
		cout<<"\nThe substring starts from index "<<i<<endl;
	
	else
		cout<<"\nThere is no substring of T matching P\n";
	return 0;
}
