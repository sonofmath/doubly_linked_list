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

//Tests LinkedList methods with int type
bool testInt(int num){
    cout<<"**************************************************************\n";
    cout<<"Testing with int type: \n";
    bool test = false;

    LinkedList<int> list;
    list.push_back(num);
    list.push_back(9);
    list.push_back(4);
    list.push_back(-20);
    list.push_back(4);
    list.push_back(10);
    list.push_front(-404);
    cout<<"Front: " <<list.front() <<endl;
    cout<<"Back: " <<list.back() <<endl;
    cout<<"Popping front...\n";
    list.pop_front();
    cout<<"Number of elements now in list: " <<list.size();
    list.printList();
    cout<<"**************************************************************\n";
    return test;
}

//Tests LinkedList methods with double type
bool testDouble(double num){
    cout<<"**************************************************************\n";
    cout<<"Testing with double type: \n";
    bool test = false;

    LinkedList<double> list;
    list.push_back(num);
    list.push_back(4.3);
    list.push_back(-20.1212);
    list.push_back(4.0);
    list.push_back(10.34);
    list.push_front(-404.4);
    cout<<"Front: " <<list.front() <<endl;
    cout<<"Back: " <<list.back() <<endl;
    cout<<"Popping front...\n";
    list.pop_front();
    cout<<"Number of elements in list: " <<list.size();
    list.printList();
    cout<<"**************************************************************\n";
    return test;
}

//Tests LinkedList methods with string type
bool testString(string str){
    cout<<"**************************************************************\n";
    cout<<"Testing with string type: \n";
    bool test = false;

    LinkedList<string> list;
    list.push_back(str);
    list.push_back("Ray");
    list.push_back("JR");
    list.push_back("I love C++");
    list.push_back("HELLO");
    list.push_back("Bye!");
    list.push_front("I should be 1st now!");
    cout<<"Front: " <<list.front() <<endl;
    cout<<"Back: " <<list.back() <<endl;
    cout<<"Popping front...\n";
    list.pop_front();
    cout<<"Number of elements in list: " <<list.size();
    list.printList();
    cout<<"**************************************************************\n";
    return test;
}