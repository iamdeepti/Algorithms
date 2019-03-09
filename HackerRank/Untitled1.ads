#include<bits/stdc++.h>
using namespace std;

int no_of_subsequences(char a[],int i)
{
    if(a[i+2]=='\0')
        return 0;
    if(a[i]=='a')
    {
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]=='b')
            {
                for(int j=i;j!='\0';j++)
                {
                    if(a[i]=='c')
                        return 1+no_of_subsequences(a,i+1);
                }
            }
        }
        return no_of_subsequences(a,i+1);
    }
    return no_of_subsequences(a,i+1);

}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t){
	char a[101];
	cin>>a;
	cout<<no_of_subsequences(a,0);
	t--;

	}
	return 0;
}
