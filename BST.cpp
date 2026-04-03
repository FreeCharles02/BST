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

    TreeNode* root = nullptr;
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
                 this->insert(newNode, currNode);
               } else {
                this->_delete(newNode->data, currNode);
               } 

    };

    void insert(TreeNode* newNode, TreeNode* currNode) {
        if (currNode == nullptr) {
           this->root = newNode;
           this->size++;
           return;
           // base case if tree is empty
        }
        if (currNode->data > newNode->data) {
            if (currNode->left == nullptr) {
                currNode->left = newNode;
                this->size++;
                return;
            } else {
                currNode = currNode->left;
            return insert(newNode,currNode);
            }
        }

        if (currNode->data < newNode->data) {
            if (currNode->right == nullptr) {
                currNode->right = newNode;
                this->size++;
                return;
            } else {
                currNode = currNode->right;
              return  insert(newNode, currNode);
            }
        }
    };

    TreeNode* lookup(int val, TreeNode* rootCopy) {
        if (rootCopy == nullptr) {return nullptr;}
        if (rootCopy->data == val) {return rootCopy; }
      if (rootCopy->data > val) {
           rootCopy = rootCopy->left;
         return this->lookup(val,rootCopy);
       } else {
        rootCopy = rootCopy->right;
      return  this->lookup(val,rootCopy);
       }
    }

    int getMin(TreeNode* node) {
        if (node->left != nullptr) {
            return this->getMin(node->left);
        }
        return node->data;
    };

    void _delete(int val, TreeNode* &currNode) {
        if (this->root == nullptr) {
            std::cout<< "Tree is empty" << "\n";
            // base case if tree is empty
            return;
        }
        if (currNode->data == val) {
            TreeNode* leftTemp = nullptr;
            TreeNode* rightTemp = nullptr;
            if (currNode->left == nullptr && currNode->right == nullptr) {

                delete currNode;
                currNode = nullptr;
                this->size--;
                return;
        } 

        

        if (currNode->left != nullptr && currNode->right != nullptr) {
            int inOrderSuccesorVal = this->getMin(currNode->right);
            currNode->data = inOrderSuccesorVal;
           return this->_delete(inOrderSuccesorVal, currNode->right);
        }
        
        if (currNode->left != nullptr) 
        {
            leftTemp = currNode->left;
            currNode = leftTemp;
            this->size--;
            return;
        }

        if (currNode->right != nullptr)
        {
           rightTemp = currNode->right;
           currNode = rightTemp;
           this->size--;
        }

    
    }

    if (currNode->data > val) {
        currNode = currNode->left;
        return _delete(val, currNode);
    } else {
        currNode = currNode->right;
        return _delete(val, currNode);
    }
};

    bool contains(TreeNode* newNode, TreeNode* currNode) {
       if (currNode == nullptr) {return false;}
       if (currNode->data == newNode->data ) {return true;}
       
       if (currNode->data > newNode->data) {
          currNode = currNode->left;
         return this->contains(newNode,currNode);
       } else {
        currNode = currNode->right;
      return  this->contains(newNode,currNode);
       }
    }

    void printInOrder() {
        while () {
            // printInOrder
        }
    }
};

int main() 
{
    BST tree;
    tree.insertOrDelete(10);
    tree.insertOrDelete(5);
    tree.insertOrDelete(7);
    tree.insertOrDelete(8);
    tree.insertOrDelete(20);
    tree.insertOrDelete(6);
    tree.insertOrDelete(7);
    tree.insertOrDelete(15);
    tree.insertOrDelete(30);
    return 0;
}