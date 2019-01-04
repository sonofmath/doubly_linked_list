#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class LinkedList {

    public:
        //Constructor:
        LinkedList();

        //Modifiers:
        void push_back(T newData);
        void push_front(T newData);
        void printList();
        void pop_front();

        //Element access:
        T front();
        T back();

        //Capacity:
        const int size() const;
        const bool empty() const;

        //Destructor:
        ~LinkedList();

    private:
        class Node {
            public:
                //Constructors:
                Node();
                Node(Node* newPrev, Node* newNext, T newData);
                Node(T newData);

                //Setters:
                void setData (T inputData);
                void setNext (Node* newNext);
                void setPrev (Node* newPrev);

                //Getters
                const T getData();
                Node* getNext();
                Node* getPrev();

                //Destructor:
                ~Node();

                Node *next, *prev;
                T data;

            private:

        };

        Node* head;
        Node* tail;

        const bool isEmpty() const;
};

#include "LinkedList.inl"

#endif // LINKEDLIST_HPP_INCLUDED
