#include <iostream>
#include "MyString.h"
using std::cout, std::cin;

int main() {

    {
        cout << "[Test] overload operator+=" << '\n';
        cout << "Test 1: ";
        {
            MyString str("hello");
            str += " world";
            cout << str << '\n';
        }
    }

    {
        cout << '\n';
        cout << "[Test] overload operator==" << '\n';
        cout << "Test 1: ";
        {
            MyString str1("hello");
            MyString str2("hello");
            cout << (str1 == str2) << '\n';
        }

        cout << "Test 2: ";
        {
            MyString str1("ello");
            MyString str2("hello");
            cout << (str1 == str2) << '\n';
        }

        cout << "Test 3: ";
        {
            MyString str1("bello");
            MyString str2("hello");
            cout << (str1 == str2) << '\n';
        }

        cout << "Test 4: ";
        {
            MyString str1("Hello");
            MyString str2("hello");
            cout << (str1 == str2) << '\n';
        }

        cout << "Test 5: ";
        {
            MyString str1("Hello WORLD!@#$");
            MyString str2("Hello WORLD!@#$");
            cout << (str1 == str2) << '\n';
        }
    }
    
    {
        cout << '\n';
        cout << "[Test] overload operator+" << '\n';
        cout << "Test 1: ";
        {
            MyString str1("hello");
            MyString str2(" world");
            str1 = str1 + str2;
            cout << str1 << '\n';
        }

        cout << "Test 2: ";
        {
            MyString str1("hello");
            MyString str2(" world!");
            MyString str3(" again");
            str1 = str1 + str2 + str3;
            cout << str1 << '\n';
        }
    }

    {
        cout << '\n';
        cout << "[Test] overload operator>> and <<" << '\n';
        cout << "Test 1: ";
        {
            MyString name;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Outputting Name: " << name << '\n';
        }
    }
}