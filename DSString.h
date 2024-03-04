#ifndef DSSTRING_H
#define DSSTRING_H

#include "DSVector.h"
#include <iostream>
#include <cstring>

class DSString : public DSVector<char>
{
private:

public:
    DSString() = default;
    DSString(const DSString &) = default;
    DSString(DSString &&rhs) = default;
    ~DSString() = default;

    DSString(const char *);

    DSString &operator=(const DSString &) = default;
    DSString &operator=(DSString &&) = default;

    DSString &operator=(const char *);

    DSString operator+(const DSString &) const;

    bool operator==(const DSString &) const;
    bool operator<(const DSString &) const;

    DSString substring(size_t start, size_t numChars) const;

    const char *c_str() const;

    friend std::ostream &operator<<(std::ostream &, const DSString &);

    ifstream& getline(ifstream &is, DSString& s, char& delim);
};

#endif
