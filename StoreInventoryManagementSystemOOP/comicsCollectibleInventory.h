//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for inventory class
// The inventory class is responsible for storing all the details of the comics inventory 
//---------------------------------------------------------------------------

#ifndef COMICS_COLLECTIBLE_INVENTORY_
#define COMICS_COLLECTIBLE_INVENTORY_

#include "collectibleInventory.h"
#include <string>

using namespace std;

class ComicsCollectibleInventory : public CollectibleInventory {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new SportCardsCollectibleInventory object 
   // @pre none
   // @post creates a Inventory object
   ComicsCollectibleInventory();

   //------------------------------------------------------------------------
   // The copy constructor that deep copies the provided Inventory object
   // @pre otherInventory should be a valid Inventory object
   // @post creates a deep copy of give Inventory object
   // @param otherInventory The Inventory object to be copied
   ComicsCollectibleInventory(const ComicsCollectibleInventory& otherInventory);

   //------------------------------------------------------------------------
   // Sets the comics title details
   // @pre valid input params
   // @post Sets the comics title details
   // @param title The title details
   void setTitle(string title);

   //------------------------------------------------------------------------
   // Sets the comics publisher details
   // @pre valid input params
   // @post Sets the comics publisher details
   // @param publisher The publisher details
   void setPublisher(string publisher);

   //------------------------------------------------------------------------
   // Sets the comics grade details
   // @pre valid input params
   // @post Sets the comics grade details
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
   bool operator<(Inventory& otherInventory);

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
   ~ComicsCollectibleInventory();

private:
   //------------------------------------------------------------------------
   // The Inventory title 
   string title;

   //------------------------------------------------------------------------
   // The Inventory publisher 
   string publisher;

   //------------------------------------------------------------------------
   // The Inventory grade 
   string grade;
};

#endif