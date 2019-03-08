#include<bits/stdc++.h>

using namespace std;

int inf = 100000;
void build(int *a,int s, int e, int index,int * tree){
    if(s==e){
        tree[index]=a[e];
        return;
    }
    int mid=(s+e)/2;
    build(a,s,mid,2*index,tree);
    build(a,mid+1,e,2*index+1,tree);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int minq(int * tree, int qs, int qe, int s, int e,int index)
{   //complete overlap
    if(s>=qs && e<=qe)
    {
        //cout<<"complete overlap in "<<s<<endl;
        return tree[index];
    }
    //no overlap
    if(qe<s || qs>e)
        return inf;
    {
        int mid=(s+e)/2;
        //cout<<"partial overlap in : "<<s<<" "<<e<<endl;
        return min(minq(tree,qs,qe,s,mid,2*index),minq(tree,qs,qe,mid+1,e,2*index+1));
    }
}
void update(int * tree, int inc, int index, int s, int e,int tind)
{
    //Base Case - if at leaf node
    if(s==e && s==index)
    {
        tree[tind]+=inc;
        return;
    }
    //if index is in the range
    if(index<=e && index>=s)
    {
        int mid = (s+e)/2;
        update(tree,inc,index,s,mid,2*tind);
        update(tree,inc,index,mid + 1,e,2*tind+1);
        tree[tind]= min(tree[2*tind],tree[2*tind+1]);
    }
    if(index<s || index>e)
        return ;
}
void rangeupdate(int s, int e, int * tree, int l, int r,int index,int inc)
{
    //No overlap
    if(l>e || r<s)
        return;
    //leaf node
    if(s==e)
    {
        tree[index]+=inc;
        return;
    }
    int mid = (s+e)/2;
    rangeupdate(s,mid,tree,l,r,2*index,inc);
    rangeupdate(mid+1,e,tree,l,r,2*index+1,inc);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}
int main()
{
    int arr[]={1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(int);
    int * tree = new int[4*n +1];
    build(arr,0,5,1,tree);
    for(int i=1;i<=13;i++)
        cout<<tree[i]<<" ";
    int qs,qe;
    cin>>qs>>qe;
    cout<<minq(tree,qs,qe,0,5,1);
    cout<<"enter increment and index to update : ";
    int inc, index;
    cin>>inc>>index;
    arr[index]+=inc;
    update(tree,inc,index,0,5,1);
    for(int i=1;i<=13;i++)
        cout<<tree[i]<<" ";
    int l,r;
    cout<<"Enter range to be updated : ";
    cin>>l>>r;
    rangeupdate(0,5,tree,l,r,1,inc);
    for(int i=1;i<=13;i++)
        cout<<tree[i]<<" ";
    return 0;
}
