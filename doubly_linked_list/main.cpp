#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList<int> list;
    int test = list.head->getData();
    cout<<test;
    return 0;
}
