#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijikstra(int G[MAX][MAX], int n, int startnode);
 
void main(){
	system("clear");
	printf("::::::::::::::::ATM Locator::::::::::::::::::"\n\n\n);
	int G[MAX][MAX]={{0,2,5,8,6},{2,0,8,10,4},{5,8,0,8,6},{8,10,8,0,11},{6,4,6,11,0}};
	int i, j, n=5, u;
	printf("Enter your area\n1. Jayanagar\n2. Basavanagudi\n3. JP Nagar\n4. Bommanahalli\n5. Banashankari\n");
	scanf("%d", &u);
	printf("The closest ATMs near you:\n");
	switch(u)
	{
		case 4:
		printf("In Bommanahalli:\n");
		printf("->1&, 2, Begur Main Rd\n");
		printf("->65/2a, Devarachikkanahalli Main Rd\n");
		break;
		case 2:
		printf("In Basavanagudi:\n");
		printf("->198, Gandhi Bazar Main Rd, Gandhi Bazaar\n");
		printf("->29/1, MN Krishna Rao Rd\n");
		break;
		case 3:
		printf("In JP Nagar\n");
		printf("->33, 100 Feet Ring Road, 18th Main, 15t Cross, Near-VET Polytechnic, J P Nagar 2nd Phase\n");
		printf("->15th Cross, Near-Union Bank, J P Nagar 6th Phase\n");
		break;
		case 1:
		printf("In Jayanagar\n");
		printf("->Jayanagar Shopping Complex, 27th A Cross Rd, 4th T Block East, 4th Block\n");
		printf("->129, 16th Main, 4th Block, 16th Main Rd, 4th T Block East, Pattabhirama Nagar\n");
		break;
		case 5:
		printf("In Banashankari:\n");
		printf("->Shop No.121, 2nd Stage\n");
		printf("->242, 27th Cross Rd, Siddanna Layout, Banashankari Stage II\n");
		break;
		default:
		printf("Invalid choice\n Try again\n");
		break;
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
 
	for(i=0;i< 3;i++)
	{
		if(distance[i]>distance[i+1])
		continue;
		else if(distance[i]<distance[i+1])
		{
		printf("\n\n\nThe next closest ATMs are %d KMs away\n",distance[i]);
		switch(i)
	{
		case 4:
		printf("In Bommanahalli:\n");
		printf("->1&, 2, Begur Main Rd\n");
		printf("->65/2a, Devarachikkanahalli Main Rd\n");
		break;
		case 2:
		printf("In Basavanagudi:\n");
		printf("->198, Gandhi Bazar Main Rd, Gandhi Bazaar\n");
		printf("->29/1, MN Krishna Rao Rd\n");
		break;
		case 3:
		printf("In JP Nagar:\n");
		printf("->33, 100 Feet Ring Road, 18th Main, 15t Cross, Near-VET Polytechnic, J P Nagar 2nd Phase\n");
		printf("->15th Cross, Near-Union Bank, J P Nagar 6th Phase\n");
		break;
		case 1:
		printf("In Jayanagar:\n");
		printf("->Jayanagar Shopping Complex, 27th A Cross Rd, 4th T Block East, 4th Block\n");
		printf("->129, 16th Main, 4th Block, 16th Main Rd, 4th T Block East, Pattabhirama Nagar\n");
		break;
		case 5:
		printf("In Banashankari:\n");
		printf("->Shop No.121, 2nd Stage\n");
		printf("->242, 27th Cross Rd, Siddanna Layout, Banashankari Stage II\n");
		break;
		default:
		printf("Invalid choice\n Try again\n");
		break;
}
		}
	
	}		

}