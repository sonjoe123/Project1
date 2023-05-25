//
// Created by phant on 9/29/2022.
//

#ifndef DOEVERYTHING_H
#define DOEVERYTHING_H
#include "DSString.h"
#include "WordCounts.h"
class DoEverything{
public:
    void train(char inputName[50]);
    void test(char inputName[50]);
    void check(char inputName[50]);

private:
    // Dictionary vector
    DSVector<WordCounts> counts;
    // Testing vector
    DSVector<WordCounts> testStore;
    // Delimeter use for tokenize
    //Create a stop sign for special value including the space
    char *delim = " ,.<>/?;:\"'{}[]!@#$%^&*()-_=+1234567890~`";
    // Stop word vector
    DSVector<WordCounts> stopWord;

};
#endif //CLIONPROJECT_DOEVERYTHING_H
