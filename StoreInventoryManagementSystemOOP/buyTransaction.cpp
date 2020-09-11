//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for BuyTransaction class
// The BuyTransaction class is responsible for storing all the details of 
// buy Transaction on an inventory item.
// Derives from the base Transaction class
//---------------------------------------------------------------------------

#include "buyTransaction.h"

//------------------------------------------------------------------------
// The default constructor that creates a new Transaction object 
// @pre none
// @post creates a Transaction object
BuyTransaction::BuyTransaction() {
   transactionId = "B";
}

//------------------------------------------------------------------------
// Adds a transaction to the current customer object on given inventory
// inventory.add or inventory.remove based on transaction type
// @pre inventory are valid existing objects
// @post adds a new buy transaction on given inventory
// @param transaction The transaction object to be added
void BuyTransaction::addTransaction(Inventory* inventory) const {
   inventory->setSize(inventory->getSize() + 1);
}

//------------------------------------------------------------------------
// The Buy transaction destructor 
// @pre none
// @post the transaction object is completely deleted 
//    with corresponding memory deallocated
BuyTransaction::~BuyTransaction() {
}