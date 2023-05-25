//
// Created by phant on 9/29/2022.
//

#include "DoEverything.h"
#include <iostream>
#include <algorithm>
#include "DSString.h"
#include  <fstream>
#include  <sstream>
#include <cstring>
#include <iomanip>
#include "WordCounts.h"

using namespace std;
void DoEverything::train(char inputName[50]) {
    // Create a char array to store
    char buffer[1024];


    // Read in the training file
    ifstream readFile(inputName);
    // Get the title line out
    readFile.getline(buffer, 1024);

    while (!readFile.eof()) {
        readFile.getline(buffer, 1024, ',');
        //instead of looking at 4 and 0 as numbers, they will be true for positive and false for negative
        bool sentiment = buffer[0] == '4';

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024);
        for(int i = 0; i < strlen(buffer); i++){
            buffer[i] = tolower(buffer[i]);
        }
        //When it reach this special variable, it will stop and take out the word
        //tokenize a single word of a single tweet and save it in its own array
        char* token = strtok(buffer, delim);

        DSVector<DSString> words;
        //Push back this single word into a vector
        while (token != nullptr) {
            words.push_back(token);
            token = strtok(nullptr, delim);
        }


        for (int i = 0; i < words.size(); i++) {
            //Create a char pointer to point through each word in the vector
            WordCounts* itr = find(counts.begin(), counts.end(), words[i]);
            // If there is no word that is the same in this vector yet then create a new word and set its value depends on the sentiment
            if (itr == counts.end()) {
                WordCounts curr;
                curr.word = words[i];
                if (sentiment) {
                    curr.count = 1;
                } else {
                    curr.count = -1;
                }
                // Push back the new word that just create into the vector
                counts.push_back(curr);
            } else {
                // If there is a word that already exist, we will change its score depend on the sentiment
                if (sentiment) {
                    itr->count+=1;
                } else {
                    itr->count-=1;
                }
            }
        }

    }
    readFile.close();


}
void DoEverything::test(char inputName[50]) {
    char buffer[1024];


    ifstream readFile(inputName);
    readFile.getline(buffer, 1024);
    DSVector<WordCounts>id;
    testStore;
    WordCounts sentCount;
    int tempSent = 0;
    while (!readFile.eof()) {
        readFile.getline(buffer, 1024, ',');
        WordCounts tempId;
        tempId.word = buffer;
        sentCount = tempId;
        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024, ',');

        readFile.getline(buffer, 1024);
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }
        //Create a stop sign for special value including the space
        // char *delim = "
        //When it reach this special variable, it will stop and take out the word
        //tokenize a single word of a single tweet and save it in its own array
        char *token = strtok(buffer, delim);

        DSVector<DSString> words;
        //Push back this single word into a vector
        while (token != nullptr) {
            words.push_back(token);
            token = strtok(nullptr, delim);
        }

        // Loop through thw vector and will add the value of each word of one line into totalSent
        int totalSent =0;
        for (int i = 0; i < words.size(); i++) {

            WordCounts* itr = find(counts.begin(),counts.end(), words[i]);
            if (itr != counts.end()){
                totalSent +=itr->count;


            }
        }
        // Check to see whether that line is positive or negative
        if(totalSent >0 ){
            sentCount.count = 4;

        }
        else{
            sentCount.count = 0;
        }
        testStore.push_back(sentCount);

    }
    // Create the first output file
    ofstream myFile;
    myFile.open("./First_output.csv");
    for (int i = 0; i < testStore.size()-1; ++i) {

        myFile << testStore[i].count << " " << testStore[i].word << endl;
    }

    readFile.close();
}

void DoEverything::check(char inputName[50]) {
    char buffer[1024];
    DSVector<WordCounts> checkSent;
    double count = 0;
    ifstream readFile(inputName);
    readFile.getline(buffer, 1024);

    while (!readFile.eof()) {
        readFile.getline(buffer, 1024, ',');
        WordCounts tempSent;
        // Have to change to integer because the sentiment in testing is being stored as integer
        tempSent.count = atoi(buffer);

        checkSent.push_back(tempSent);
        readFile.getline(buffer, 1024);

    }
    // Get the number of correct tweet
    for (int i = 0; i < checkSent.size(); i++) {
        if(checkSent[i].count == testStore[i].count){
            count+=1;
        }
    }
    // Calculating the accuracy
    double accuracy ;
    double size = (double) checkSent.size() - 1;
    accuracy = count / size;
    // Print out the second output
    ofstream myFile;
    myFile.open("./Second_Output.csv");
    myFile << fixed << setprecision(3) <<accuracy <<endl;
    for (int i = 0; i < testStore.size(); ++i) {
        if(checkSent[i].count != testStore[i].count) {
            myFile << checkSent[i].count << ", " << testStore[i].count << ", " << testStore[i].word << endl;
        }
    }
    readFile.close();
}

