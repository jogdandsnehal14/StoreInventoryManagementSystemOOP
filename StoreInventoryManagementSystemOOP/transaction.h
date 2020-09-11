//---------------------------------------------------------------------------
// File: transaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for Transaction class
// The Transaction class is responsible for storing all the details of a Transaction on an inventory item.
//---------------------------------------------------------------------------

#ifndef TRANSACTION_
#define TRANSACTION_

#include "inventory.h"

class Transaction {
public:
   //------------------------------------------------------------------------
   // The transaction id
   string transactionId;
   
   //------------------------------------------------------------------------
   // The default constructor that creates a new Transaction object 
   // @pre none
   // @post creates a Transaction object
   Transaction();

   //------------------------------------------------------------------------
   // Adds a transaction to the current customer object on given inventory
   // inventory.add or inventory.remove based on transaction type
   // @pre inventory are valid existing objects
   // @post adds a new buy transaction on given inventory
   // @param transaction The transaction object to be added
   virtual void addTransaction(Inventory* inventory) const = 0;

   //------------------------------------------------------------------------
   // The Store transaction destructor 
   // virtual funtion to allow being overriden by the derived class
   // @pre none
   // @post the transaction object is completely deleted 
   //    with corresponding memory deallocated
   virtual ~Transaction() = 0;

private:
   //------------------------------------------------------------------------
   // The inventory object pointer
   Inventory* inventory;
};

#endif