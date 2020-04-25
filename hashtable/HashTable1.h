/*
 *  HashTable1.h
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */

#ifndef HashTable1_h
#define HashTable1_h

#include "HashNode.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/****************************************************************************
 *                                                                          *
 *                    class HashTable1 (Chaining) declaration               *
 *                                                                          *
 ****************************************************************************/
class HashTable1
{
private:
    HashNode **htable; // htable is a pointer to a pointer to HashNode
    int currentCapacity;
    int elementCount;
    
public:
    HashTable1(int sz);
    ~HashTable1();

    bool isPrime(int n);
    int nextPrime(int n);
    
    unsigned int computeHash(string s) const; // hash function
    HashNode* search(HashNode *head, string &toFind) const;
    bool containsString(string toFind) const;
    void put(string s);
    
    void displayHash();
    void rehash(); // rehash when load factor = 1
};


    
#endif /* HashTable1_h */
