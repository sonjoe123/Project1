//
// Based on DSString by Mark Fontenot
//

#ifndef DSSTRING_H
#define DSSTRING_H

#include "DSVector.h"

#include <iostream>
#include <cstring>

// Note: you can also add functionality to DSVector.h

class DSString : public DSVector<char>
{
private:
    // private:

public:
    /**
     * Constructors and destructor call the base class
     *
     * Make sure you use proper memory management.
     **/

    // we get those from DSVector and can say default in C++11

    // constructor with no argument
    DSString() = default;
    
    //The big3
    //Copy constructor
    DSString(const DSString &) = default;
    //Copy assignment operator
    DSString(DSString &&rhs) = default;
    //Destructor
    ~DSString() = default;

    // we need to implement this.
    //constructor with 1 argument
    //Mỗi chữ trong 1 từ sẽ được phân ra thành từng kí tự 1 và lưu vào 1 cái array
    DSString(const char *);

    /**
     * Overloaded Assignment Operators
     * See: https://en.cppreference.com/w/cpp/language/operators
     */
    // these are already provided by DSVector (default in C++11)
    // string 2 = string1 
    DSString &operator=(const DSString &) = default;
    //string 2 = "adf" move constructor. it will take the other one address and the other will lost it, && rhs, &lhs only for creating object
    DSString &operator=(DSString &&) = default;

    // we need to add this.
    // this one will be called when the righ hand value has alrd declared and if the left hand hasnt been declared it will call the dsstring(const char*)
    //reassigning an exsiting object to a value
    DSString &operator=(const char *);

    /**
     * Overloaded non-modifying string concat
     */
    //string 1 + string 2
    DSString operator+(const DSString &) const;

    /**
     * Standard relational operators.  Feel free to add additional.
     **/
    //string compare
    bool operator==(const DSString &) const;
    bool operator<(const DSString &) const;

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * parameter start - the index of where to start
     * parameter numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(size_t start, size_t numChars) const;

    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. It would be smart to always have an extra `\0`
     * at the end of the string in DSString so you can just return a pointer to the
     * objects. You can make objects protected in DSVector, so
     * DSString can see it or you can realize that an iterator is actually also a
     * pointer.
     **/
    const char *c_str() const;

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. `DSString&`
     * could be const, but then we would have to implement a const interator in
     * DSVector.
     **/
    friend std::ostream &operator<<(std::ostream &, const DSString &);

    // You are free to add more functionality to the class.  For example,
    // you may want to add a find(...) function that will search for a
    // string within a string.  (just an example)
    ifstream& getline(ifstream &is, DSString& s, char& delim);
};

#endif