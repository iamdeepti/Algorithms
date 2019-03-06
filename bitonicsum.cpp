#include<bits/stdc++.h>
using namespace std;
int biotonic(int n,int arr[])
{
   // int inc=0,dec=0;
    int sum=arr[0];
    int max = 0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        max = arr[j];
        //inc = 0, dec =0;
        while(arr[j+1]>arr[j] && j<n-1)
        {
            max+= arr[j+1];
            j++;
            //inc=1;
        }
        while(arr[j+1]<arr[j] && j<n-1)
        {
            max +=arr[j+1];
            j++;
            //dec =1;
        }
        cout<<max<<" "<<j<<endl;
        i=j-1;
        if(arr[j]==arr[j+1] || j==n-1)
            i=j;
        if(max>sum)
            sum = max;
    }
    return sum;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<biotonic(n,arr)<<endl;

	    T--;
	}
	return 0;
}
