## Testing two different hashtable implementations for spellcheck and wordcount

### Goal:
This program designs and implements two different hashtable structures, one that uses chaining to handle collisions and one that uses quadratic probing. The structures will be used to perform word counting and spell checking. 

### How it works:
My program reads in the dictionary file and stores the lexicon in both hashtables. A second input file is read in, and its contents are searched for in the hashtables. When reading in both the dictionary and input files, I convert the strings to lowercase and strip them of punctuation and numbers.  If a word in the input file does not appear in the hashtable, then it is declared as misspelled. The program then prints the number of misspelled words according to each hashtable, and the runtime of the spell check process. Runtimes are compared to declare one hashtable structure as more time efficient than the other. 

In both the chaining and quadratic probing hashtables, I used a hash function that sums the ASCII values for each character in the string and divides this sum by the size of the hashtable. My chaining hashtable has a load factor of 1.0, while my quadratic probing hashtable has a load factor of 0.5.

### Optimizing efficiency:
Although I implemented rehash functions for both hashtable structures, I decided to include a function in main that counts the number of words in the file and instantiates the hashtable with an appropriate size. For chaining, the size is the first prime number above the number of words in the dictionary file. For quadratic probing, the size is the first prime number above twice the number of words. Since the size of the test dictionary files varied significantly, choosing a default table size would have been difficult, resulting in either wasted space resources or time resources from calling rehash frequently. 

In my put method for the chaining hashtable structure, I considered using a back pointer to avoid traversing through the linked list to insert at the end, but did not end up implementing one since I don’t expect collisions to happen too often given the load factor of 1.

### Performance on test inputs:

Hashtable Structure | dictionaryFile.txt (235,886 words) | dictionaryFileMedium.txt (9,897 words) | dictionaryFileSimple.txt (14 words)
--- | --- | --- | --- 
Chaining | Mispelled: 135, Runtime: 0.01380 | Mispelled: 17614, Runtime: 0.28121 | Mispelled: 0, Runtime: 0.000141 
--- | --- | --- | --- 

The theoretical average-case run time for both hashtable structures is O(1). In the case of this program, the timers include the process of standardizing the strings to lowercase, throwing out punctuation and digits. These forloops would add to the runtime. My runtime results showed that for larger files, chaining hashtable structures were more time efficient for the spellcheck process compared to quadratic probing. For smaller dictionary files and input files however, the two hashtable’s runtimes were about the same, with quadratic probing having a slight advantage. The runtime seems to depend on the spread of the dictionary files and how often collisions occurred accordingly. Perhaps lowering the load factor for the quadratic probing hashtable could result in faster runtimes. Space complexity however would increase.

