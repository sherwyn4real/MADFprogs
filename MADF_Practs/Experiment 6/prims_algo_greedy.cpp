#include<iostream>
using namespace std;
const int v=10;	//size of the matrix
int count=0,n;	//n is number of vertices


void showtree(int *parent, int graph[v][v])
{
	cout<<"The minimum cost spanning tree is:\n";
	
	cout<<"Edge	Weight\n";
	for(int i=1;i<n;i++)
		{
			cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<"\n";
			count++;	//for
		}
	count++;	//for
}

int minkey(int *key,bool *visited)
{
	int min=99,min_index;	//99 indicates infinite value
	count++;	//for assign
	
	for(int i=0;i<n;i++)
		{
			count+=2;	//for and if
			if(key[i]<min && visited[i]==false)
			{
				min=key[i];
				min_index=i;
				count+=2;
			}
	}
	count++;	//for
	
	count++;	//return
	return min_index;
}

void mintree(int graph[v][v])
{
	int parent[n],key[n];	//parent indicates the spanning tree; key indicates the weights;
							
	bool visited[n];	//visited indicates whether the vertice has been visited or not
	
	for(int i=0;i<n;i++)
		{
			key[i]=99,visited[i]=false;
			count+=3;
		}
	count++;
	
	key[0]=0;		//first vertex is chosen first
	parent[0]=-1;	//root of mst
	count+=2;
	

	
	for(int i=0;i<n-1;i++)
	{
		int u = minkey(key,visited);
		
		visited[u] = true;
		count+=3;	//outer for and assignments
		
		for(int j=0;j<n;j++)
			{
				count+=2;	//inner for and if
				if(graph[u][j] && visited[j]==false && graph[u][j]<key[j])
				{
					key[j]=graph[u][j],
					parent[j]=u;
					count+=2;
				}
			}
		count++;	//inner for
	}
	count++;	//outer for
	showtree(parent,graph);
}
		
	

int main()
{
	
	int graph[v][v];
	cout<<"Enter number of vertices:";
	cin>>n;
	
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cout<<"\nEnter edge cost between "<<i<<" and "<<j<<":";
			cin>>graph[i][j];
		}
	
	
			
	mintree(graph);
	
	cout<<"\nCount="<<count<<endl;
	return 0;
}


/*int graph[v][v] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; */
						
						
/*cout<<"Consider the graph:\n";
	cout<<"|0 2 0 6 0 |\n";
	cout<<"|2 0 3 8 5 |\n";
	cout<<"|0 3 0 0 7 |\n";
	cout<<"|6 8 0 0 9 |\n";
	cout<<"|0 5 7 9 0 |\n\n";
	*/
