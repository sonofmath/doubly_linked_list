#include <iostream>
#include "LinkedList.hpp"
using namespace std;

bool testInt(int num);
bool testDouble(double num);
bool testString(string str);
bool testSwap();

int main()
{
    cout<<testInt(5) <<endl;
    cout<<testDouble(5.5) <<endl;
    cout<<testString("Hello!") <<endl;
    cout<<testSwap() <<endl;
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

    cout<<"Popping back...\n";
    list.pop_back();
    cout<<"Number of elements now in list: " <<list.size();
    list.printList();

    //Testing the remove function
    cout<< endl <<"Removing 4 and -20 from the list...\n";
    list.remove(4);
    list.remove(-20);
    list.printList();

    cout<<"Clearing the list...\n";
    list.clear();
    list.printList();

    cout<<"Adding after doing clear(): \n";
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(3);
    list.push_back(9);
    list.push_back(10);
    list.push_back(3);
    list.push_back(6);

    cout<<"Calling unique(): \n";
    list.unique();

    //Testing iterator
    cout<<"Printing list using iterator: \n";
    int counter = 1;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        cout<<"Node " <<counter <<" = " <<*it <<endl;
        counter++;
    }

    cout<< endl <<"Resizing the list to 5 Nodes...";
    list.resize(5, 2);
    list.printList();
    cout<< endl << "Resizing the list to add 3 Nodes with value of 2...";
    list.resize(8, 2);
    list.printList();



    cout<< endl << "Printing the reversed list...";
    list.reverse();
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

    cout<<"Popping back...\n";
    list.pop_back();
    cout<<"Number of elements in list: " <<list.size();
    list.printList();

    //Testing the remove function
    cout<< endl <<"Removing 4.0 and 4.3 from the list...\n";
    list.remove(4.0);
    list.remove(4.3);
    list.printList();

    cout<<"Clearing the list...\n";
    list.clear();
    list.printList();

    cout<<"Adding after doing clear(): \n";
    list.push_back(1.1);
    list.push_back(2.2);
    list.push_back(2.2);
    list.push_back(2.2);
    list.push_back(3.3);
    list.push_back(4.4);
    list.push_back(5.5);
    list.push_back(6.6);
    list.push_back(7.7);
    list.push_back(8.8);
    list.push_back(9.9);
    list.push_back(2.2);
    list.push_back(10.10);
    list.push_back(8.8);

    cout<<"Calling unique(): \n";
    list.unique();

    //Testing iterator
    cout<<"Printing list using iterator: \n";
    int counter = 1;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        cout<<"Node " <<counter <<" = " <<*it <<endl;
        counter++;
    }

    cout<< endl << "Resizing the list to 5 Nodes...";
    list.resize(5, 2.3);
    list.printList();
    cout<< endl << "Resizing the list to add 3 Nodes with value of 2.3...";
    list.resize(8, 2.3);
    list.printList();

    cout<< endl <<"Printing the reversed list...";
    list.reverse();
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

    cout<<"Popping back...\n";
    list.pop_back();
    cout<<"Number of elements in list: " <<list.size();
    list.printList();

    //Testing the remove function
    cout<< endl <<"Removing HELLO and JR from from the list...\n";
    list.remove("HELLO");
    list.remove("JR");
    list.printList();

    cout<<"Clearing the list...\n";
    list.clear();
    list.printList();

     cout<<"Adding after doing clear(): \n";
    list.push_back("Alpha");
    list.push_back("Alpha");
    list.push_back("Alpha");
    list.push_back("Beta");
    list.push_back("Gamma");
    list.push_back("Delta");
    list.push_back("Epsilon");
    list.push_back("Zeta");
    list.push_back("Eta");
    list.push_back("Delta");
    list.push_back("Theta");
    list.push_back("Iota");
    list.push_back("Kappa");
    list.push_back("Delta");

    cout<<"Calling unique(): \n";
    list.unique();

    //Testing iterator
    cout<<"Printing list using iterator: \n";
    int counter = 1;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        cout<<"Node " <<counter <<" = " <<*it <<endl;
        counter++;
    }

    cout<< endl << "Resizing the list to 5 Nodes...";
    list.resize(5, "Hello Ray!");
    list.printList();
    cout<< endl << "Resizing the list to add 3 Nodes with value of Hello Ray...";
    list.resize(8, "Hello Ray!");
    list.printList();

    cout<< endl << "Printing the reversed list...";
    list.reverse();
    list.printList();
    cout<<"**************************************************************\n";
    return test;
}

bool testSwap(){
    cout<<"**************************************************************\n";
    cout<<"Testing swap function: \n";
    bool test = false;
    LinkedList<int> list1(5,50);
    LinkedList<int> list2(3,30);

    cout<<"list1:";
    list1.printList();

    cout<<"list2:";
    list2.printList();

    cout<<"Swapping Lists: \n";
    list1.swap(list2);

    cout<<"list1:";
    list1.printList();

    cout<<"list2:";
    list2.printList();

    cout<<"**************************************************************\n";
    return test;
}
