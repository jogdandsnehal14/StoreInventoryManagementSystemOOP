//---------------------------------------------------------------------------
// File: store.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for Store class
// The store class is responsible for storing all the details of the customers 
// and the inventory items. It reads the details from the file stream and 
// processes the commands and outputs the result accordingly
//---------------------------------------------------------------------------

#include "store.h"
#include "commandFileReader.h"

//------------------------------------------------------------------------
// The default constructor that creates a new Store object 
// @pre none
// @post creates a Store object
Store::Store() {
}

//------------------------------------------------------------------------
// Reads the customers details from the file input stream
// @pre input stream is valid stream of data formatted per specification
// @post sets the customers information 
// @param inputCustomersStream The input customers file stream
// Implementation:
//    Read stream for customer data
//    Add customer to the customer hashtable
void Store::readCustomers(istream& inputCustomersStream) {
   while (inputCustomersStream.peek() != EOF) {
      if (inputCustomersStream.eof()) break;

      string customerId;
      getline(inputCustomersStream, customerId, ',');
      inputCustomersStream.get();

      string customerName;
      getline(inputCustomersStream, customerName, '\n');

      Customer* customer = new Customer(customerId, customerName);
      customersTable.add(customerId, customer);
      customers.insert(customer);
   }
}

//------------------------------------------------------------------------
// Reads the inventory details from the file input stream
// @pre input stream is valid stream of data formatted per specification
// @post sets the inventory information 
// @param inputInventoryStream The input inventory file stream
// Implementation:
//    Read stream for inventory data
//    Create inventory objects based on inventory type
//    Add inventory objects to the inventory hashtable based on inventory id
void Store::readInventory(istream& inputInventoryStream) {
   while (inputInventoryStream.peek() != EOF) {
      if (inputInventoryStream.eof()) break;

      string line;
      getline(inputInventoryStream, line);
      stringstream lineStream(line);

      Inventory* inventory = InventoryFileReader::getInventoryObject(lineStream);
      if (inventory != nullptr) {
         string inventoryId = inventory->getId();
         SearchTree<Inventory>* tree = inventoryTable.get(inventoryId);
         if (tree != nullptr) {
            tree->insert(inventory);
         }
         else {
            tree = new SearchTree<Inventory>();
            tree->insert(inventory);
            inventoryTable.add(inventoryId, tree);
         }
      }
   }
}

//------------------------------------------------------------------------
// Reads the commands details from the file input stream and processes the 
// transactions and outputs results based on commands
// @pre input stream is valid stream of data formatted per specification
// @post sets the commands information 
// @param inputCommandsStream The input commands file stream
// Implementation:
//    Read stream for commands data
//    Process the commands
void Store::readCommands(istream& inputCommandsStream) {
   while (inputCommandsStream.peek() != EOF) {
      if (inputCommandsStream.eof()) break;

      string line;
      getline(inputCommandsStream, line);
      stringstream lineStream(line);

      CommandFileReader::executeCommand(lineStream, this);
   }
}
//------------------------------------------------------------------------
// Displays the inventory details
// @pre none
// @post displays all the customer details, outputs nothing if no customer 
//    exist
void Store::displayCustomers() const {
   customers.display();
}

//------------------------------------------------------------------------
// Displays the customer details
// @pre none
// @post displays all the inventory details, outputs nothing if no inventory 
//    exist
void Store::displayInventory() {
   for (string inventoryId : inventoryTable.getAllKeys()) {
      SearchTree<Inventory>* tree = inventoryTable.get(inventoryId);
      if (tree != nullptr) {
         tree->display();
      }
   }
}

//------------------------------------------------------------------------
// Displays the transaction history details
// @pre none
// @post outputs the history for every customer, 
//    with the customers in alphabetical order
void Store::displayHistory() const {
   customers.display();
}

//------------------------------------------------------------------------
// Gets the customer from the given customer id
// @pre customers hashtable is initialized
// @post returns the customer if found, nullptr if not found
   // @param customerId The customer Id
Customer* Store::getCustomer(const string customerId) {
   return customersTable.get(customerId);
}

//------------------------------------------------------------------------
// Gets the customer from the given customer id
// @pre customers hashtable is initialized
// @post returns the customer if found, nullptr if not found
   // @param customerId The customer Id
Inventory* Store::getInventory(Inventory* inventoryToFind) {
   SearchTree<Inventory>* tree = inventoryTable.get(inventoryToFind->getId());
   if (tree != nullptr) {
      return tree->find(inventoryToFind);
   }

   return nullptr;
}

//------------------------------------------------------------------------
// The Store object destructor 
// @pre none
// @post the Store object is completely deleted 
//    with corresponding memory deallocated
Store::~Store() {
}