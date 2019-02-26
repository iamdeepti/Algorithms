#include<iostream>
#include<stack>
using namespace std;
int maxheight(stack<int> s1,stack<int> s2,stack<int> s3,int h1,int h2,int h3)
{
    if(s1.empty()||s3.empty()||s2.empty())
        return 0;
    if(h1==h2 && h2==h3)
        return h1;
    h1 = h1-s1.top();
        s1.pop();
    int q1 = maxheight(s1,s2,s3,h1,h2,h3);
        h2 = h2-s2.top();
        s2.pop();
    int q2 = maxheight(s1,s2,s3,h1,h2,h3);
        h3 = h3-s3.top();
        s3.pop();
    int q3 = maxheight(s1,s2,s3,h1,h2,h3);
    return max(q1,max(q2,q3));
}
int main()
{
  stack<int> s1,s2,s3;
  int h1=0,h2=0,h3=0;
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  int x;
  for(int i =0;i<n1;i++)
  {
  cin>>x;
    s1.push(x);
    h1+=x;
  }
  for(int i =0;i<n2;i++)
  {
  cin>>x;
    s2.push(x);
    h2+=x;
  }
  for(int i =0;i<n3;i++)
  {
  cin>>x;
    s3.push(x);
    h3+=x;
  }

    cout<<maxheight(s1,s2,s3,h1,h2,h3);

    return 0;
}
