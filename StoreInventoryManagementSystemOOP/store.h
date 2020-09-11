//---------------------------------------------------------------------------
// File: store.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for Store class
// The store class is responsible for storing all the details of the customers 
// and the inventory items. It reads the details from the file stream and 
// processes the commands and outputs the result accordingly
//---------------------------------------------------------------------------

#ifndef STORE_
#define STORE_

#include "customer.h"
#include "searchTree.h"
#include "hashTable.h"
#include <sstream>
#include <fstream>

using namespace std;

class Store {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new Store object 
   // @pre none
   // @post creates a Store object
   Store();

   //------------------------------------------------------------------------
   // Reads the customers details from the file input stream
   // @pre input stream is valid stream of data formatted per specification
   // @post sets the customers information 
   // @param inputCustomersStream The input customers file stream
   // Implementation:
   //    Read stream for customer data
   //    Add customer to the customer hashtable
   void readCustomers(istream& inputCustomersStream);

   //------------------------------------------------------------------------
   // Reads the inventory details from the file input stream
   // @pre input stream is valid stream of data formatted per specification
   // @post sets the inventory information 
   // @param inputInventoryStream The input inventory file stream
   // Implementation:
   //    Read stream for inventory data
   //    Create inventory objects based on inventory type
   //    Add inventory objects to the inventory hashtable based on inventory id
   void readInventory(istream& inputInventoryStream);

   //------------------------------------------------------------------------
   // Reads the commands details from the file input stream and processes the 
   // transactions and outputs results based on commands
   // @pre input stream is valid stream of data formatted per specification
   // @post sets the commands information 
   // @param inputCommandsStream The input commands file stream
   // Implementation:
   //    Read stream for commands data
   //    Process the commands
   void readCommands(istream& inputCommandsStream);

   //------------------------------------------------------------------------
   // Displays the inventory details
   // @pre none
   // @post displays all the customer details, outputs nothing if no customer 
   //    exist
   void displayCustomers() const;

   //------------------------------------------------------------------------
   // Displays the customer details
   // @pre none
   // @post displays all the inventory details, outputs nothing if no inventory 
   //    exist
   void displayInventory();

   //------------------------------------------------------------------------
   // Displays the transaction history details
   // @pre none
   // @post outputs the history for every customer, 
   //    with the customers in alphabetical order
   void displayHistory() const;

   //------------------------------------------------------------------------
   // Gets the customer from the given customer id
   // @pre customers hashtable is initialized
   // @post returns the customer if found, nullptr if not found
      // @param customerId The customer Id
   Customer* getCustomer(const string customerId);

   //------------------------------------------------------------------------
   // Gets the customer from the given customer id
   // @pre customers hashtable is initialized
   // @post returns the customer if found, nullptr if not found
      // @param customerId The customer Id
   Inventory* getInventory(Inventory* inventoryToFind);

   //------------------------------------------------------------------------
   // The Store object destructor 
   // @pre none
   // @post the Store object is completely deleted 
   //    with corresponding memory deallocated
   ~Store();

private:
   //------------------------------------------------------------------------
   // The list of customers saved in hashtable with customer id as key
   HashTable<Customer> customersTable;

   //------------------------------------------------------------------------
   // The search tree of all customers sorted by name
   SearchTree<Customer> customers;

   //------------------------------------------------------------------------
   // The root nodes of all inventory items
   HashTable<SearchTree<Inventory>> inventoryTable;
};

#endif