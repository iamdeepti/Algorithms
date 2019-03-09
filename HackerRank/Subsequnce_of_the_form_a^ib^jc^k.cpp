#include<bits/stdc++.h>
using namespace std;
int findchar(char a[],char ch,int k)
{
    for(int i=k;a[i]!='\0';i++)
    {
        if(a[i]==ch)
            return i;
    }
    return -1;
}
int no_of_subsequences(char a[],int i)
{
    if(a[i+2]=='\0')
        return 0;
    if(a[i]=='a')
    {

        int k = findchar(a,'b',i+1);
        int j = findchar(a,'c',k+1);
        if(k==-1 || j==-1)
            return no_of_subsequences(a,i+1);
        else
            return 1+no_of_subsequences(a,i+1);
       // return no_of_subsequences(a,i+1);
    }
    else
    return no_of_subsequences(a,i+1);

}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t){
	char * a = new char[100];
	cin>>a;
	cout<<no_of_subsequences(a,0)<<endl;
	t--;

	}
	return 0;
}
