#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
    public:
        LinkedList();
        void insert(T newData);
        void printList();
        ~LinkedList();

        T front();
        T back();
        const int size() const;
        const bool empty() const;

    private:
        class Node {
            public:
                Node ();
                Node (Node* newPrev, Node* newNext, T newData);
                Node(T newData);

                // Setters
                void setData (T inputData);
                void setNext (Node* newNext);
                void setPrev (Node* newPrev);

                // Getters
                const T getData ();
                Node* getNext();
                Node* getPrev ();

                // Destructor
                ~Node ();

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
