//---------------------------------------------------------------------------
// File: sportCardsCollectibleInventory.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for inventory class
// The inventory class is responsible for storing all the details of the sports cards inventory 
//---------------------------------------------------------------------------

#ifndef SPORT_CARDS_COLLECTIBLE_INVENTORY_
#define SPORT_CARDS_COLLECTIBLE_INVENTORY_

#include "collectibleInventory.h"
#include <string>

using namespace std;

class SportCardsCollectibleInventory : public CollectibleInventory {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new SportCardsCollectibleInventory object 
   // @pre none
   // @post creates a Inventory object
   SportCardsCollectibleInventory();

   //------------------------------------------------------------------------
   // The copy constructor that deep copies the provided Inventory object
   // @pre otherInventory should be a valid Inventory object
   // @post creates a deep copy of give Inventory object
   // @param otherInventory The Inventory object to be copied
   SportCardsCollectibleInventory(const SportCardsCollectibleInventory& otherInventory);

   //------------------------------------------------------------------------
   // Sets the sport cards details
   // @pre valid input params
   // @post Sets the sport cards details
   // @param player The player details
   void setPlayer(string player);

   //------------------------------------------------------------------------
   // Sets the sport cards details
   // @pre valid input params
   // @post Sets the sport cards details
   // @param manufacturer The manufacturer details
   void setManufacturer(string manufacturer);

   //------------------------------------------------------------------------
   // Sets the sport cards grade details
   // @pre valid input params
   // @post Sets the sport cards grade details
   // @param grade The grade details
   void setGrade(string grade);

   //------------------------------------------------------------------------
   // Returns a string of the current inventory details
   // @pre none
   // @post displays the current inventory details
   // @returns the current inventory details as string
   string toString() const;

   //------------------------------------------------------------------------
   // Displays the current inventory details
   // @pre none
   // @post displays the current inventory details
   void display();

   //------------------------------------------------------------------------
   // Overload == operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if both are inventory objects are equal
   // @param otherInventory The otherInventory to compare with
   bool operator==(Inventory& otherInventory);

   //------------------------------------------------------------------------
   // Overload < operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is less than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator<( Inventory& otherInventory);

   //------------------------------------------------------------------------
   // Overload > operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is greater than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator>(Inventory& otherInventory);

   //------------------------------------------------------------------------
   // The SportCardsCollectibleInventory destructor 
   // virtual funtion to allow being overriden by the derived class
   // @pre none
   // @post the Inventory object is completely deleted 
   //    with corresponding memory deallocated
   ~SportCardsCollectibleInventory();

private:
   //------------------------------------------------------------------------
   // The Inventory player 
   string player;

   //------------------------------------------------------------------------
   // The Inventory manufacturer 
   string manufacturer;

   //------------------------------------------------------------------------
   // The Inventory grade 
   string grade;
};

#endif