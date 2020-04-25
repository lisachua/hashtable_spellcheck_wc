/*
 *  HashTable1.cpp
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */

#include "HashTable1.h"

/****************************************************************************
 *                                                                          *
 *                 class HashTable1 (Chaining) implementation               *
 *                                                                          *
 ****************************************************************************/

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/
HashTable1::HashTable1(int sz)
{
    int size = nextPrime(sz);
    htable = new HashNode *[size];
    for (int i = 0; i < size; i++)
    {
        htable[i] = NULL;
    }
    elementCount = 0;
    currentCapacity = size;
}

/****************************************************************************
 *                               destructor                                 *
 ****************************************************************************/
HashTable1::~HashTable1()
{
    for (int i = 0; i < currentCapacity; ++i)
    {
        HashNode *entry = htable[i];
        while (entry != NULL)
        {
            HashNode *prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] htable;
}

/****************************************************************************
 *                               isPrime                                    *
 ****************************************************************************/
bool HashTable1::isPrime (int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

/****************************************************************************
 *                             nextPrime                                    *
 ****************************************************************************/
int HashTable1::nextPrime(int n)
{
    if (n <= 0)
        n = 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime( n ); n += 2);
    return n;
}

/****************************************************************************
 *                               computeHash                                *
 ****************************************************************************/
unsigned int HashTable1::computeHash(string s) const
{
    unsigned int hash = 0;
    for (unsigned int i = 0; i < s.length( ); i++)
    {
        hash += s[i]; //sum ASCII values for each character in word
    }
    return hash % currentCapacity;
}

/****************************************************************************
 *                               search                                     *
 ****************************************************************************/
HashNode* HashTable1::search( HashNode *head, string &toFind) const
{
    HashNode* here = head;
    
    if (here == NULL) //if empty list
    {
        return NULL;
    }
    else
    {
        while (here->info != toFind && here->next != NULL)
            here = here->next;
        
        if (here->info == toFind)
            return here;
        else
            return NULL;
    }
}

/****************************************************************************
 *                               put                                        *
 ****************************************************************************/
void HashTable1::put(string s)
{
    //cout << "in PUT... " << endl;
    int hash = computeHash(s);
    if (search(htable[hash], s) == NULL) // only add word if it's not already in the list
    {
        if (htable[hash] == NULL) // bucket is empty
        {
            htable[hash] = new HashNode(s);
        }
        else { // not empty
            HashNode *current = htable[hash];
            
            while (current->next != NULL) // traverse to end of LL
            {
                current = current->next;
            }
                current->next = new HashNode(s); // insert HashNode
        } // END else bucket not empty
    }
    
    elementCount++;
    
    // Rehash if at load factor 1
    if( elementCount > currentCapacity)
    {
        cout << "array is full, calling rehash" << endl;
        rehash( );
    }
}

/****************************************************************************
 *                            containsString                                *
 ****************************************************************************/
bool HashTable1::containsString(string toFind) const
{
    int hash = this->computeHash(toFind);
    HashNode* result = search(htable[hash], toFind);
    if (result == NULL)
        return false;
    else
        return true;
}

void HashTable1::displayHash() {
    for (int i = 0; i < currentCapacity; i++) {
        cout << i;
        HashNode *current = htable[i];
        while (current != NULL)
        {
            cout << " --> " << current->info;
            current = current->next;
        }
        cout << endl;
    }
}

/****************************************************************************
 *                                rehash                                    *
 ****************************************************************************/
void HashTable1::rehash( )  //when load factor = 1.0
{
    HashNode **oldhtable = htable;

    // Create new double-sized, empty table
    int newCapacity = 2 * currentCapacity;
    htable = new HashNode *[newCapacity];
    for (int i = 0; i < newCapacity; i++)
    {
        htable[i] = NULL;
    }
    
    // update counts and capacity
    elementCount = 0;
    int oldCapacity = currentCapacity;
    currentCapacity = newCapacity;
    
    // Copy elements over from old htable
    for (int i = 0; i < oldCapacity; i++) {
        HashNode *current = oldhtable[i];
        while (current != NULL)
        {
            put(current->info);
            current = current->next;
        } // END while loop
    } // END for loop

    //cout << "new array size: " << currentCapacity << endl;
    
    delete[] oldhtable;
}
