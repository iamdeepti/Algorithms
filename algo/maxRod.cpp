#include<bits/stdc++.h>

using namespace std;
int memo[100];
int maxrod(int len,int cost[100])
{
    int total = 0;
    //base cases
    if(len == 0)
        return 0;
    if(memo[len]!=-1)
        return memo[len];
    for(int i=0;i<len;i++)
    {
        if(cost[i]+maxrod(len-i-1,cost) > total)
            total = cost[i] + maxrod(len-i-1,cost);
        cout<<"cutting log of length "<<i+1<<" "<<total<<endl;

    }
    memo[len]=total;
    return total;
}

int main()
{
    int len, cost[100];
    cin>>len;

    for(int i=0;i<len;i++)
        cin>>cost[i];
      for(int i=0;i<=len;i++)
            memo[i]=-1;
    cout<<maxrod(len,cost);
    return 0;
}
