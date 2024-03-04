#include "DSString.h"
#include <string.h>
#include <stdexcept>

DSString::DSString(const char *x)
{
    size_t size = strlen(x);
    resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        (*this)[i] = x[i];
    }
}

DSString &DSString::operator=(const char *rhs)
{
    size_t size = strlen(rhs);
    resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        (*this)[i] = rhs[i];
    }

    return *this;
}

DSString DSString::operator+(const DSString &rhs) const
{
    DSString result;
    size_t rhs_size = strlen(rhs.c_str());
    char *str = new char[theSize + rhs_size + 1];
    std::strncpy(str, objects, theSize);
    std::strncpy(str + theSize, rhs.c_str(), rhs_size);
    str[theSize + rhs_size] = '\0';
    result = str;
    return result;
}

bool DSString::operator==(const DSString &rhs) const
{
    if (size() != rhs.size())
        return false;

    for (size_t i = 0; i < size(); ++i)
        if ((*this)[i] != rhs[i])
            return false;

    return true;
}

bool DSString::operator<(const DSString &rhs) const
{
    size_t compSize = min(size(), rhs.size());
    for (size_t i = 0; i < compSize; ++i)
    {
        if ((*this)[i] < rhs[i])
            return true;
        if ((*this)[i] > rhs[i])
            return false;
    }

    if (size() < rhs.size())
        return true;

    return false;
}

DSString DSString::substring(size_t start, size_t numChars) const
{
    if (start + numChars > size())
        throw std::runtime_error("out of bounds!");

    DSString tmp;
    tmp.resize(numChars);

    for (size_t i = 0; i < numChars; ++i)
    {
        tmp[i] = (*this)[start + i];
    }
    return tmp;
}

const char *DSString::c_str() const
{
    return this->objects;
}

std::ostream &operator<<(std::ostream &out, const DSString &x)
{
    for (const auto &c : x)
        out << c;

    return out;
}
