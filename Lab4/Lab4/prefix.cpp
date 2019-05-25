//
//  prefix.cpp
//  lab4
//
//  Created by Terence Ho on 11/14/16.
//
//  Evaluates a prefix expression and to converts a prefix expression
//  into a postfix using recursion.
//
//  Assumption:
//  - Each expression is a valid prefix expression where the operands consist
//    of one digit
//  - Operators are either + ,‐ , *, /
//
//  Implementation:
//  - Uses expr[] array to keep track of symbols
//  - Recursion is used in evaluatePrefixHelper and toPostFix for finding the
//    symbol and inserting the symbol at the end for postFix.
//

#include "prefix.h"

//-----------------------------------------------------------------------------
// constructor
// initialize the array to the empty string,
// char arrays are terminated with '\0' so operator<< works properly

Prefix::Prefix() {
   expr[0] = '\0'; 
} 

//-----------------------------------------------------------------------------
// setPrefix
// Set a prefix expression made of single digit operands, operators +,-,*,/
// and no blanks or tabs contained in a file. The expression is valid in
// that each valid operator has two valid operands.

void Prefix::setPrefix(ifstream& infile) { 
    infile >> expr;
}

//-----------------------------------------------------------------------------
// evaluatePrefix 
// Evaluate a prefix expr made of single digit operands and operators +,-,*,/
// Return the answer (integer arithmetic).

int Prefix::evaluatePrefix() const {
    if (expr[0] == '\0') 
        return 0;

    int index = -1;                               // to walk through expr
    return evaluatePrefixHelper(index);
}

int Prefix::evaluatePrefixHelper(int& index) const {
    char symbol = expr[++index];
    
    // check if symbol is a digit
    if(isdigit(symbol)) {
        // return the symbol by changing it from char using i-'0'
        return symbol-'0';
    } else if (symbol == '-') {
        // recurse with operator-
        return evaluatePrefixHelper(index) - evaluatePrefixHelper(index);
    } else if (symbol == '+') {
        // recurse with operator+
        return evaluatePrefixHelper(index) + evaluatePrefixHelper(index);
    } else if (symbol == '/') {
        // recurse with operator/
        return evaluatePrefixHelper(index) / evaluatePrefixHelper(index);
    } else if (symbol == '*') {
        // recurse with operator*
        return evaluatePrefixHelper(index) * evaluatePrefixHelper(index);
    } else {
        // all other cases return 0
        return 0;
    }
}

//-----------------------------------------------------------------------------
// outputAsPostfix, toPostfix
// Convert prefix expression to postfix and output

void Prefix::outputAsPostfix(ostream& out) const {
    if (expr[0] == '\0') 
        return;

    int index = -1;                           // to walk through expr
    int count = -1;                           // used to build postfix array
    char postfix[MAXSIZE+1];                  // holds postfix expression
    toPostfix(index, postfix, count);
    postfix[++count] = '\0';
    out << postfix;
}

void Prefix::toPostfix(int& index, char postfix[], int& count) const {
    char symbol = expr[++index];
    
    // check if symbol is a digit
    if(isdigit(symbol)) {
        
        // add expression symbol to postFix array
        postfix[++count] = symbol;
    } else {
        
        // recurse through the input array
        toPostfix(index, postfix,count);
        toPostfix(index, postfix,count);

        // add expression symbol to postFix array
        postfix[++count] = symbol;
    }
}

//-----------------------------------------------------------------------------
// operator<<
// display prefix expression as a string (char array)

ostream& operator<<(ostream& output, const Prefix& expression) {
    output << expression.expr;
    return output;
}

