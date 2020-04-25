/*
 *  HashTable2.cpp
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */
#include "HashTable2.h"

/****************************************************************************
 *                                                                          *
 *             class HashTable2 (Quadratic Probing) implementation          *
 *                                                                          *
 ****************************************************************************/

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/
HashTable2::HashTable2(int sz)
{
    int size = nextPrime(sz * 2);
    htable = new HashElement[size];
    
    for(int i=0; i < size; i++){
       htable[i].status = EMPTY;
    }
    elementCount = 0;
    currentCapacity = size;
}

/****************************************************************************
 *                               isPrime                                    *
 ****************************************************************************/
bool HashTable2::isPrime (int n)
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
int HashTable2::nextPrime(int n)
{
    if (n <= 0)
        n = 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime( n ); n += 2);
    return n;
}

/****************************************************************************
 *                             rehash                                       *
 ****************************************************************************/
void HashTable2::rehash( )  //when load factor = 0.5
{
    //cout << "in rehash... " << endl;
    HashElement *oldhtable = htable;
    
    // Create new double-sized, empty table
    int newCapacity = nextPrime(2 * currentCapacity);
    htable = new HashElement[newCapacity];
    for(int i=0; i < newCapacity; i++){
        htable[i].status = EMPTY;
    }
    
    // Copy elements over from old htable
    elementCount = 0;
    int oldCapacity = currentCapacity;
    currentCapacity = newCapacity;
    
    for(int i=0; i < oldCapacity; i++){
        if (oldhtable[i].status == ACTIVE)
            put(oldhtable[i].element);
        
    }
    
    //cout << "new array size: " << currentCapacity << endl;
}

/****************************************************************************
 *                               computeHash                                *
 ****************************************************************************/
int HashTable2::computeHash(string s) const
{
    unsigned int hash = 0;
    for (unsigned int i = 0; i < s.length( ); i++)
    {
        hash += s[i]; //sum ASCII values for each character in word
    }
    return hash % currentCapacity;
}

/****************************************************************************
 *                          quadraticProbing                                *
 ****************************************************************************/
int HashTable2::quadraticProbing(string s) const
{
    int offset = 1;
    int currentPos = computeHash(s);  // initial index is calculated from hash function
    
    // if collision occurs
    while( htable[currentPos].status != EMPTY && htable[currentPos].element != s )
    {
        currentPos += offset;  // Compute ith probe
        offset += 2;
        if( currentPos >= currentCapacity )
            currentPos -= currentCapacity;
    }
    
    return currentPos;
}

/****************************************************************************
 *                                   put                                     *
 ****************************************************************************/
void HashTable2::put(string s)
{
    // find index to insert into
    int currentPos = quadraticProbing(s);
    if( htable[currentPos].status == ACTIVE ) // duplicate already in table, do nothing
        return;
    
    // insert string at that index, update status and elementCount
    htable[currentPos].element = s;
    htable[currentPos].status = ACTIVE;
    elementCount++;
    
    // Rehash if at load factor 0.5
    if( elementCount > currentCapacity/2)
    {
        cout << "array is full, calling rehash" << endl;
        rehash( );
    }
    
}

/****************************************************************************
 *                            containsString                                *
 ****************************************************************************/
bool HashTable2::containsString(string toFind) const
{
    if (htable[quadraticProbing(toFind)].status == ACTIVE)
        return true;
    else
        return false;
}

/****************************************************************************
 *                            displayHash                                   *
 ****************************************************************************/
void HashTable2::displayHash(){
    for (int i = 0; i < currentCapacity; i++){
        cout<<"\n"<<i<<" = "<<htable[i].element;
    }
    cout<<"\nThe number of elements in the Table is : " <<this->elementCount;
}

