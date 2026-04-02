#include<iostream>
#include<stack>

class BST 
{
    struct TreeNode 
    {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;
    int size = 0;
    std::stack<TreeNode*> traversalStack;

public:
    int getSize() {
        return this->size;
    };
    void insertOrDelete(TreeNode* newNode) {
        TreeNode* currNode = this->root;
        if (this->contains(newNode, currNode) == false)        
    };
    bool contains(TreeNode* newNode, TreeNode* currNode) {
       if (currNode == nullptr) {return false;}
       if (currNode->data == newNode->data ) {return true;}
       
       if (currNode->data > newNode->data) {
          currNode = currNode->left;
          this->contains(newNode,currNode);
       } else {
        currNode = currNode->right;
        this->contains(newNode,currNode);
       }
    }
};
