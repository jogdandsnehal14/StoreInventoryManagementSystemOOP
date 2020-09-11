//---------------------------------------------------------------------------
// File: transaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for Transaction class
// The Transaction class is responsible for storing all the details of a Transaction on an inventory item.
//---------------------------------------------------------------------------

#include "transaction.h"

//------------------------------------------------------------------------
// The default constructor that creates a new Transaction object 
// @pre none
// @post creates a Transaction object
Transaction::Transaction() : transactionId("Z"), inventory(nullptr) {
}

//------------------------------------------------------------------------
// The Store transaction destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the transaction object is completely deleted 
//    with corresponding memory deallocated
Transaction::~Transaction() {
}