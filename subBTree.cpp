#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node * createNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node * insert(Node * root, int data){
    if(root == NULL)
        return createNode(data);  
    else if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
}

Node * findSubRoot(Node * root, int x){
    if(root == NULL) return root;
    if(root->data == x)
        return root;
    else if(root->data > x)
        root = findSubRoot(root->left, x);
    else
        root = findSubRoot(root->right, x); 
}

void traverse(Node * root){
    if(root == NULL) return;
    cout << root->data << "\n";
    traverse(root->left);
    traverse(root->right);
}

int main(){
    Node * root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = insert(root, x);
    } 
    int x; cin >> x;
    root = findSubRoot(root, x);
    traverse(root);    
    
    return 0;
}
