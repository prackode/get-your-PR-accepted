// Height of a Tree
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int key)
{
    node* tmp = new node();
    tmp->data = key;
    tmp->left = tmp->right = nullptr;
 
    return tmp;
}

//INSERTION 
node* insert(node* root, int l_data){
    if(root == nullptr){
        return newNode(l_data);
    }
    if(l_data <= root->data){
        root->left = insert(root->left, l_data);
    }else{
        root->right = insert(root->right, l_data);
    }
    return root;
}

//INORDER TRAVERSAL
void inorder(node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int height(node* root){
    if(root == NULL)
        return -1;
    return max(height(root->left), height(root->left)) + 1;
}

int main(){
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"\n Inorder transversal: ";
    inorder(root);
    cout<<"\n Height of Tree: "<<height(root);
}