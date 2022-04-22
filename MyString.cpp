// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
MyString::MyString() : _capacity{15}, _size{}, _length{}, _cstring{new char[16]{'\0'}} {}

MyString::MyString(const MyString& str) : _capacity{str.capacity()}, _size{str.size()}, _length{str.length()}, _cstring{new char[str.capacity()+1]} {
    const char* str_cstring = str.data();
    for (size_t i = 0; i <= _capacity; ++i) {
        _cstring[i] = str_cstring[i];
    }
}
// {'a', 'b', 'c', '\0', '\0', '\0'}    <-- _cstring
//   1 ,  2 ,  3 ,   4 ,   5 ,   6      <-- array size
//   1 ,  2 ,  3 ,   4 ,   5            <-- _capacity
//   1 ,  2 ,  3                        <-- _size
//   1 ,  2 ,  3                        <-- _length
MyString::MyString(const char* s) : _capacity{15}, _size{}, _length{}, _cstring{new char[16]{'\0'}} {
    size_t s_size = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        ++s_size;
    }
    if (s_size > _capacity) {
        while (s_size > _capacity) {
            _capacity *= 2;
            char* new_cstring = new char[_capacity+1]{'\0'};
            delete[] _cstring;
            _cstring = new_cstring;
            for (size_t i = 0; i < s_size; ++i) {
                _cstring[i] = s[i];
            }
        }
    } else {
        for (size_t i = 0; i < s_size; ++i) {
            _cstring[i] = s[i];
        }
    }
    _size = s_size;
    _length = s_size;
}

MyString::~MyString() {
    delete[] _cstring;
}

size_t MyString::resize(size_t n) {
    if (n > _capacity) {
        _size = n;
        _length = n;
        _capacity *= 2;
        char* new_cstring = new char[_capacity+1]{'\0'};
        for (size_t i = 0; i < n; ++i) {
            new_cstring[i] = _cstring[i];
        }
        delete[] _cstring;
        _cstring = new_cstring;
    } else {
        _size = n;
        _length = n;
        char* new_cstring = new char[_capacity+1]{'\0'};
        for (size_t i = 0; i < n; ++i) {
            new_cstring[i] = _cstring[i];
        }
        delete[] _cstring;
        _cstring = new_cstring;
    }
    return n;
}

size_t MyString::capacity() const {
    return _capacity;
}

size_t MyString::size() const {
    return _size;
}

size_t MyString::length() const {
    return _length;
}

const char* MyString::data() const {
    return _cstring;
}

bool MyString::empty() const {
    if (_size == 0) {
        return true;
    }
    return false;
}

const char& MyString::front() const {
    return _cstring[0];
}

const char& MyString::at(size_t pos) const {
    if (pos >= _size) {
        throw std::out_of_range("Error: access out of range");
    }
    return _cstring[pos];
}

void MyString::clear() {
    for (size_t i = 0; i < _size; ++i) {
        _cstring[i] = '\0';
    }
    _size = 0;
    _length = 0;
}

size_t MyString::find(const MyString& str, size_t pos) const {
    const char* str_cstring = str.data();
    size_t s_size = str.size();
    bool is_found = true;
    for (size_t i = pos; i < _size; ++i) {
        if (str_cstring[0] == _cstring[i]) {
            int tracker = 0;
            for (size_t j = i; j < i + s_size; ++j) {
                if (str_cstring[tracker] != _cstring[j]) {
                    is_found = false;
                    break;
                }
                ++tracker;
            }
            if (is_found) {
                return i;
            }
        }
    }
    return -1;
}

ostream& operator<< (ostream& os, const MyString& str) {
    const char* str_cstring = str.data();
    for (size_t i = 0; i < str.size(); ++i) {
        os << str_cstring[i];
    }
    return os;
}

istream& operator>> (istream& is, MyString& str) { // [FUN]
	str.clear();
	while (!is.eof()) {
		char c;
		is >> std::noskipws >> c; // use the noskipws manipulator
		if (isspace(c) || is.fail()) break; // if whitespace, can stop adding to string
		const char* newstr = new char[2] {c, '\0'};
		MyString newc = MyString(newstr); // MyString: copy constructor
		delete[] newstr;
		str += newc; // MyString: operator+=()
	}
	return is;
}

MyString& MyString::operator= (const MyString& str) {
    char* new_cstring;
    if (str.capacity() != _capacity) {
        _capacity = str.capacity();
        new_cstring = new char[_capacity+1]{'\0'};
        delete[] _cstring;
        _cstring = new_cstring;
    }
    _size = str.size();
    _length = str.length();
    const char* str_cstring = str.data();
    for (size_t i = 0; i < _size; ++i) {
        _cstring[i] = str_cstring[i];
    }
    return *this;
}

MyString& MyString::operator+= (const MyString& str) {
    size_t new_size = _size + str.size();
    while (new_size > _capacity) {
        _capacity *= 2;
        char* new_cstring = new char[_capacity + 1]{'\0'};
        for (size_t i = 0; i < _size; ++i) {
            new_cstring[i] = _cstring[i];
        }
        delete[] _cstring;
        _cstring = new_cstring;
    }
    const char* str_cstring = str.data();
    int tracker = 0;
    for (size_t i = _size; i < new_size; ++i) {
        _cstring[i] = str_cstring[tracker];
        ++tracker;
    }
    _size = new_size;
    _length = new_size;
    return *this;
}

bool operator== (const MyString& lhs, const MyString& rhs) { // [EXTRA CREDIT]
    if (lhs.size() != rhs.size()) {
        return false;
    }
    const char* lhs_string = lhs.data();
    const char* rhs_string = rhs.data();
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs_string[i] != rhs_string[i]) {
            return false;
        }
    }
    return true;
}

bool operator!= (const MyString& lhs, const MyString& rhs) { // [FUN]
    if (lhs.size() != rhs.size()) {
        return true;
    }
    const char* lhs_string = lhs.data();
    const char* rhs_string = rhs.data();
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs_string[i] != rhs_string[i]) {
            return true;
        }
    }
    return false;
}

MyString operator+ (const MyString& lhs, const MyString& rhs) { // [EXTRA CREDIT]
    MyString new_string;
    new_string += lhs.data();
    new_string += rhs.data();
    return new_string;
}