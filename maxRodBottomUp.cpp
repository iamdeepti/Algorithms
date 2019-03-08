#include<bits/stdc++.h>

using namespace std;
int memo[100];
int maxrod(int len,int cost[100])
{
    //base cases
    memo[0]=0;
    memo[1]=cost[0];
    for(int i=2;i<=len;i++)
    {
        int max=-1;
        memo[i]=cost[i-1];
        for(int j=0;j<=len/2;j++)
        {
            if(memo[j]+memo[i-j] > max)
            {
                max = memo[j]+memo[i-j];
            }
        }
        memo[i]=max;
        cout<<i<<" "<<memo[i]<<endl;
    }
    return memo[len];
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
