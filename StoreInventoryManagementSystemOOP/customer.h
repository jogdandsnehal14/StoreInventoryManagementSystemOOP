//---------------------------------------------------------------------------
// File: customer.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for Customer class
// The customer class is responsible for storing all the details of the customers 
//---------------------------------------------------------------------------

#ifndef CUSTOMER_
#define CUSTOMER_

#include <string>
#include <iostream>
#include <vector> 
#include "transaction.h"

class Customer {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new Customer object 
   // @pre none
   // @post creates a Store object
   Customer();

   //------------------------------------------------------------------------
   // The constructor that creates a new Customer object with given customer id and name
   // @pre none
   // @post creates a Customer object
   // @param storeId The Customer id
   // @param customerName The Customer name
   Customer(string customerId, string customerName);

   //------------------------------------------------------------------------
   // Returns the current customer id
   // @pre none
   // @post Returns the current customer id
   // @returns customer id
   string getCustomerId();

   //------------------------------------------------------------------------
   // Adds a transaction to the current customer object
   // @pre transaction is valid object
   // @post adds a new transaction to the current list of transactions
   // @param transaction The transaction object to be added
   void addTransaction(string transaction);

   //------------------------------------------------------------------------
   // Returns a string of the current customer details
   // @pre none
   // @post displays the current customer details
   // @returns the current customer details as string
   string toString();

   //------------------------------------------------------------------------
   // Displays the list of all transactions for the current customer
   // @pre otherCustomer should be a valid customer object
   // @post creates a deep copy of give customer object
   // @param otherCustomer The Customer object to be copied
   void display();

   //------------------------------------------------------------------------
   // Overload == operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if both are inventory objects are equal
   // @param otherInventory The otherInventory to compare with
   bool operator==(Customer& otherCustomer);

   //------------------------------------------------------------------------
   // Overload < operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is less than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator<(Customer& otherCustomer);

   //------------------------------------------------------------------------
   // Overload > operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is greater than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator>(Customer& otherCustomer);

   //------------------------------------------------------------------------
   // The Customer object destructor 
   // @pre none
   // @post the Customer object is completely deleted 
   //    with corresponding memory deallocated
   ~Customer();

private:
   //------------------------------------------------------------------------
   // The customer id
   string customerId;

   //------------------------------------------------------------------------
   // The customer name
   string customerName;

   //------------------------------------------------------------------------
   // The list of all transactions 
   vector<string> transactions;
};

#endif