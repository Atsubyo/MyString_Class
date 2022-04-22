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
        cout << "[Are you cool?]" << '\n';
        
        MyString name;
        MyString name1("Andrew");
        MyString name2("andrew");
        MyString name3("Andrwe");
        MyString name4("andrwe");
        MyString name5("Andwer");
        MyString name6("andwer");
        cout << "Enter Name: ";
        cin >> name;
        while (name != "") {
            if (name == name1 || name == name2 || name == name3 || name == name4 || name == name5 || name == name6) {
                cout << name << ", I'm dissapointed. No." << '\n';
            } else {
                cout << "Wow, " << name << " is so cool!" << '\n';
            }
            cout << "Enter Name: ";
            cin >> name;
        }
    }
}