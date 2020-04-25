/*
 *  HashNode.h
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */

#ifndef HashNode_h
#define HashNode_h

#include <string>
#include <iostream>
using std::string;

/****************************************************************************
 *                                                                          *
 *                       class HashNode declaration                         *
 *                                                                          *
 ****************************************************************************/
class HashNode
{
public:
    //int key;
    string info;
    HashNode *next;

    HashNode(/*int key,*/ string s)
    {
        //this->key = key;
        this->info = s;
        this->next = NULL;
    }
    
}; //END declaration of class HashNode

/***************************************************************************
 **                                                                        **
 **                        class HashNode implementation                   **
 **                                                                        **
 ***************************************************************************/

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

/*
template <typename T>
HashNode<T>::HashNode(int key, int value)
{
    this->key = key;
    this->value = value;
    this->next = NULL;
}

*/
#endif /* HashNode_h */
