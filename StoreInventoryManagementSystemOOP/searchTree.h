//---------------------------------------------------------------------------
// File: searchTree.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for HashTable class
// The SearchTree class is responsible for providing the binary search tree data structure 
// implementation
//---------------------------------------------------------------------------

#ifndef SearchTree_
#define SearchTree_

#include <iostream>

using namespace std;

template<class ItemType>
class SearchTree {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new Store object 
   // @pre none
   // @post creates a Store object
   SearchTree() {
      root = nullptr;
   };

   //------------------------------------------------------------------------
   // The copy constructor that deep copies the provided SearchTree object
   // @pre otherStore should be a valid SearchTree object
   // @post creates a deep copy of give SearchTree object
   // @param otherStore The SearchTree object to be copied
   SearchTree(const SearchTree& otherSearchTree) {
   };

   //------------------------------------------------------------------------
   // Inserts an item into the binary search tree
   // @pre inventory is valid
   // @post inserts the item into search tree
   // @param item The inventory item to be added
   bool insert(ItemType* item) {
      if (item == nullptr) {
         return false;
      }

      Node* newNode = new Node;
      newNode->item = item;
      newNode->left = nullptr;
      newNode->right = nullptr;

      // empty search tree
      if (root == nullptr) {
         root = newNode;
      }
      else {
         Node* current = root;
         Node* parent = root;

         // find the location where node could be inserted
         while (current != nullptr) {
            parent = current;
            if (*(newNode->item) < *(current->item)) 
               current = current->left;
            else 
               current = current->right;
         }

         if (*(newNode->item) < *(parent->item)) 
            parent->left = newNode;
         else 
            parent->right = newNode;
      }
   }

   ItemType* find(ItemType* item) {
      return findRecursive(root, item);
   }

   //------------------------------------------------------------------------
   // Displays the items in the search tree
   // @pre none
   // @post displays the items in the search tree
   // @param current The root node
   void display() const {
      inorderDisplay(root);
   };

   //------------------------------------------------------------------------
   // The SearchTree object destructor 
   // @pre none
   // @post the SearchTree object is completely deleted 
   //    with corresponding memory deallocated
   ~SearchTree() {
      clear(root);
   };

private:
   //------------------------------------------------------------------------
   // The Binary search tree Node structure
   struct Node {
      ItemType* item;
      Node* left;
      Node* right;
   };

   // The tree root node
   Node* root;


   //------------------------------------------------------------------------
   // Recursively finds the given item in the tree
   // @pre none
   // @post returs the found item in the search tree
   // @param current The root node
   // @param item The item to find
   ItemType* findRecursive(Node* node, ItemType* item) {
      if (node == nullptr) return nullptr;
      else if (*(node->item) == *item)
         return node->item;
      else if (*(item) < *(node->item)) findRecursive(node->left, item);
      else findRecursive(node->right, item);
   }

   //------------------------------------------------------------------------
   // Displays the items in the search tree
   // @pre none
   // @post displays the items in the search tree
   // @param current The root node
   void inorderDisplay(Node* node) const {
      if (node == nullptr) return;
      inorderDisplay(node->left);
      node->item->display();
      inorderDisplay(node->right);
   };

   //------------------------------------------------------------------------
   // Clears all the items from the search tree
   // @pre none
   // @post search tree is cleared
   void clear(Node* node) {
      if (node == nullptr) return;

      clear(node->left);
      clear(node->right);

      delete node->item;
      node->item = nullptr;
      delete node;
      node = nullptr;
   }
};
#endif