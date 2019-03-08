#include<iostream>
#include<math.h>
using namespace std;
bool isok(int n,int i, int j,int sudoku[20][20],int k){
    //number not in row
    for(int m=0;m<n;m++)
    {
        if(sudoku[i][m]==k)
           {
             //cout<<"same no in row"<<k<<endl;
             return false;
           }
    }
    //number not in column
    for(int m=0;m<n;m++)
    {
        if(sudoku[m][j]==k){
                //cout<<"same no in col: "<<k<<endl;
            return false;
        }
    }
    //number not in sub-grid
    int rootn = sqrt(n);
    int b = (i/rootn)*rootn;
    int c = (j/rootn)*rootn;
    for(int m=b;m<(b+sqrt(n));m++)
    {
        for(int p=c;p<(c+sqrt(n));p++)
        {
             if(sudoku[m][p]==k){
                   // cout<<"same no in sub grid : "<<k<<" at "<<m<<","<<p<<endl;
                    //cout<<c+rootn<<","<<c<<endl;
                return false;
             }
        }
    }
    //cout<<k<<" can be filled in "<<i<<","<<j<<endl;
        return true;
}
bool solve(int n, int i, int j,int sudoku[20][20])
{
    //base case
    //cout<<"for "<<i<<","<<j<<endl;
    if(i==n)
    {
       for(int k=0;k<n;k++)
       {
           for(int p=0;p<n;p++)
                cout<<sudoku[k][p]<<" ";
           cout<<endl;
       }
       return true;
    }
    if(j==n)
    {
        return solve(n,i+1,0,sudoku);
    }
    if(sudoku[i][j]!=0)
    {
        return solve(n,i,j+1,sudoku);
    }
    for(int k =1;k<=n;k++){
        if(isok(n,i,j,sudoku,k))
        {
            sudoku[i][j]=k;
            if(solve(n,i,j+1,sudoku))
                return true;
        }
       //
    }
     sudoku[i][j]=0;
     //cout<<"backtrack"<<endl;
    return false;
    //rec case
}
int main()
{
  int n=9;
  int sudoku[20][20]={{3,0,8,1,9,0,0,6,0},
                      {0,7,0,0,6,0,1,8,3},
                      {5,1,0,0,0,0,4,2,0},
                      {0,0,0,0,0,7,0,0,2},
                      {4,0,0,9,0,1,0,0,8},
                      {7,0,0,3,0,0,0,0,0},
                      {0,3,7,0,0,0,0,9,4},
                      {2,5,9,0,3,0,0,1,0},
                      {0,8,0,0,1,9,3,0,5}};
if(solve(n,0,0,sudoku))
    cout<<"solved";
else
    cout<<"no soln";

}
