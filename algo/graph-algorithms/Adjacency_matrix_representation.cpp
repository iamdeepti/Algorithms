#include <iostream>
using namespace std;

int main()
{
int u,v;
cin>>u>>v;
int U,V;
int adjMatrix[u][v];
for(int i=0;i<u;i++)
{
    for(int j=0;j<v;j++)
    {    cin>>U>>V;
         adjMatrix[U][V]=1;
         adjMatrix[V][U]=1;
    }
}
return 0;
}
