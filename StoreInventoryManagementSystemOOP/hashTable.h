//---------------------------------------------------------------------------
// File: hashTable.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for HashTable class
// The HashTable class is responsible for providing the hash table data structure 
// implementation
//---------------------------------------------------------------------------

#ifndef HASH_TABLE_
#define HASH_TABLE_

#include <string>

using namespace std;

template<class ItemType>
class HashTable {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new HashTable object 
   // @pre none
   // @post creates a HashTable object
   HashTable() {
      for (int index = 0; index < SIZE; index++) {
         table[index] = nullptr;
      }
   }

   //------------------------------------------------------------------------
   // Inserts an item into the hashtable
   // @pre item is valid
   // @post inserts the item into hashtable
   // @param item The item to be added
   void add(string itemId, ItemType* item) {
      int hashIndex = getHash(itemId);

      HashTableNode* node = new HashTableNode;
      node->key = itemId;
      node->value = item;
      node->next = nullptr;

      keys.push_back(itemId);

      // no collision
      if (table[hashIndex] == nullptr) {
         table[hashIndex] = node;
      }
      else {
         // collision detected, resolve by chaining
         HashTableNode* current = table[hashIndex];
         while (current != nullptr) {
            // if same item is already added, overwrite the value
            if ((current->key).compare(itemId) == 0) {
               ItemType* itemToDelete = current->value;
               delete itemToDelete;
               current->value = item;
            }

            current = current->next;
         }
      }
   };

   //------------------------------------------------------------------------
   // Clears all the items from the hashtable
   // @pre none
   // @post hashtable is cleared
   void clear() {
      for (int index = 0; index < SIZE; index++) {
         if (table[index] != nullptr) {
            HashTableNode* nodeToDelete = table[index];

            // delete all the nodes from the linked list
            while (table[index] != nullptr) {
               table[index] = table[index]->next;
               delete nodeToDelete->value;
               delete nodeToDelete;
               nodeToDelete = table[index];
            }
         }
      }
   }

   //------------------------------------------------------------------------
   // Checks if hashtable has the given key
   // @pre none
   // @post returns true if key is found
   // @param itemId The itemId to be searched for in hash table
   // @returns true if an item exists at given key
   bool containsKey(string itemId) const {
      int hashIndex = getHash(itemId);
      if (table[hashIndex] == nullptr) return false;
      return true;
   }

   //------------------------------------------------------------------------
   // Returns the item in the hashtable
   // @pre none
   // @post returns the item if key is found, else nullptr
   // @param itemId The itemId to be searched for in hash table
   // @returns the item at given key
   ItemType* get(string itemId) {
      int hashIndex = getHash(itemId);

      if (table[hashIndex] == nullptr) return nullptr;
      else {
         HashTableNode* current = table[hashIndex];
         while (current != nullptr) {
            if ((current->key).compare(itemId) == 0) return current->value;
            current = current->next;
         }

         return nullptr;
      }
   }

   vector<string> getAllKeys() {
      return keys;
   }

   //------------------------------------------------------------------------
   // The HashTable destructor 
   // virtual funtion to allow being overriden by the derived class
   // @pre none
   // @post the HashTable object is completely deleted 
   //    with corresponding memory deallocated
   ~HashTable() {
      clear();
   }

private:
   static const int SIZE = 9973;

   //------------------------------------------------------------------------
   // The HashTableNode structure 
   // @pre none
   struct HashTableNode {
      string key;
      ItemType* value;
      HashTableNode* next;
   };

   // The hashtable collection
   HashTableNode* table[SIZE];

   // The hashtable key collection
   vector<string> keys;

   //------------------------------------------------------------------------
   // Returns the hash of the item id
   // @pre none
   // @post returns the hash of the given item id
   // @param itemId The itemId to get hash for
   // @returns the hash of given item id
   int getHash(const string& itemId) {
      unsigned int b = 378551;
      unsigned int a = 63689;
      unsigned int hash = 0;

      for (int i = 0; i < itemId.length(); i++) {
         hash = hash * a + itemId[i];
         a = a * b;
      }

      return (hash & 0x7FFFFFFF) % SIZE;
   }
};
#endif