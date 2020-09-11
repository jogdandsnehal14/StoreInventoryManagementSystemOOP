//---------------------------------------------------------------------------
// File: commandFileReader.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for CommandFileReader class
// The CommandFileReader class is responsible for processing the commands
//---------------------------------------------------------------------------

#ifndef COMMAND_FILE_READER_
#define COMMAND_FILE_READER_

#include <iostream>
#include <string>
#include "sellTransaction.h"
#include "buyTransaction.h"
#include "inventoryFileReader.h"

using namespace std;

class CommandFileReader {
public:
   //------------------------------------------------------------------------
   // Executes the command on the store pointer object
   // @pre input line stream is valid and store object is valid
   // @post returns the hash of the given item id
   // @param inputLineStream The line stream
   // @param store The store object
   static void executeCommand(stringstream& inputLineStream, Store* store);
private:
};

#endif