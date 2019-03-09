#include<iostream>
using namespace std;


//Nodes of the linked list
struct ListNode{
int VertexNumber ;
struct ListNode* next;
};
struct Graph{
int V;
int E;
ListNode ** Adj; //pointer to head of linked list
};
//function to create Graph
struct Graph * adjListOfGraph(){
int i,x,y;
struct ListNode * temp;
struct Graph * G = new Graph;
cout<<"Enter no of vertices and edges respectively : ";
cin>>G->V>>G->E;
G->Adj[G->V];
for(i=0;i<G->V;i++)
{
    G->Adj[i] = new ListNode;
    G->Adj[i]->VertexNumber = i;
    G->Adj[i]->next = G->Adj[i];
}
//Reading Edges
for(i=0;i<G->E;i++)
{
    cin>>x>>y;
    temp = new ListNode;
    temp->VertexNumber = y;
    temp->next = G->Adj[x];
    if(G->Adj[x]->next == G->Adj[x])
        G->Adj[x]->next = temp;
    temp = new ListNode;
    temp->VertexNumber = x;
    temp->next = G->Adj[y];
    if(G->Adj[y]->next == G->Adj[y])
        G->Adj[y]->next = temp;
}
return G;
}
int main(){


return 0;
}
