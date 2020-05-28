#include<stdio.h> 
void dijkstra(int G[5][5],int n,int sa);//where "sa" is selected area
 
int main()
{
	int i,j,n,u;
	int G[5][5]={

		{0,2,5,8,6},
		{2,0,8,10,4},
		{5,8,0,8,6},
		{8,10,8,0,11},
		{6,4,6,11,0}
	};
	
	printf("\nChoose your Area:\n");
	printf("1. Jayanagar\n2. Basavanagudi\n3. JP Nagar\n4. Bommanahalli\n5. Banashankari");
	scanf("%d",&u-1);
	dijkstra(G,n,u);
	
	return 0;
}
 
void dijkstra(int G[5][5],int n,int sa)
{
 
	int cost[5][5],distance[5],pred[5];
	int visited[5],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=0;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[sa][i];
		pred[i]=sa;
		visited[i]=0;
	}
	
	distance[sa]=0;
	visited[sa]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=0;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=sa)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=sa);
	}
}