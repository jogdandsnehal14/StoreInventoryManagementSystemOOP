//---------------------------------------------------------------------------
// File: inventoryFileReader.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for InventoryFileReader class
// The InventoryFileReader class is responsible for processing the inventory from file stream
//---------------------------------------------------------------------------

#ifndef INVENTORY_FILE_READER_
#define INVENTORY_FILE_READER_

#include <fstream>
#include <iostream>
#include "comicsCollectibleInventory.h"
#include "coinsCollectibleInventory.h"
#include "sportCardsCollectibleInventory.h"

using namespace std;

class InventoryFileReader {
public:
   //------------------------------------------------------------------------
   // Gets the inventory object based on current line stream
   // @pre none
   // @post returns inventory object if valid line stream
   // @param lineStream The line stream
   // @param returns new inventory object
   static Inventory* getInventoryObject(stringstream& lineStream);

   //------------------------------------------------------------------------
   // Gets the inventory object based on inventory type
   // @pre none
   // @post returns inventory object if valid line stream
   // @param inventoryType The inventory Type
   // @param inputLineStream The line stream
   // @param returns new inventory object
   static Inventory* getInventoryObject(char inventoryType, stringstream& inputLineStream);

   //------------------------------------------------------------------------
   // Gets the Comics inventory object based on current line stream
   // @pre none
   // @post returns inventory object if valid line stream
   // @param inputLineStream The line stream
   // @param returns new inventory object
   static Inventory* getComicsInventoryObject(stringstream& inputLineStream);

   //------------------------------------------------------------------------
   // Gets the coins inventory object based on current line stream
   // @pre none
   // @post returns inventory object if valid line stream
   // @param inputLineStream The line stream
   // @param returns new inventory object
   static Inventory* getCoinsInventoryObject(stringstream& inputLineStream);

   //------------------------------------------------------------------------
   // Gets the SportCard inventory object based on current line stream
   // @pre none
   // @post returns inventory object if valid line stream
   // @param inputLineStream The line stream
   // @param returns new inventory object
   static Inventory* getSportCardsInventoryObject(stringstream& inputLineStream);

   //------------------------------------------------------------------------
   // Gets the inventory object based on current line stream
   // @pre inputLineStream is valid
   // @post returns string token separated by separator character
   // @param inputLineStream The line stream
   // @param separator The line stream separator
   // @param returns string token separated by separator character
   static string getString(stringstream& inputLineStream, char separator);

   //------------------------------------------------------------------------
   // Gets the inventory object based on current line stream
   // @pre inputLineStream is valid
   // @post returns integer token separated by separator character
   // @param inputLineStream The line stream
   // @param separator The line stream separator
   // @param returns integer token separated by separator character
   static int getInteger(stringstream& inputLineStream, char separator);
};

#endif