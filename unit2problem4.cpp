#include <iostream>

using namespace std;
char a[100];

void k_ary(int n, int k)
{
    if(n<1)
    {
        cout<<a<<endl;
        return;
    }
    for(int i=0;i<k;i++)
    {
        a[n-1]=i+'0';
        k_ary(n-1,k);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    k_ary(n,k);
    return 0;
}
