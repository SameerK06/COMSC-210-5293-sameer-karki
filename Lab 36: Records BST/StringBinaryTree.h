// Specification file for the StringBinaryTree class
#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H

#include <iostream>
#include <string>
using namespace std;

// The StringBinaryTree class manages a binary tree of strings.
class StringBinaryTree {
private:
   // TreeNode is a private structure for StringBinaryTree nodes.
   struct TreeNode {
      string value; // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(string, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   StringBinaryTree()     { root = nullptr; }

   // Destructor deallocates all nodes in the tree.
   ~StringBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes.
   void insertNode(string);
   bool searchNode(string);
   void remove(string);
   bool modifyNode(string oldStr, string newStr); // Added by Sameer Karki

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};

// Implementation file for the StringBinaryTree class
#include "StringBinaryTree.h"
using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold str as its value,
// and passes it to the insert function.                  
void StringBinaryTree::insertNode(string str) {
   TreeNode *newNode = new TreeNode;      // Pointer to a new node.

   // Create a new node and store str in it.
   newNode->value = str;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   

// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool StringBinaryTree::searchNode(string str) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == str)
         return true;
      else if (str < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// remove calls deleteNode to delete the      
// node whose value member is the same as str.
void StringBinaryTree::remove(string str) {
   deleteNode(str, root);
}

// deleteNode deletes the node whose value 
// member is the same as str.              
void StringBinaryTree::deleteNode(string str, TreeNode *&nodePtr) {
   if (!nodePtr) {
      cout << "Record \"" << str << "\" not found" << endl;
      return;
   }
   if (str < nodePtr->value)
      deleteNode(str, nodePtr->left);
   else if (str > nodePtr->value)
      deleteNode(str, nodePtr->right);
   else {
      makeDeletion(nodePtr);
      cout << "Record \"" << str << "\" deleted" << endl;
   } 
}

// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// Modified by Sameer Karki
// Modify a record while preserving BST ordering
bool StringBinaryTree::modifyNode(string oldStr, string newStr) {
   if (!searchNode(oldStr)) {
      return false;
   }
   remove(oldStr);
   insertNode(newStr);
   return true;
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

// The displayPreOrder member function displays the values      
// in the subtree pointed to by nodePtr, via preorder traversal.
void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

// The displayPostOrder member function displays the values     
// in the subtree pointed to by nodePtr, via postorder traversal.
void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

#endif // STRINGBINARYTREE_H
