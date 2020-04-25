/*
 *  main.cpp
 *
 *  COSC160 Spring 2019
 *  Project #3
 *
 *  Due on: April 30, 2019
 *  Author: lc1116
 *
 *
 */

#include <iostream>
#include "main.h"

int main(int argc, const char * argv[]) {
    try
    {
        // throw exception if less than two command line arguments
        if (argc < 3)
            throw std::invalid_argument( "Must have at least one command line argument\n");
        
        string dictFileName = argv[1];
        
        // read in dictionary file
        std::fstream inFile(dictFileName);
        
        // check if inFile opened
        if (!inFile)
            throw std::invalid_argument("failed to open lexicon file, check filename and path:\n");
        
        // count number of words in dictionary file
        string input;
        int count = 0;
        
        while (inFile >> input )
        {
            count++;
        } // END while loop
        
        // instantiate h1 and h2
        HashTable1 h1(count);
        HashTable2 h2(count);
        
        // read in dictionary file again
        std::fstream inFile2(dictFileName);
        
        // check if inFile2 opened
        if (!inFile2)
            throw std::invalid_argument("failed to open lexicon file, check filename and path:\n");
        
        // store dictionary into h1 and h2
        while (inFile2 >> input )
        {
            string toInsert;
            for (unsigned int i = 0 ; i < input.length(); i++)
            {
                if (!ispunct(input[i])) // take out punctuation
                    toInsert += tolower(input[i]); // lower case
            }
            h1.put(toInsert);
            h2.put(toInsert);
        } // END while loop
        
        // read in input file
        string inputFileName = argv[2];
        std::fstream inFile3(inputFileName);
        
        // check if inFile3 opened
        if (!inFile3)
            throw std::invalid_argument("failed to open input file, check filename and path:\n");
        
        // spell check input file
        int mispelledCountH1 = 0;
        
        // start h1 timer
        ProcessTimer h1Time;
        h1Time.setTimeStart(clock());
        bool isNumber;
        
        while (inFile3 >> input )
        {
            string toCheck;
            for (unsigned int i = 0 ; i < input.length(); i++) // take out punctuation
            {
                if (!ispunct(input[i]))
                    toCheck += tolower(input[i]);
            }
            
            isNumber = false;
            
            for (unsigned int i = 0 ; i < toCheck.length(); i++) // check if toCheck is a numeric
            {
                if (isdigit(input[i]))
                    isNumber = true;
            }
           
            if (!h1.containsString(toCheck) && !isNumber) // if toCheck not found & not number
            {
                mispelledCountH1++;
            }
            
        } // END while loop
        
        // stop h1 timer
        h1Time.setTimeEnd(clock());
        
        // print number of mispelled words and time
        cout << endl;
        cout << "Total number of words hashtable1 considers mispelled: " << mispelledCountH1 << endl;
        cout << "Total runtime for spell check with hashtable1: " << h1Time << endl;
        
        
        // read in input file back in with new inFile
        std::fstream inFile4(inputFileName);
        
        // check if inFile4 opened
        if (!inFile4)
            throw std::invalid_argument("failed to open input file, check filename and path:\n");
        
        // spell check input file
        int mispelledCountH2 = 0;
        
        // start h2 timer
        ProcessTimer h2Time;
        h2Time.setTimeStart(clock());
        
        
        while (inFile4 >> input )
        {
            string toCheck;
            for (unsigned int i = 0 ; i < input.length(); i++) // take out punctuation
            {
                if (!ispunct(input[i]))
                    toCheck += tolower(input[i]);
            }
            
            isNumber = false;
            
            for (unsigned int i = 0 ; i < toCheck.length(); i++) // check if toCheck is numeric
            {
                if (isdigit(input[i]))
                    isNumber = true;
            }
            
            if (!h2.containsString(toCheck) && !isNumber) // if toCheck not found & not number
            {
                //cout << mispelledCount << ". " << toCheck << ", ";
                mispelledCountH2++;
            }
            
        } // END while loop
        
        // stop h2 timer
        h2Time.setTimeEnd(clock());
        
        // print number of mispelled words and time
        cout << "Total number of words hashtable2 considers mispelled: " << mispelledCountH2 << endl;
        cout << "Total runtime for spell check with hashtable2: " << h2Time << endl;
        
        // print statement of which table was more time efficient
        if (h1Time.getTimeElapsed() < h2Time.getTimeElapsed())
        {
            cout << "Hashtable1 (chaining) is more time efficient than ";
            cout << "Hashtable2 (quadratic probing)" << endl;
        }
        else
        {
            cout << "Hashtable2 (quadratic probing) is more time efficient than ";
            cout << "Hashtable1 (chaining)" << endl;
        }
        
    } // END TRY
    catch (std::bad_alloc &ba0)
    {
        cout << "Caught bad_alloc exception in function main.\n";
        cout << ba0.what();
        cout << endl;
    }
    catch (std::out_of_range &oor0)
    {
        cout << "Caught out_of_range exception in function main.\n";
        cout << oor0.what();
        cout << endl;
    }
    
    catch (std::invalid_argument &ia0)
    {
        cout << "Caught invalid_argument exception in function main.\n";
        cout << ia0.what();
        cout << endl;
    }
    catch (...)
    {
        cout << "unknown exception caught in function main." << endl;
    }
    
    return 0;
}
