#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int a){
        val=a;
        left=NULL;
        right=NULL;
    }
};
struct BST{
    Node* root;
    BST(){
        root=NULL;
    }
    Node* insert(Node*root,int val){
        if(root==NULL){
            return new Node(val);
        }
        if(val<root->val){
            root->left=insert(root->left,val);
        }
        else if(val>root->val){
            root->right=insert(root->right,val);

        }
   
            return root;
        

    }
};
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
     int t;
    //cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
       BST avl;
        //cout << "Enter 5 elements for this test case:\n";
        for (int i = 0; i < 5; ++i) {
            int x;
            cin >> x;
            avl.root = avl.insert(avl.root, x);
        }

        //cout << "Preorder traversal of AVL tree for this test case: ";
        preorder(avl.root);
        cout << endl;
    }

    return 0;
    }