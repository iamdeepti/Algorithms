#include <iostream>
#include <map>
#include <queue>

using namespace std;
class Tree{
    public:
        int data;
        Tree * left;
        Tree * right;
        int hd;
        Tree(int x)
        {
            left = NULL;
            right = NULL;
            data = x;
            hd=0;
        }

};
void topview(Tree * root)
{
  if(root==NULL)
    return;
  map<int,int> m;
  queue<Tree*> q;
  q.push(root);
  int hd;
  root->hd = 0;
  while(q.size())
  {


    hd = root->hd;
    if(m.count(hd)==0)
        m[hd]=root->data;
    if(root->left)
    {
        q.push(root->left);
        root->left->hd = hd-1;
    }
    if(root->right)
    {
        q.push(root->right);
        root->right->hd = hd+1;
    }
    q.pop();
    root = q.front();
  }
  map<int,int>::iterator it;
  for(it = m.begin();it!=m.end();it++)
    cout<<it->second<<" ";

}
Tree * insertion(Tree *root, int data)
{
    if(root==NULL)
        return new Tree(data);
    else if(root->data < data)
    {
        root->right = insertion(root->right,data);
    }
    else
    {
        root->left = insertion(root->left,data);
    }
    return root;
}
void inorder(Tree * root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
int main()
{
    int n;
    cin>>n;
    int x;
    Tree * root = NULL;
    for(int i =0;i<n;i++)
    {
        cin>>x;
        root = insertion(root,x);
    }
    inorder(root);
    cout<<endl;
     topview(root);
}
