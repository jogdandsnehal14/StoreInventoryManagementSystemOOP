//---------------------------------------------------------------------------
// File: sellTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for SellTransaction class
// The SellTransaction class is responsible for storing all the details of 
// sell Transaction on an inventory item.
// Derives from the base Transaction class
//---------------------------------------------------------------------------

#ifndef SELL_TRANSACTION_
#define SELL_TRANSACTION_

#include "transaction.h"
#include "store.h"

class SellTransaction : public Transaction {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new Transaction object 
   // @pre none
   // @post creates a Transaction object
   SellTransaction();

   //------------------------------------------------------------------------
   // Adds a transaction to the current customer object on given inventory
   // inventory.add or inventory.remove based on transaction type
   // @pre inventory are valid existing objects
   // @post adds a new buy transaction on given inventory
   // @param transaction The transaction object to be added
   void addTransaction(Inventory* inventory) const;

   //------------------------------------------------------------------------
   // The Sell transaction destructor 
   // @pre none
   // @post the transaction object is completely deleted 
   //    with corresponding memory deallocated
   ~SellTransaction();
};

#endif