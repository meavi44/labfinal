//diameter of a BT
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
int diameter(Node*&root,int &dia){
    if(root==NULL)return 0;
    int lh=diameter(root->left,dia);
    int rh=diameter(root->right,dia);
    dia=max(dia,lh+rh);
    return 1+max(lh,rh);

}
int Dia(Node*&root){
    int diam=0;
    diameter(root,diam);
    return diam;

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
     root->right->left=new Node(4);
      root->right->left->left=new Node(3);
       root->right->left->left->right=new Node(3);
       
    cout<<Dia(root);
}