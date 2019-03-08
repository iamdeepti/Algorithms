#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char n[15];
    cin>>n;
    long long ans=0;
    ans= (1<<strlen(n))-2;
    for(int i=strlen(n)-1,pos=0;i>=0;i--,pos++)
    {
        if(n[i]=='7')
            ans+= 1<<pos;
    }
    cout<<ans+1;
    return 0;
}
