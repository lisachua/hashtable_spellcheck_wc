/*
 *  HashTable2.h
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */

#ifndef HashTable2_h
#define HashTable2_h

#include <string>
#include <iostream>
//#include <iomanip>
//#include <exception>
//#include <stdexcept>
//#include <sstream>

using std::cout;
using std::endl;
using std::string;


/****************************************************************************
 *                                                                          *
 *               class HashTable2 (Quadratic Probing) declaration           *
 *                                                                          *
 ****************************************************************************/
class HashTable2
{
private:
    
    enum EntryType { ACTIVE, EMPTY };
    struct HashElement
    {
        string element;
        enum EntryType status;
    };
    
    //HashElement htable[DEFAULTSIZE];
    HashElement *htable;
    int currentCapacity;
    int elementCount;
    
public:
    HashTable2(int sz);
    //~HashTable2();
    
    bool isPrime(int n);
    int nextPrime(int n);
    
    int computeHash(string s) const; // **int hashFunction
    int quadraticProbing(string s) const;
    
    void put(string s);
    bool containsString(string toFind) const; // **int search
    
    void displayHash(); // ** display
    void rehash(); // rehash when load factor = 1?
    
    
};


#endif /* HashTable2_h */
