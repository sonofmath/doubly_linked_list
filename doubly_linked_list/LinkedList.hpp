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
        void pop_back();
        void resize(int n, T newData);
        void clear();

        //Operations
        void remove(T inputData);
        void unique();
        void reverse();

        //Element access:
        T front();
        T back();

        //Capacity:
        const int size() const;
        const bool empty() const;

        //Destructor:
        ~LinkedList();

        // Declaration of the iterator class for this list
		class iterator
		{
			public:
				iterator(typename LinkedList<T>::Node *s);
				iterator& operator++();
				const T operator*();
				const bool operator ==(const iterator& r);
				const bool operator !=(const iterator& r);

			private:
				typename LinkedList<T>::Node *curr;
		};

        iterator begin();
		iterator end();

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

/* For separate header and source file source code
	Template classes & functions declarations and implementations
	should be in the "same file". BST.inl allows us to separate
	these two.
	*/
#include "LinkedList.inl"

#endif // LINKEDLIST_HPP_INCLUDED
