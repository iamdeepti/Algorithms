#include <iostream>
#include <algorithm>

using namespace std;
int connect(int arr[100][100],int i,int j,int m,int n)
{
int count= 0;
    if(i>=m||j>=n || i<0 || j<0)
        return count;

    if(arr[i][j]==0)
        return count;
    int v[]={connect(arr,i+1,j,m,n),connect(arr,i,j+1,m,n),connect(arr,i+1,j+1,m,n),connect(arr,i,j-1,m,n),connect(arr,i-1,j-1,m,n)};
    return 1+ *max_element(v,v+6);
}
void connected1(int arr[100][100],int n,int m)
{
    int count = 0;
    int max =0;
    if(m==0 || n==0)
        return ;
        int j;
    for(int i =0;i<m;i++)
    {
        for( j =0;j<n;j++)
        {
            if(arr[i][j]==1)
             {
                 count = connect(arr,i,j,m,n);
                 break;
             }

        }
        if(j!=n)
            break;
    }
    cout<<count;

}
int main()
{
    int A[100][100];
    int n,m;
    cin>>n>>m;
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    connected1(A,n,m);
 return 0;
}
