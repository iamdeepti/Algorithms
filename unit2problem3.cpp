#include <iostream>
using namespace std;
char str[100];
void binary(int n)
{
    if(n<1)
    {
        cout<<str<<endl;
        return;
    }
    str[n-1]='0';
    binary(n-1);
    str[n-1]='1';
    binary(n-1);

}
int main()
{
    int n;
    cin>>n;
    //char str[100];
    binary(n);
    return 0;
}
