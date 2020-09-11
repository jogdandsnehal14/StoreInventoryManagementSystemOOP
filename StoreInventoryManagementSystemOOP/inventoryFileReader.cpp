//---------------------------------------------------------------------------
// File: inventoryFileReader.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for InventoryFileReader class
// The InventoryFileReader class is responsible for processing the inventory from file stream
//---------------------------------------------------------------------------

#include "inventoryFileReader.h"
#include <sstream>

//------------------------------------------------------------------------
// Gets the inventory object based on current line stream
// @pre none
// @post returns inventory object if valid line stream
// @param lineStream The line stream
// @param returns new inventory object
Inventory* InventoryFileReader::getInventoryObject(stringstream& inputLineStream) {
   string strInventoryType = getString(inputLineStream, ',');
   int inventorySize = getInteger(inputLineStream, ',');

   char inventoryType = strInventoryType[0];
   Inventory* inventory = getInventoryObject(inventoryType, inputLineStream);
   if (inventory != nullptr) inventory->setSize(inventorySize);
   return inventory;
}

//------------------------------------------------------------------------
// Gets the inventory object based on inventory type
// @pre none
// @post returns inventory object if valid line stream
// @param inventoryType The inventory Type
// @param inputLineStream The line stream
// @param returns new inventory object
Inventory* InventoryFileReader::getInventoryObject(char inventoryType, stringstream& inputLineStream) {
   Inventory* inventory;
   switch (inventoryType) {
   case 'C':
      inventory = getComicsInventoryObject(inputLineStream);
      break;
   case 'M':
      inventory = getCoinsInventoryObject(inputLineStream);
      break;
   case 'S':
      inventory = getSportCardsInventoryObject(inputLineStream);
      break;
   default:
      cout << "Invalid inventory type: " << inventoryType << endl;
      inputLineStream.ignore(256, '\n');
      return nullptr;
   }

   return inventory;
}

//------------------------------------------------------------------------
// Gets the Comics inventory object based on current line stream
// @pre none
// @post returns inventory object if valid line stream
// @param inputLineStream The line stream
// @param returns new inventory object
Inventory* InventoryFileReader::getComicsInventoryObject(stringstream& inputLineStream) {
   ComicsCollectibleInventory* inventory = new ComicsCollectibleInventory();
   inventory->setId("C");
   inventory->setYear(getInteger(inputLineStream, ','));
   inputLineStream.get();
   inventory->setGrade(getString(inputLineStream, ','));
   inputLineStream.get();
   inventory->setTitle(getString(inputLineStream, ','));
   inputLineStream.get();
   inventory->setPublisher(getString(inputLineStream, '\n'));
   return inventory;
}

//------------------------------------------------------------------------
// Gets the coins inventory object based on current line stream
// @pre none
// @post returns inventory object if valid line stream
// @param inputLineStream The line stream
// @param returns new inventory object
Inventory* InventoryFileReader::getCoinsInventoryObject(stringstream& inputLineStream) {
   CoinsCollectibleInventory* inventory = new CoinsCollectibleInventory();
   inventory->setId("M");
   inventory->setYear(getInteger(inputLineStream, ','));
   inputLineStream.get();
   inventory->setGrade(getInteger(inputLineStream, ','));
   inputLineStream.get();
   inventory->setType(getString(inputLineStream, '\n'));
   return inventory;
}

//------------------------------------------------------------------------
// Gets the SportCard inventory object based on current line stream
// @pre none
// @post returns inventory object if valid line stream
// @param inputLineStream The line stream
// @param returns new inventory object
Inventory* InventoryFileReader::getSportCardsInventoryObject(stringstream& inputLineStream) {
   SportCardsCollectibleInventory* inventory = new SportCardsCollectibleInventory();
   inventory->setId("S");
   inventory->setYear(getInteger(inputLineStream, ','));
   inputLineStream.get();
   inventory->setGrade(getString(inputLineStream, ','));
   inputLineStream.get();
   inventory->setPlayer(getString(inputLineStream, ','));
   inputLineStream.get();
   inventory->setManufacturer(getString(inputLineStream, '\n'));
   return inventory;
}

//------------------------------------------------------------------------
// Gets the inventory object based on current line stream
// @pre inputLineStream is valid
// @post returns string token separated by separator character
// @param inputLineStream The line stream
// @param separator The line stream separator
// @param returns string token separated by separator character
string InventoryFileReader::getString(stringstream& inputLineStream, char separator) {
   string strValue;
   getline(inputLineStream, strValue, separator);
   return strValue;
}

//------------------------------------------------------------------------
// Gets the inventory object based on current line stream
// @pre inputLineStream is valid
// @post returns integer token separated by separator character
// @param inputLineStream The line stream
// @param separator The line stream separator
// @param returns integer token separated by separator character
int InventoryFileReader::getInteger(stringstream& inputLineStream, char separator) {
   string strValue;
   getline(inputLineStream, strValue, separator);
   return atoi(strValue.c_str());
}