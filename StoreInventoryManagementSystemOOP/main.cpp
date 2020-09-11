//---------------------------------------------------------------------------
// File: Graph.h
// Author: Snehal Jogdand
// Date: 02/26/2020
// Program 4: Object-oriented design
//
// DESCRIPTION:
// Driver code for testing the store class
// This code tests the basic functionality of the Store class to
// perform Collectibles store simulation for CSS 502 Program 4.
// It is not meant to exhaustively test the class.
//
// Assumptions:
//   -- a text files provided exists in the same directory
//      as the code and is formatted as described in the specifications
//---------------------------------------------------------------------------

#include <fstream>
#include "store.h"

using namespace std;

//-------------------------- main -------------------------------------------
// Tests the Store class by reading data from provided text files
// Preconditions:   If the given txt file exists, it must be formatted
//                  as described in the lab Store.
// Postconditions:  The basic functionalities of the Store class 
//                  are used. Should compile, run to completion, and output  
//                  correct answers if the classes are implemented correctly.
int main() {
   Store* store = new Store();

   ifstream customers;
   ifstream collectibles;
   ifstream commands;

   try {
      customers.open("hw4customers.txt");
   }
   catch (std::ios_base::failure &e) {
      cerr << e.code().message() << std::endl;
      return -1;
   }

   try {
      collectibles.open("hw4inventory.txt");
   }
   catch (std::ios_base::failure & e) {
      cerr << e.code().message() << std::endl;
      return -1;
   }

   try {
      commands.open("hw4commands.txt");
   }
   catch (std::ios_base::failure & e) {
      cerr << e.code().message() << std::endl;
      return -1;
   }

   store->readCustomers(customers);
   store->readInventory(collectibles);
   store->readCommands(commands);
}