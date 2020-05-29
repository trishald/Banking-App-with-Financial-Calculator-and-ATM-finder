#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijikstra(int G[MAX][MAX], int n, int startnode);
 
void main(){
	int G[MAX][MAX]={{0,2,5,8,6},{2,0,8,10,4},{5,8,0,8,6},{8,10,8,0,11},{6,4,6,11,0}};
	int i, j, n=5, u;
	printf("Enter your area\n1. Jayanagar\n2. Basavanagudi\n3. JP Nagar\n4. Bommanahalli\n5. Banashankari\n");
	scanf("%d", &u);
	switch(u)
	{
		case 1:
		printf("The closest ATMs near you:\n");
		printf("In Bommanahalli:\n");
		printf("->1&, 2, Begur Main Rd\n");
		printf("->65/2a, Devarachikkanahalli Main Rd\n");
		break;
		case 2:
		printf("The closest ATMs near you:\n");
		printf("In Basavanagudi");
		printf("->198, Gandhi Bazar Main Rd, Gandhi Bazaar\n");
		printf("")


	}
	dijikstra(G,n,u-1);

}
 
void dijikstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}