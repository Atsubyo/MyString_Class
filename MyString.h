// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using std::ostream, std::istream;

class MyString {
    private:
        size_t _capacity; // capacity of cstring array
        size_t _size; // size of string (chars)
        size_t _length; // length of string (bytes)
        char* _cstring; // array of chars that make up the string
    public:
        MyString(); // default constructor
        MyString(const MyString& str); // copy constructor
        MyString(const char* s); // from c-string constructor
        ~MyString(); // destructor

        size_t capacity() const; // capacity getter
        size_t size() const; // size getter
        size_t length() const; // length getter
        const char* data() const; // data getter

        size_t resize(size_t n); // resizes c-string to new length
        bool empty() const; // returns if length is zero (empty string)
        const char& front() const; // returns reference to first char
        const char& at(size_t pos) const; // returns reference to char at given position
        void clear(); // clears the elements of string
        size_t find(const MyString& str, size_t pos = 0) const; // finds first occurence of a char in string starting from pos (default 0)

        friend ostream& operator<< (ostream& os, const MyString& str); // insertion operator overload
        friend istream& operator>> (istream& is, MyString& str); // extraction operator overload [FUN]
        MyString& operator= (const MyString& str); // copy assignment
        MyString& operator+= (const MyString& str); // add equal operator overload
        friend bool operator== (const MyString& lhs, const MyString& rhs); // isEqual operator [EXTRA CREDIT]
        friend bool operator!= (const MyString& lhs, const MyString& rhs); // isEqual operator [FUN]
        friend MyString operator+ (const MyString& lhs, const MyString& rhs); // sum operator [EXTRA CREDIT]
};

#endif