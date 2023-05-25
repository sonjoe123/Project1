#include <iostream>
#include <algorithm>
#include <fstream>
#include "DSString.h"
#include <sstream>
#include <unordered_map>
#include "WordCounts.h"
#include "DoEverything.h"

using namespace std;
int main(int argc, char** argv) {
    // Run the program
    DoEverything model;
    model.train(argv[1]);
    model.test(argv[2]);
    model.check(argv[3]);


    return 0;
}



