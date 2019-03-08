#include <bits/stdc++.h>

using namespace std;

int memo[101][101];
int edit(char s1[100],char s2[100],int i,int j)
{
    int total=0;
    //base case
    if(s1[i]=='\0' && s2[j]=='\0')
        return total;
        //do nothing if same
    if(s1[i]==s2[j])
    {
        cout<<"char are same"<<endl;
        total+= edit(s1,s2,i+1,j+1);
    }
        //if s1 still have characters
    else if(s2[j]=='\0')
    {
        cout<<"s2 empty"<<endl;
        return total+ strlen(s1)-i;
    }

        //if s2 still have characters
    else if(s1[i]=='\0')
    {
        cout<<"s1 is empty"<<endl;
         return total+ strlen(s2)-j;
    }
        //else replace insert or delete whichever is minimum
    else
    {
        cout<<"replace insert or delete "<<endl;
        total+= min(edit(s1,s2,i+1,j+1),min(edit(s1,s2,i,j+1),edit(s1,s2,i+1,j)))+1;
    }

    return total;
}
/*int editdp(char s1[100],char s2[100],int i,int j)
{
    int total=0;
    //base case
    if(memo[i][j]!=-1)
     {
          cout<<"already known"<<endl;
          return memo[i][j];
     }
    if(s1[i]=='\0' && s2[j]=='\0')
    {
        memo[i][j]=0;
        cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
         return memo[i][j];
    }

        //do nothing if same
    if(s1[i]==s2[j])
    {
        cout<<"char are same"<<endl;
        memo[i][j]= edit(s1,s2,i+1,j+1);
        cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
        return memo[i][j];
    }
        //if s1 still have characters
     if(s2[j]=='\0')
    {
        cout<<"s2 empty"<<endl;
        memo[i][j]=memo[i][j-1]+ strlen(s1)-i;
        cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
        return memo[i][j];
    }

        //if s2 still have characters
     if(s1[i]=='\0')
    {
        cout<<"s1 is empty"<<endl;
        memo[i][j]=memo[i-1][j]+ strlen(s2)-j;
        cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
        return memo[i][j];
    }
        //else replace insert or delete whichever is minimum

    {
        cout<<"replace insert or delete "<<endl;
        memo[i][j]= min(edit(s1,s2,i+1,j+1),min(edit(s1,s2,i,j+1),edit(s1,s2,i+1,j)))+1;
        cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
        return memo[i][j];
    }

}*/
int editdp(char in[100], char out[100])
{
    memo[0][0]=0;
    int m=strlen(in);
    int n = strlen(out);
    for(int i=1;i<=m;i++)
    {
        memo[i][0]= memo[i-1][0]+1;
    }
    for(int j=1;j<=n;j++)
    {
        memo[0][j]= memo[0][j-1]+1;
    }
    int q1,q2,q3;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            q1 = memo[i-1][j-1];
            q2 = memo[i][j-1];
            q3 = memo[i-1][j];
            memo[i][j]=min(q1,min(q2,q3))+ (in[i]!=out[j]);
        }
    }
    return memo[m][n];
}

int main()
{
    char input[100], change[100];
    cin>>input>>change;
    //memset(memo, -1, strlen(input)*strlen(change));
    for(int i=0;i<strlen(input);i++)
    {
        for(int j=0;j<strlen(change);j++)
        {
            memo[i][j]=-1;
        }
    }
    cout<<"through recursion "<<edit(input,change,0,0)<<endl<<endl;
    cout<<" DP----"<<endl;
    cout<<editdp(input,change);
    cout<<endl;

    return 0;
}
