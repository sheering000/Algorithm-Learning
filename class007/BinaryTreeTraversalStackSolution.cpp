// 二叉树遍历的非递归实现
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class BinaryTree{
public:
    TreeNode *root;
    BinaryTree(TreeNode &root):root(&root){}
    BinaryTree(TreeNode *root):root(root){}
    BinaryTree(int x):root(new TreeNode(x)){}

public:
    // 先序遍历
    vector<int> preOrder(TreeNode *head){
        vector<int> res;
        if(head){
            stack<TreeNode*> stk;
            stk.push(head);
            while(!stk.empty()){
                head = stk.top();
                stk.pop();
                res.push_back(head->val);
                if(head->right) stk.push(head->right);
                if(head->left) stk.push(head->left);
            }
        }
        return res;
    }

    // 中序遍历
    vector<int> midOrder(TreeNode *head){
        vector<int> res;
        if(head){
            stack<TreeNode*> stk;
            while(!stk.empty()||head){
                if(head){
                    stk.push(head);
                    head = head->left;
                }else{
                    head = stk.top();
                    stk.pop();
                    res.push_back(head->val);
                    head = head->right;
                }
            }
        }
        return res;
    }

    // 后序遍历
    // 两个栈实现
    vector<int> posOrder_2stack(TreeNode *head){
        vector<int> res;
        if(head){
            stack<TreeNode*> stk;
            stack<int> collect;
            stk.push(head);
            while(!stk.empty()){
                head = stk.top();
                stk.pop();
                collect.push(head->val);
                if(head->left) stk.push(head->left);
                if(head->right) stk.push(head->right);
            }
            while(!collect.empty()){
                res.push_back(collect.top());
                collect.pop();
            }
        }
        return res;
    }

    // 后序遍历
    // 一个栈实现
    vector<int> posOrder_1stack(TreeNode *head){
        vector<int> res;
        if(head){
            stack<TreeNode*> stk;
            stk.push(head);
            // 如果始终没有打印过结点，head为头节点
            // 若打印过节点，head为上次打印的结点
            while(!stk.empty()){
                TreeNode *cur = stk.top();
                if(cur->left!=nullptr
                    &&cur->left!=head
                    &&cur->right!=head){
                    // 有左树且左树未处理
                    stk.push(cur->left);
                }else if(cur->right!=nullptr
                    &&cur->right!=head){
                    // 有右树且右树未处理
                    stk.push(cur->right);
                }else{
                    res.push_back(cur->val);
                    head = stk.top();
                    stk.pop();
                }
            }
        }
        return res;
    }
};