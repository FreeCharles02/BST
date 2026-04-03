#include<iostream>
#include<stack>
#include <string>

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
    void insertOrDelete(int value) {
        TreeNode* currNode = this->root;
        TreeNode* newNode = new TreeNode(value); 
            if (this->contains(newNode, currNode) == false) {
                 this->insert(currNode, newNode);
               } 
    };

    void insert(TreeNode* newNode, TreeNode* currNode) {
        if (currNode == nullptr) {
           this->root = newNode;
           return;
           // base case is tree is empty
        }
        if (currNode->data > newNode->data) {
            if (currNode->left == nullptr) {
                currNode->left = newNode;
                return;
            } else {
                currNode = currNode->left
                insert(newNode,currNode);
            }
        }

        if (currNode->data < newNode->data) {
            if (currNode->right == nullptr) {
                currNode->right = newNode;
                return;
            } else {
                currNode = currNode->right;
                insert(newNode, currNode);
            }
        }
    };

    void _delete(TreeNode* newNode, TreeNode* currNode) {
        
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
