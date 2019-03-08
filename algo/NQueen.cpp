#include<bits/stdc++.h>

using namespace std;
bool issafe(int i,int j,int board[10][10],int n){
    for(int k=0;k<i;k++)
    {

        if(board[k][j]==1)
            return false;

    }
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
     x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}
bool nqueen(int board[10][10],int i,int n)
{
    //base case
    if(i==n)
    {
        //cout<<"board";
        for(int k=0;k<n;k++)
        {
            for(int m=0;m<n;m++)
            {
                if(board[k][m]==1)
                    cout<<"Q";
                else
                    cout<<"_";
            }
            cout<<"\n";
        }
        cout<<"\n";
        //return true;
        return false;
    }
    for(int j=0;j<n;j++)
    {
       //cout<<" for pos "<<i<<","<<j<<issafe(i,j,board,n);
        if(issafe(i,j,board,n))
        {
             board[i][j]=1;
             //cout<<"safe  posn "<<i<<" ,"<<j<<endl;
            if(nqueen(board,i+1,n))
                return true;

        }
         board[i][j]=0;

    }
    return false;
}
int main()
{
    int n = 5;
    int board[10][10]={0};
    nqueen(board,0,n);
    return 0;
}
