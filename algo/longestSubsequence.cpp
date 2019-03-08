#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int dp[100];
    for(int j=0;j<n;j++)
    {
        dp[j]=1;
        int max = 1;
        for(int i = 0;i<j;i++)
        {
            if(arr[i]<arr[j] && dp[i]+1>max)
                max = dp[i]+1;
        }
        dp[j]=max;
        cout<<dp[j]<<" ";
    }
    cout<<endl;
    cout<<*max_element(dp,dp+n);
    return 0;
}
