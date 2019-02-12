#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int lcs(char x[100], char y[100], int i, int j)
{
    if(memo[i][j]!=-1)
    {
        cout<<"already known "<<endl;
        return memo[i][j];
    }
    if(x[i]=='\0' || y[j]=='\0')
    {
        return 0;
    }
    if(x[i]==y[j])
    {   memo[i][j]= 1+ lcs(x,y,i+1,j+1);
        return memo[i][j];
    }
    memo[i][j]= max(lcs(x,y,i,j+1),lcs(x,y,i+1,j));
    return memo[i][j];

}
int dp[101][101];
int lcsDP(char x[100],char y[100])
{
   int m = strlen(x);
   int n =strlen(y);
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(x[i]==y[j])
           {
               dp[i][j]= 1 + dp[i-1][j-1];
           }
           else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
           }
       }
   }

   return dp[m][n];
}
int main()
{
    char x[100], y[100];
    cin>>x>>y;
    memset(memo,-1,sizeof(memo));
    memset(dp,-1,sizeof(dp));
    cout<<lcs(x,y,0,0)<<endl;
    cout<<lcsDP(x,y);
    return 0;
}
