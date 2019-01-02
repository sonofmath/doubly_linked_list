#include <iostream>
#include "LinkedList.hpp"
using namespace std;

bool testInt(int num);
bool testDouble(double num);
bool testString(string str);


int main()
{
    cout<<testInt(5) <<endl;
    cout<<testDouble(5.5) <<endl;
    cout<<testString("Hello!") <<endl;
    return 0;
}

bool testInt(int num){
    bool test = false;

    LinkedList<int> list;
    list.insert(num);
    list.insert(9);
    list.insert(4);
    list.insert(-20);
    list.insert(4);
    list.insert(10);
    list.printList();
    return test;
}

bool testDouble(double num){
    bool test = false;

    LinkedList<double> list;
    list.insert(num);
    list.insert(4.3);
    list.insert(-20.1212);
    list.insert(4.0);
    list.insert(10.34);
    list.printList();
    return test;
}

bool testString(string str){
    bool test = false;

    LinkedList<string> list;
    list.insert(str);
    list.insert("Ray");
    list.insert("JR");
    list.insert("I love C++");
    list.insert("HELLO");
    list.printList();
    return test;
}
