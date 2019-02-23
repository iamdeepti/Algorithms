#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m;
	int n;
	cin>>n>>m;

	vector<vector<int>> queries(m);
	for(int i =0;i<m;i++)
	{
		queries[i].resize(3);
		for(int j =0;j<3;j++)
		{
			cin>>queries[i][j];
		}
	}
	long max =0;

vector<int> a(n);


for(int i =0;i<m;i++)
{
    a[queries[i][0]-1]+=queries[i][2] ;
    if(queries[i][1]<n)
        a[queries[i][1]]-= queries[i][2];
}

long total = 0;
    for(int i =0;i<n;i++)
    {
        total+=a[i];
        if(total>max)
            max = total;
    }
    //break;
    cout<<max;
return 0;

}
