#include<bits/stdc++.h>

using namespace std;
 int n;

int memo[20][20];

int wine(vector<int> cost,int i, int j,int year)
{

    if(i==j)
        memo[i][j]=cost[i]*year;

    // memo[i][j] = (max)
    if(memo[i][j]!=0)
        return memo[i][j];
    memo[i][j] = max(cost[i]*year + wine(cost,i+1,j,year+1), cost[j]*year + wine(cost,i,j-1,year+1));
        return memo[i][j];
}
int main(){
cin>>n;
for(int i=0;i<n;i++)
{
     for(int j=0;j<n;j++)
        memo[i][j]=0;
}
vector<int> cost(n);
for(int i =0;i<n;i++)
    cin>>cost[i];
cout<<wine(cost,0,cost.size()-1,1);
return 0;
}
