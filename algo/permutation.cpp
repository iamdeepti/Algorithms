#include<bits/stdc++.h>

using namespace std;

void per(char *in, int i)
{
    if(in[i]=='\0')
    {
        //print
        cout<<in<<" ";
        return;
    }
    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        per(in,i+1);
        swap(in[i],in[j]);
    }
}
int main()
{
    char in[]="abc";

    per(in,0);
    return 0;
}
