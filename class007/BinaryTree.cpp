// 二叉树及其三种序的遍历递归实现
#include <bits/stdc++.h>
using namespace std;

// 二叉树的实现
struct TreeNode {
    int val;
    TreeNode *head,*left,*right;
    TreeNode():val(0),head(nullptr),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),head(nullptr),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode& head):val(x),head(&head),left(nullptr),right(nullptr){}

    bool isFull(){
        return left&&right;
    }

    bool newChild(int x){
        if(isFull()){
            return false;
        }
        if(left==nullptr){
            left = new TreeNode(x,*this);
        }else{
            right = new TreeNode(x,*this);
        }return true;
    }
};

class BinaryTree {
public:    
    TreeNode *root;
    BinaryTree(TreeNode& root):root(&root){}
    BinaryTree(TreeNode* root):root(root){}
    BinaryTree(int x){
        root = new TreeNode(x);
    }
public:
    // 先序遍历
    void preOrder(TreeNode *root){
        if(root==nullptr) return;
        cout << root->val << '\n';
        preOrder(root->left);
        preOrder(root->right);
    }

    // 中序遍历
    void midOrder(TreeNode *root){
        if(root==nullptr) return;
        midOrder(root->left);
        cout << root->val << '\n';
        midOrder(root->right);
    }

    // 后序遍历
    void posOrder(TreeNode *root){
        if(root==nullptr) return;
        posOrder(root->left);
        posOrder(root->right);
        cout << root->val << '\n';
    }
};