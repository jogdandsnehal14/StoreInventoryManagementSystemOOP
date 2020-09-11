//---------------------------------------------------------------------------
// File: commandFileReader.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for CommandFileReader class
// The CommandFileReader class is responsible for processing the commands
//---------------------------------------------------------------------------

#include "commandFileReader.h"
#include <sstream>

//------------------------------------------------------------------------
// Executes the command on the store pointer object
// @pre input line stream is valid and store object is valid
// @post returns the hash of the given item id
// @param inputLineStream The line stream
// @param store The store object
void CommandFileReader::executeCommand(stringstream& inputLineStream, Store* store) {
   string strCommandType = InventoryFileReader::getString(inputLineStream, ',');
   inputLineStream.get();
   char commandType = strCommandType[0];
   
   Customer* customer = nullptr;;
   Inventory* inventory = nullptr;

   if (commandType == 'S' || commandType == 'B' || commandType == 'C') {
      string customerId = InventoryFileReader::getString(inputLineStream, ',');
      inputLineStream.get();
      customer = store->getCustomer(customerId);

      if (customer == nullptr) {
         cout << "Customer not found in store: " << customerId << endl;
         return;
      }

      if (commandType != 'C') {
         string strInventoryType = InventoryFileReader::getString(inputLineStream, ',');
         inputLineStream.get();
         char inventoryType = strInventoryType[0];

         Inventory* inventoryToFind = InventoryFileReader::getInventoryObject(inventoryType, inputLineStream);
         if (inventoryToFind != nullptr) {
            inventory = store->getInventory(inventoryToFind);
         }

         if (inventory == nullptr) {
            cout << "Inventory not found in store: " << inventoryType << endl;
            return;
         }
      }
   }

   Transaction* transaction;
   switch (commandType) {
   case 'S':
      transaction = new SellTransaction();
      transaction->addTransaction(inventory);
      customer->addTransaction(inputLineStream.str());
      break;
   case 'B':
      transaction = new BuyTransaction();
      transaction->addTransaction(inventory);
      customer->addTransaction(inputLineStream.str());
      break;
   case 'D':
      cout << "Store Inventory: " << endl;
      store->displayInventory();
      cout << endl;
      break;
   case 'C':
      customer->display();
      cout << endl;
      break;
   case 'H':
      cout << "Store History: " << endl;
      store->displayHistory();
      cout << endl;
      break;
   default:
      cout << "Invalid command type: " << commandType << endl;
      break;
   }

   return;
}