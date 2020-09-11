//---------------------------------------------------------------------------
// File: sportCardsCollectibleInventory.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for inventory class
// The inventory class is responsible for storing all the details of the sports cards inventory 
//---------------------------------------------------------------------------

#include "sportCardsCollectibleInventory.h"

//------------------------------------------------------------------------
// The default constructor that creates a new SportCardsCollectibleInventory object 
// @pre none
// @post creates a Inventory object
SportCardsCollectibleInventory::SportCardsCollectibleInventory() {
}

//------------------------------------------------------------------------
// The copy constructor that deep copies the provided Inventory object
// @pre otherInventory should be a valid Inventory object
// @post creates a deep copy of give Inventory object
// @param otherInventory The Inventory object to be copied
SportCardsCollectibleInventory::SportCardsCollectibleInventory(const SportCardsCollectibleInventory& otherInventory) {
   setId(otherInventory.getId());
   setSize(otherInventory.getSize());
   setYear(otherInventory.getYear());
   setPlayer(otherInventory.player);
   setGrade(otherInventory.grade);
   setManufacturer(otherInventory.manufacturer);
}

//------------------------------------------------------------------------
// Sets the sport cards details
// @pre valid input params
// @post Sets the sport cards details
// @param player The player details
void SportCardsCollectibleInventory::setPlayer(string player) {
   this->player = player;
}

//------------------------------------------------------------------------
// Sets the sport cards details
// @pre valid input params
// @post Sets the sport cards details
// @param manufacturer The manufacturer details
void SportCardsCollectibleInventory::setManufacturer(string manufacturer) {
   this->manufacturer = manufacturer;
}
//------------------------------------------------------------------------
// Sets the sport cards grade details
// @pre valid input params
// @post Sets the sport cards grade details
// @param grade The grade details
void SportCardsCollectibleInventory::setGrade(string grade) {
   this->grade = grade;
}

//------------------------------------------------------------------------
// Returns a string of the current inventory details
// @pre none
// @post displays the current inventory details
// @returns the current inventory details as string
string SportCardsCollectibleInventory::toString() const {
   return getId() + ", " + to_string(getSize()) + ", " + to_string(getYear()) + ", " + grade + ", " + player + ", " + manufacturer + "\n";
}

//------------------------------------------------------------------------
// Displays the current inventory details
// @pre none
// @post displays the current inventory details
void SportCardsCollectibleInventory::display() {
   cout << toString();
}

//------------------------------------------------------------------------
// Overload == operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if both are inventory objects are equal
// @param otherInventory The otherInventory to compare with
bool SportCardsCollectibleInventory::operator==(Inventory& otherInventory) {
   SportCardsCollectibleInventory* sportsInventory = static_cast<SportCardsCollectibleInventory*>(&otherInventory);
   return player.compare(sportsInventory->player) == 0
      && getYear() == sportsInventory->getYear()
      && manufacturer.compare(sportsInventory->manufacturer) == 0
      && grade == sportsInventory->grade;
}

//------------------------------------------------------------------------
// Overload < operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is less than input inventory
// @param otherInventory The otherInventory to compare with
bool SportCardsCollectibleInventory::operator<(Inventory& otherInventory) {
   SportCardsCollectibleInventory* sportsInventory = static_cast<SportCardsCollectibleInventory*>(&otherInventory);
   if (player.compare(sportsInventory->player) != 0) return player.compare(sportsInventory->player) < 0;
   else if (getYear() == sportsInventory->getYear() != 0) return getYear() < sportsInventory->getYear();
   else if (manufacturer.compare(sportsInventory->manufacturer) != 0) return manufacturer.compare(sportsInventory->manufacturer) < 0;
   return grade < sportsInventory->grade;
}

//------------------------------------------------------------------------
// Overload > operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is greater than input inventory
// @param otherInventory The otherInventory to compare with
bool SportCardsCollectibleInventory::operator>(Inventory& otherInventory) {
   SportCardsCollectibleInventory* sportsInventory = static_cast<SportCardsCollectibleInventory*>(&otherInventory);
   if (player.compare(sportsInventory->player) != 0) return player.compare(sportsInventory->player) > 0;
   else if (getYear() == sportsInventory->getYear() != 0) return getYear() > sportsInventory->getYear();
   else if (manufacturer.compare(sportsInventory->manufacturer) != 0) return manufacturer.compare(sportsInventory->manufacturer) > 0;
   return grade > sportsInventory->grade;
}

//------------------------------------------------------------------------
// The SportCardsCollectibleInventory destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the Inventory object is completely deleted 
//    with corresponding memory deallocated
SportCardsCollectibleInventory::~SportCardsCollectibleInventory() {
}
