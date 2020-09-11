//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for inventory class
// The inventory class is responsible for storing all the details of the coins inventory 
//---------------------------------------------------------------------------
#include "coinsCollectibleInventory.h"

//------------------------------------------------------------------------
// The default constructor that creates a new CoinsCollectibleInventory object 
// @pre none
// @post creates a Inventory object
CoinsCollectibleInventory::CoinsCollectibleInventory() : grade(0) {
}

//------------------------------------------------------------------------
// The copy constructor that deep copies the provided Inventory object
// @pre otherInventory should be a valid Inventory object
// @post creates a deep copy of give Inventory object
// @param otherInventory The Inventory object to be copied
CoinsCollectibleInventory::CoinsCollectibleInventory(const CoinsCollectibleInventory& otherInventory) {
   setId(otherInventory.getId());
   setSize(otherInventory.getSize());
   setYear(otherInventory.getYear());
   setGrade(otherInventory.grade);
   setType(otherInventory.type);
}

//------------------------------------------------------------------------
// Sets the sport card grade details
// @pre valid input params
// @post Sets the sport cards grade details
// @param grade The grade details
void CoinsCollectibleInventory::setGrade(int grade) {
   this->grade = grade;
}

//------------------------------------------------------------------------
// Sets the inventory type details
// @pre valid input params
// @post Sets the inventory type details
// @param type The inventory type details
void CoinsCollectibleInventory::setType(string type) {
   this->type = type;
}

//------------------------------------------------------------------------
// Returns a string of the current inventory details
// @pre none
// @post displays the current inventory details
// @returns the current inventory details as string
string CoinsCollectibleInventory::toString() const {
   return getId() + ", " + to_string(getSize()) + ", " + to_string(getYear()) + ", " + to_string(grade) + ", " + type + "\n";
}

//------------------------------------------------------------------------
// Displays the current inventory details
// @pre none
// @post displays the current inventory details
void CoinsCollectibleInventory::display() {
   cout << toString();
}

//------------------------------------------------------------------------
// Overload == operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if both are inventory objects are equal
// @param otherInventory The otherInventory to compare with
bool CoinsCollectibleInventory::operator==(Inventory& otherInventory) {
   CoinsCollectibleInventory* coinsInventory = static_cast<CoinsCollectibleInventory*>(&otherInventory);
   return type.compare(coinsInventory->type) == 0
      && getYear() == coinsInventory->getYear()
      && grade == coinsInventory->grade;
}

//------------------------------------------------------------------------
// Overload < operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is less than input inventory
// @param otherInventory The otherInventory to compare with
bool CoinsCollectibleInventory::operator<(Inventory& otherInventory) {
   CoinsCollectibleInventory* coinsInventory = static_cast<CoinsCollectibleInventory*>(&otherInventory);
   if (type.compare(coinsInventory->type) != 0) return type.compare(coinsInventory->type) < 0;
   else if (getYear() == coinsInventory->getYear() != 0) return getYear() < coinsInventory->getYear();
   return grade < coinsInventory->grade;
}

//------------------------------------------------------------------------
// Overload > operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is greater than input inventory
// @param otherInventory The otherInventory to compare with
bool CoinsCollectibleInventory::operator>(Inventory& otherInventory) {
   CoinsCollectibleInventory* coinsInventory = static_cast<CoinsCollectibleInventory*>(&otherInventory);
   if (type.compare(coinsInventory->type) != 0) return type.compare(coinsInventory->type) > 0;
   else if (getYear() == coinsInventory->getYear() != 0) return getYear() > coinsInventory->getYear();
   return grade > coinsInventory->grade;
}

//------------------------------------------------------------------------
// The CoinsCollectibleInventory destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the Inventory object is completely deleted 
//    with corresponding memory deallocated
CoinsCollectibleInventory::~CoinsCollectibleInventory() {
}