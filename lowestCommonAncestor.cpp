#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    bool contains(Node * root, int v)
    {
        if(root==NULL)
            return false;
        if(root->left->data==v || root->right->data==v)
            return true;
        //return (contains(root->left,v) || contains(root->right,v));
        if(root->data > v)
            return contains(root->left,v);
        else
            return contains(root->right,v);
    }

    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        stack<Node *> st;
        st.push(root);
        cout<<"......";
        while(root->data!=v1 && root!=NULL)
        {
            if(v1>root->data)
                root=root->right;
            else
                root=root->left;
            if(!root)
                break;
            st.push(root);

        }
        while(!contains(st.top(),v2) && !st.empty())
            st.pop();
        cout<<st.top()->data<<" ..";
        return st.top();
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

  	int v1, v2;
  	std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

  	std::cout << ans->data;

    return 0;
}
