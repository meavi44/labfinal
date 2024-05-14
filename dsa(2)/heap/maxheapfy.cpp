//maxheapify via linkedlist


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
struct BT{
    Node* root;
    BT(){
        root=NULL;
    }
    void insert(int val){
            if(root==NULL){
                root=new Node(val);
                return;
            }
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* temp=q.front();
                q.pop();
                if(temp->left==NULL){
                    temp->left=new Node(val);
                    break;
                }
                else{
                    q.push(temp->left);
                }
                if(temp->right==NULL){
                    temp->right=new Node(val);
                    break;
                }
                else{
                    q.push(temp->right);
                }
            }
    }
    
};
vector<vector<int>>levelorder(Node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size=q.size();
        
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL)  q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
}
void display(Node* root){
    vector<vector<int>>result=levelorder(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
void  maxheapify(Node*&root){
    if(root==NULL) return;
    Node* largest=root;
    if(root->left!=NULL&&root->left->val>root->val){
        largest=root->left;
    }
    if(root->right!=NULL&&root->right->val>largest->val){
        largest=root->right;
    }
    if(largest!=root){
        swap(root->val,largest->val);
        maxheapify(largest);
    }
}
int main(){
    BT b1;
    b1.insert(1);
    b1.insert(14);
    b1.insert(10);
    b1.insert(8);
    b1.insert(7);
    b1.insert(9);
    b1.insert(3);
     b1.insert(2);
      b1.insert(4);
       b1.insert(6);
    display(b1.root);
    maxheapify(b1.root);
    display(b1.root);
    
}