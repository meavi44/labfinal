#include<bits/stdc++.h>
using namespace std;

struct AVLTrees {
    struct Node {
        int data, height;
        Node *left, *right;
        Node(int a) {
            data = a;
            height = 1;
            left = right = NULL;
        }
    };

    Node* root;
    AVLTrees(){
        root=NULL;
    }

    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return root->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int getBalance(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return height(root->left) - height(root->right);
    }

    Node* insert(Node* root, int key) {
        if (root == NULL) {
            return new Node(key);
        }
        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        else if (key > root->data) { // Fixed this condition
            root->right = insert(root->right, key);
        }
        else {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int bf = getBalance(root);

        // Left Left Case
        if (bf > 1 && key < root->left->data) {
            return rightRotate(root);
        }

        // Right Right Case
        if (bf < -1 && key > root->right->data) {
            return leftRotate(root);
        }

        // Left Right Case
        if (bf > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (bf < -1 && key < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
};

void preorder(AVLTrees::Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right); // Changed to preorder
}

int main() {
    int t;
    //cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        AVLTrees avl;
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
