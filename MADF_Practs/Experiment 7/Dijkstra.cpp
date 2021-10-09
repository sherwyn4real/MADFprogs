#include<iostream>
using namespace std;
const int v=10;
int n, count=0;

void show_paths(int *dist)
{
	cout<<"\nVertex      Distance from source:\n";
		
	for(int i=0;i<n;i++)
		cout<<"  "<<i<<"                 "<<dist[i]<<endl;
		
}


int findmin(bool *visited, int *dist)
{
	int min=99, u;
	count++;
	
	for(int i=0;i<n;i++)
		{
			count+=2;
			if(visited[i]==false && min>dist[i])
				min=dist[i],u=i,count+=2;
		}
		
	count++;		
	return u;
}
	

void shortestpaths(int graph[v][v], int s)
{
	int dist[n];	//collection of shortest paths from source
	bool visited[n];	//Keeps track of visited vertices
	
	
	for(int i=0;i<n;i++)
		visited[i]=false,
		dist[i]=99, count+=3;
		
	count++;	//end of for
		
	dist[s]=0;		//distance from source to itself is zero
	count++;
	
	for(int i=0;i<n;i++)
	{
		int u = findmin(visited,dist);
		visited[u]=true;
		count+=3;	//outer for and assignments
		
		for(int j=0;j<n;j++)
			{
				count+=2;		//for loop and if statement
				if(graph[u][j]!=0 && j!=s)
					if(dist[j]> dist[u] + graph[u][j])
						dist[j] = dist[u] + graph[u][j],count+=2;
			}
	}
	
	show_paths(dist);
	
}
	
	
int main()
{
	
	
	cout<<"Enter number of vertices\n";
	cin>>n;
	
	int graph[v][v];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cout<<"\nEnter edge cost between "<<i<<" and "<<j<<":";
			cin>>graph[i][j];
		}
	
	/*int graph[v][v] = { { 0, 1, 8, 0, 0 }, 
						{ 0, 0, 3, 10,7 }, 
						{ 0, 0, 0, 2, 2 }, 
						{ 0, 0, 0, 0, 12}, 
						{ 0, 0, 0, 0, 0 } };*/
						
	int source;
	cout<<"Enter the source vertex\n";
	cin>>source;
	
	shortestpaths(graph,source);
	cout<<"\nStepCount="<<count<<endl;	
	return 0;
}		
	
