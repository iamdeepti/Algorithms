#include<bits/stdc++.h>
int m,n;
using namespace std;
bool way(char maze[10][10],int i,int j,int res[10][10])
{
    if(j==n-1 && i==m-1)
    {
        res[i][j]=1;
        //cout<<"since "<<i<<","<<j<<endl;
        for(int k=0;k<m;k++)
        {
         for(int l=0;l<n;l++)
            cout<<res[k][l];
            cout<<endl;
        }
                return true;
    }
    //res[i][j]='1';
    if(maze[i][j]=='X')
     {
            //cout<<"posn "<<i<<","<<j<<" not safe "<<endl;
            return false;

     }
         if((i>=m) || (j>=n))
        {   //cout<<"out of maze";
            return false;}
    res[i][j]=1;
    //res[i][j]='0';
    //cout<<"posn "<<i<<","<<j<<"is safe "<<endl;
    bool fwd = way(maze,i+1,j,res);
    bool dwn = way(maze,i,j+1,res);
    res[i][j]=0;
    if(fwd||dwn)
     {
        //cout<<"i can still move"<<endl;
        return true ;
     }
     //cout<<"can't move now returning false"<<endl;
    return false;
}
int main()
{

    //cin>>m>>n;
    m=4,n=5;
    char maze[10][10] = {"00X00",
                         "0X000",
                         "000X0",
                         "0X000"};
       /* for(int k=0;k<m;k++)
        {
         for(int l=0;l<n;l++)
            cin>>maze[k][l];
        }*/
    //m=maze.size()-1;
    //n=maze[0].length()-1;

    //cout<<maze.size();
    //cout<<maze[0].length()<<endl;
    int res[10][10]={0};
    if(way(maze,0,0,res))
        cout<<"path found:"<<endl;
    else
        cout<<"couldn't find path"<<endl;
    return 0;
}
