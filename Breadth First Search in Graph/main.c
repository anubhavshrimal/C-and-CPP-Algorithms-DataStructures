#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10
//a structure to represent node of an adjacency list
typedef struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
}AdjListNode;

//a structure to represent adjacency list
typedef struct AdjList
{
    AdjListNode* head;  //pointer to the head node of the list
}AdjList;

//a structure to represent a graph with v vertices
typedef struct Graph
{
    int v;
    AdjList* array;
}Graph;

//creates a new graph of v vertices
Graph* createGraph(int v)
{
    Graph *graph=(Graph*)malloc(sizeof(Graph));
    graph->v=v;

    graph->array=(AdjList*)malloc(v*sizeof(AdjList));

    int i;
    for(i=0;i<v;i++)
        graph->array[i].head=NULL;

    return graph;
}

//returns a new adjacency list node
AdjListNode* addAdjNode(int dest)
{
    AdjListNode *newNode=(AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

//adds an edge to the undirected graph
void addEdge(Graph *g,int src,int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    AdjListNode *newNode=addAdjNode(dest);
    newNode->next=g->array[src].head;
    g->array[src].head=newNode;

    //adds an edge from dest to src as it is an undirected graph
    newNode=addAdjNode(src);
    newNode->next=g->array[dest].head;
    g->array[dest].head=newNode;
}

//function to print the adjacency list of graph
void printGraph(Graph *g)
{
    int i;
    for(i=0;i<g->v;i++)
    {
        AdjListNode *ptr=g->array[i].head;
        printf("\nAdjacency List for node %d is:\nhead",i);
        while(ptr!=NULL)
        {
            printf(" -> %d",ptr->dest);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void BFS(Graph* g,int s)
{
    int status[max];
    int t;
    for(t=0;t<g->v;t++)
        status[t]=1;

    int queue[max];

    status[s]=2;
    queue[0]=s;
    int size=1;

    int i=0,j,k=0;

    while(size!=0)
    {
        s=queue[k];
        k++;
        printf("%d  ",s);
        status[s]=3;
        size--;
        AdjListNode* adj=g->array[s].head;
        while(adj!=NULL)
        {
            j=adj->dest;
            if(status[j]==1)
            {
                status[j]=2;
                i++;
                queue[i]=j;
                size++;
            }
            adj=adj->next;
        }
    }

}

//Driver function of the program
int main()
{
    //creation of a graph
    Graph *graph=createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,0,4);
    addEdge(graph,1,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,2,4);

    printGraph(graph);
    //printing the graph by its adjacency lists
    BFS(graph,2);
    return 0;
}














