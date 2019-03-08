#include<bits/stdc++.h>

using namespace std;
 int n;

int memo[20][20];

int wine(vector<int> cost, int n)
{
    int cnt = n;

    for(int i=0;i<n;i++)
        memo[i][i]=cost[i]*cnt;
    cnt--;
    for(int len = 2; len <= n;len++)
    {
        int str = 0;
        int end = n - len ;
        while(str<=end){
            int windowEnd = str+len-1;
            memo[str][windowEnd]= max(cost[str]*cnt + memo[str+1][windowEnd],cost[windowEnd]*cnt + memo[str][windowEnd-1]) ;
            str ++;
        }
        cnt--;
    }
    return memo[0][n-1];
}
int main(){
cin>>n;
memset(memo,0,n*n);
vector<int> cost(n);
for(int i=0;i<n;i++)
    cin>>cost[i];
cout<<wine(cost,cost.size());
return 0;
}
