#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED
#include <iostream>

template <class T>
class LinkedList {
    public:
        LinkedList ();

        class Node {
            public:
                Node ();
                Node (Node* newPrev, Node* newNext, T newData);
                // Setters
                void setData (T inputData);
                void setNext (Node* newNext);
                void setPrev (Node* newPrev);
                // Getters
                const T getData () const;
                const Node* getNext() const;
                const Node* getPrev () const;
                // Destructor
                ~Node ();

            private:
                Node *next, *prev;
                T data;
        };

        Node* head;

        ~LinkedList();

    private:

};

#include "LinkedList.inl"

#endif // LINKEDLIST_HPP_INCLUDED
