/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
node * rightrotate(node * np)
{
    node * temp = (np)->left;
    node * child = temp->right;
    temp->right = np;
    (np)->left = child;
    (np)->ht = max((np)->left->ht,(np)->right->ht);
    temp->ht = max(temp->left->ht,temp->right->ht);
    return temp;
}
node * leftrotate(node * np)
{
    node * temp = (np)->right;
    node * child = temp->left;
    temp->left = (np);
    (np)->right = child;
    (np)->ht = max((np)->left->ht,(np)->right->ht);
    temp->ht = max(temp->left->ht,temp->right->ht);
    return temp;
}
int getBalance(node * root)
{
    if(root==NULL)
        return 0;
    if(root->left == NULL)
        return root->left->ht;
    else if(root->right == NULL)
        return -root->right->ht;
    else
        return root->left->ht - root->right->ht;
}
node * insert(node * root,int val)
{
	cout<<"in function insert";
  //inserting as in BST
    //node * curr = root;
    node * np = new node;
    np->val = val;
    np->left = NULL;
    np->right = NULL;
    np->ht = 0;
    if(root==NULL)
        return np;
    else if(root->val < val)
        root->right = insert(root->right,val);
    else if(root->val > val)
        root->left = insert(root->left,val);
    else
        return root;

    root->ht = 1+max(root->left->ht,root->right->ht);
    int balancefactor = getBalance(root);

    // unbalanced because of left child
    if(balancefactor >1)
    {
        //left left case
       if(root->left->val > val)
           return rightrotate(root);
        else //left right case
        {
            root->left = leftrotate((root->left));
            return rightrotate(root);
        }
    }
    // unbalanced because of right child
    else if (balancefactor <-1)
    {
        //right left case
        if(root->right->val > val)
        {
            root->right = rightrotate((root->right));
            return leftrotate(root);
        }
        else
            return leftrotate(root);
    }
    else
        return root;
    root->ht = 1+ max(root->left->ht,root->right->ht);
    return root;
}
