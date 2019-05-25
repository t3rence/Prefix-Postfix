//
//  prefix.h
//  lab4
//
//  Created by Terence Ho on 11/14/16.
//
//  Assumption:
//  - Data has been formated for the file input stream
//
//  Implementation:
//  - Uses abstract data type.
//  - Maxsize is used to cap the size of the array

#ifndef PREFIX_H
#define PREFIX_H
#include <iostream>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;  // maxsize of array for operations

//-----------------------------------------------------------------------------
// header file for Prefix class
class Prefix {
    friend ostream& operator<<(ostream&, const Prefix&);

public:
    Prefix(); //default constructor
    void setPrefix(ifstream& infile); // creates array from file input
    int evaluatePrefix() const;  // find prefix symbol
    void outputAsPostfix(ostream&) const; // outputs postfix

private:
    char expr[MAXSIZE+1];   // array of symbols
    int evaluatePrefixHelper(int&) const; // helps to find prefix symbol
    void toPostfix(int&, char [], int&) const; // changes output to postfix
};

#endif

