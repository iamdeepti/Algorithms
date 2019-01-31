#include<bits/stdc++.h>

using namespace std;

vector<int> memo(10000,-1);
const int inf=(int)1e9;
int reduce(int n)
{
    int q1=inf,q2=inf,q3=inf;
    int count = 0;
    if(n==1)
        return count;
    if(memo[n]!=-1)
        return memo[n];
    if(n%3==0)
    {

         q1= 1+reduce(n/3);

    }

    if(n%2==0)
    {
        count++;
         q2 = 1+reduce(n/2);

    }
       q3=1+reduce(n-1);
       //memoize
       memo[n]=min(q1,min(q2,q3));
    return min(q1,min(q2,q3));
}
int reduceNoDP(int n)
{
    int dp[10000];
    //base cases for dp
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    for(int i=4;i<=n;i++)
    {
        int q1=inf,q2=inf,q3=inf;
        if(n%3==0)
            q1=dp[i/3]+1;
        if(n%2==0)
            q2=dp[i/2]+1;
        q3=dp[i-1]+1;
        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<reduce(n)<<endl;
    cout<<reduceNoDP(n);
    return 0;
}
