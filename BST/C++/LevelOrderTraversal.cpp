//including header files
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//defining tree node
struct Treenode{
    int data;
    Treenode* left;
    Treenode* right;
    Treenode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//function for level order traversal in the BST
void levelOrder(Treenode* root){
    //initializing vector of integer vector for storing each level as a vector
    vector<vector<int>> lot;
    //for empty tree, print blank space
    if(root==NULL){
        cout<<"";
    }
    //accessing each node's left and right by storing node in a queue
    queue<Treenode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Treenode *node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        lot.push_back(level);
    }
    //printing value of each level by traversing through the vector of integer vectors.
    for(int i=0;i<lot.size();i++){
        for(int j=0;j<lot[i].size();j++){
            cout<<lot[i][j]<<" ";
        }
    }
    //end of function
}
//main method
int main(){
    //creating a tree
    Treenode* root=new Treenode(1);
    root->left=new Treenode(2);
    root->right=new Treenode(3);
    root->left->left=new Treenode(4);
    root->left->right=new Treenode(5);
    root->right->left=new Treenode(6);
    root->right->right=new Treenode(7);
    //performing level order traversal in the tree
    levelOrder(root);
}
//end of code
