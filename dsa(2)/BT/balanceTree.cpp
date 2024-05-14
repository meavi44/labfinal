//check whether a tree is balance or not
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int a){
        val=a;
        left=right=NULL;
    }
};
int check(Node* root){
    if(root==NULL) return 0;
    int lh=check(root->left);
    if(lh==-1)return -1;
    int rh=check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;   //if the abs of left and right is less than or equal to 1 then we call it balance
    return max(lh,rh)+1;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
     root->right->left=new Node(4);
      root->right->left->left=new Node(3);
       root->right->left->left->right=new Node(3);
       
    cout<<check(root);
}