//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for inventory class
// The inventory class is responsible for storing all the details of the comics inventory 
//---------------------------------------------------------------------------

#include "comicsCollectibleInventory.h"

//------------------------------------------------------------------------
// The default constructor that creates a new SportCardsCollectibleInventory object 
// @pre none
// @post creates a Inventory object
ComicsCollectibleInventory::ComicsCollectibleInventory() {
}


//------------------------------------------------------------------------
// The copy constructor that deep copies the provided Inventory object
// @pre otherInventory should be a valid Inventory object
// @post creates a deep copy of give Inventory object
// @param otherInventory The Inventory object to be copied
ComicsCollectibleInventory::ComicsCollectibleInventory(const ComicsCollectibleInventory& otherInventory) {
   setId(otherInventory.getId());
   setSize(otherInventory.getSize());
   setYear(otherInventory.getYear());
   setPublisher(otherInventory.publisher);
   setGrade(otherInventory.grade);
   setTitle(otherInventory.title);
}

//------------------------------------------------------------------------
// Sets the comics title details
// @pre valid input params
// @post Sets the comics title details
// @param title The title details
void ComicsCollectibleInventory::setTitle(string title) {
   this->title = title;
}

//------------------------------------------------------------------------
// Sets the comics publisher details
// @pre valid input params
// @post Sets the comics publisher details
// @param publisher The publisher details
void ComicsCollectibleInventory::setPublisher(string publisher) {
   this->publisher = publisher;
}

//------------------------------------------------------------------------
// Sets the comics grade details
// @pre valid input params
// @post Sets the comics grade details
// @param grade The grade details
void ComicsCollectibleInventory::setGrade(string grade) {
   this->grade = grade;
}

//------------------------------------------------------------------------
// Returns a string of the current inventory details
// @pre none
// @post displays the current inventory details
// @returns the current inventory details as string
string ComicsCollectibleInventory::toString() const {
   return getId() + ", " + to_string(getSize()) + ", " + to_string(getYear()) + ", " + grade + ", " + title + ", " + publisher + "\n";;
}

//------------------------------------------------------------------------
// Returns a string of the current inventory details
// @pre none
// @post displays the current inventory details
// @returns the current inventory details as string
void ComicsCollectibleInventory::display() {
   cout << toString();
}

//------------------------------------------------------------------------
// Overload == operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if both are inventory objects are equal
// @param otherInventory The otherInventory to compare with
bool ComicsCollectibleInventory::operator==(Inventory& otherInventory) {
   ComicsCollectibleInventory* comicsInventory = static_cast<ComicsCollectibleInventory*>(&otherInventory);
   return publisher.compare(comicsInventory->publisher) == 0
      && title.compare(comicsInventory->title) == 0
      && getYear() == comicsInventory->getYear()
      && grade == comicsInventory->grade;
}

//------------------------------------------------------------------------
// Overload < operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is less than input inventory
// @param otherInventory The otherInventory to compare with
bool ComicsCollectibleInventory::operator<(Inventory& otherInventory) {
   ComicsCollectibleInventory* comicsInventory = static_cast<ComicsCollectibleInventory*>(&otherInventory);
   if (publisher.compare(comicsInventory->publisher) != 0) return publisher.compare(comicsInventory->publisher) < 0;
   else if (title.compare(comicsInventory->title) != 0) return title.compare(comicsInventory->title) < 0;
   else if (getYear() == comicsInventory->getYear() != 0) return getYear() < comicsInventory->getYear();
   return grade < comicsInventory->grade;
}

//------------------------------------------------------------------------
// Overload > operator to check object comparison.
// @pre The otherInventory is a valid inventory object
// @post returns true if inventory is greater than input inventory
// @param otherInventory The otherInventory to compare with
bool ComicsCollectibleInventory::operator>(Inventory& otherInventory) {
   ComicsCollectibleInventory* comicsInventory = static_cast<ComicsCollectibleInventory*>(&otherInventory);
   if (publisher.compare(comicsInventory->publisher) != 0) return publisher.compare(comicsInventory->publisher) > 0;
   else if (title.compare(comicsInventory->title) != 0) return title.compare(comicsInventory->title) > 0;
   else if (getYear() == comicsInventory->getYear() != 0) return getYear() > comicsInventory->getYear();
   return grade > comicsInventory->grade;
}

//------------------------------------------------------------------------
// The SportCardsCollectibleInventory destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the Inventory object is completely deleted 
//    with corresponding memory deallocated
ComicsCollectibleInventory::~ComicsCollectibleInventory() {
}