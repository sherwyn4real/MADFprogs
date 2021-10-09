#include<iostream>
using namespace std;
int count=0;


void bellford(int graph[][3], int v, int e)
{
	int dist[v];	//array of distances from source to all v
	
	dist[0]=0;	//dist from source to source itself is zero
	count++;
	
	for(int i=1;i<v;i++)
		dist[i]=99,		//99 represents infinity
		count+=2;	//assignment and for
		
	count++;	//end of for loop
		
	for(int i=1;i<v;i++)
		{
			count++;	//for
			for(int j=0;j<e;j++)
		{
				count+=2;	//for and if
				if(dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
					{
						dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
						count++;
					}
						
		}
		count++;	//inner for loop		
	}
	count++;	//outer for loop

	for(int i=0;i<e;i++)
		{
			count+=2;	//for and if
			if(dist[graph[i][0]] + graph[i][2] < dist[graph[i][1]])
				cout<<"Negative weight cycle detected. Cannot compute shortest path\n",
				count++,	//for exit;
				cout<<"stepcount="<<count<<endl,
				exit(1);
		}
	count++;	//for loop end
			
	cout<<"vertex distance from source:\n";
	for(int i=0;i<v;i++)
		cout<<i<<"\t"<<dist[i]<<endl;
}


		
int main()
{
	int v,e;
	cout<<"Enter the number of vertices:";
	cin>>v;
	
	cout<<"\nEnter the number of edges:";
	cin>>e;
	
	cout<<"Enter 8 directed edges in the order : Source,destination,Weight\n";
	
	int total_edges = v*(v-1)/2;
	count++;
	
	int graph[total_edges][3];
	for(int i=0;i<e;i++)
			{
				cout<<"Enter edge:"<<i+1<<endl;
				cin>>graph[i][0];
				cin>>graph[i][1];
				cin>>graph[i][2];
			}
	
	
	bellford(graph,v,e);
	cout<<"Stepcount="<<count<<endl;
   return 0;
	
}

/*int graph[][3] =  { { 0, 1, -1}, 
						{ 0, 2, 4 },
                        { 1, 2, 3 }, 
						{ 1, 3, 2 },
						{ 1, 4, 2 }, 
					    { 3, 2, 5 },
				 	    { 3, 1, 1 }, 
					    { 4, 3, -3 } };
	*/
