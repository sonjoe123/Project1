//
// Created by phant on 9/27/2022.
//

#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H

#include "DSString.h"
// create an object that can both hold the string and the integer count of itself
// basically re create a map object
class WordCounts {
public:
    // Store the word
    DSString word;
    // Store the value of the word
    int count;
    bool operator==(const DSString& rhs) {
        return rhs == word;
    }
   bool operator==(const WordCounts& rhs){
         if(count == rhs.count){
             return true;
         }
    }

};

#endif 
