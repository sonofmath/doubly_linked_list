
template <class T>
LinkedList<T>::Node::Node(Node* newPrev, Node* newNext, T newData) {
    prev = newPrev;
    next = newNext;
    data = newData;
}

template <class T>
LinkedList<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
    data = NULL;
}

//Returns the value of the first element in the list.
template <class T>
T LinkedList<T>::front(){
    if(!isEmpty())
        return head->getNext()->getData();
    else
        return T{};
}

//Returns the value of the last element in the list.
template <class T>
T LinkedList<T>::back(){
    if(!isEmpty())
        return tail->getPrev()->getData();
    else
        return T{};
}

//Returns the number of elements in the list.
template <class T>
const int LinkedList<T>::size() const{
    Node *current = head->getNext();
    int counter = 0;
    if(!isEmpty()){
        while(current != tail){
            counter++;
            current = current->getNext();
        }
    }
    return counter;
}

/*
Removes all elements from the list container (which are destroyed),
 and leaving the container with a size of 0.
*/
template <class T>
void LinkedList<T>::clear(){
    //If list is not empty
    if(!isEmpty()){
        Node *current = head->getNext();
        Node *previous;
        while(current != tail){
           previous = current;
           current = current->getNext();
           delete previous;
        }
        //Now we need to attach the head and tails pointers
        head->setNext(tail);
        tail->setPrev(head);
    }
}

//Returns whether the list is empty(1) or not(0).
template <class T>
const bool LinkedList<T>::empty() const{
    return isEmpty();
}

template <class T>
void LinkedList<T>::Node::setNext(Node* newNext){
    next = newNext;
}

template <class T>
void LinkedList<T>::Node::setPrev(Node* newPrev){
    prev = newPrev;
}

//Needed to use typename because Node is inside of LinkedList
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getNext(){
    return next;
}

//Needed to use typename because Node is inside of LinkedList
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getPrev(){
    return prev;
}

template <class T>
LinkedList<T>::Node::Node(T newData){
    next = nullptr;
    prev = nullptr;
    data = newData;
}

template <class T>
const T LinkedList<T>::Node::getData(){
    return data;
}

template <class T>
LinkedList<T>::Node::~Node() {}

template <class T>
LinkedList<T>::LinkedList() {
    //T{} is default value initialization
    head = new Node(nullptr, nullptr, T{});
    tail = new Node(nullptr,nullptr, T{});

    //Head node setup
    head->prev = nullptr;   //Start of list
    head->next = tail;

    //Tail node setup
    tail->prev = head;
    tail->next = nullptr;   //End of list

}

//Checks if the list is empty
template <class T>
const bool LinkedList<T>::isEmpty() const{
    if(head->getNext() == tail)
        return true;
    else
        return false;
}

//Adds a new element at the end of the list container, after its current last element
template <class T>
void LinkedList<T>::push_back(T newData){
    Node *newNode = new Node(newData);

    if(isEmpty()){
        //Attach the head and tail to new node
        head->setNext(newNode);
        tail->setPrev(newNode);

        //Attach the new node to head and tail
        newNode->setPrev(head);
        newNode->setNext(tail);
    }
    else{
        //Attach new node's prev ptr to node before tail
        newNode->setPrev(tail->getPrev());

        //Attach new node's next ptr to tail
        newNode->setNext(tail);

        //Attach the node before tail's next ptr to new node
        newNode->getPrev()->setNext(newNode);

        //Attach tails pre ptr to the new node
        tail->setPrev(newNode);
    }
}

//Inserts a new element at the beginning of the list, right before its current first element.
template <class T>
void LinkedList<T>::push_front(T newData){
    Node *newNode = new Node(newData);

    if(isEmpty()){
        //Attach the head and tail to new node
        head->setNext(newNode);
        tail->setPrev(newNode);

        //Attach the new node to head and tail
        newNode->setPrev(head);
        newNode->setNext(tail);
    }
    else{
        //Set new Node's prev ptr to head
        newNode->setPrev(head);

        //Set new Node'a next to node that was after head
        newNode->setNext(head->getNext());

        //Set head's next ptr to the new node
        newNode->getPrev()->setNext(newNode);

        //Set the prev value in node that use to be after head to new node
        newNode->getNext()->setPrev(newNode);
    }
}

//Removes the first element in the list container, effectively reducing its size by one.
template <class T>
void LinkedList<T>::pop_front(){
    if(!isEmpty()){
        //Node we want to delete
        Node *delNode = head->getNext();

        //The node that will now be first in list
        Node *firstNode = delNode->getNext();

        //Set head's next ptr to firstNode
        head->setNext(firstNode);

        //Set prev ptr in firstNode to head
        firstNode->setPrev(head);

        //Set firstNode's next ptr to actual 2nd node
        firstNode->setNext(delNode->getNext()->getNext());

        //Set the prev ptr in the 2nd node to point to firstNode
        firstNode->getNext()->setPrev(firstNode);

        //Delete delNode
        delete delNode;
    }
}


template <class T>
void LinkedList<T>::pop_back(){
    if(!isEmpty()){
        //Node we want to delete
        Node *delNode = tail->getPrev();

        //Node that will be last in the list
        Node *lastNode = delNode->getPrev();

        //Set tail's prev ptr to lastNode
        tail->setPrev(lastNode);

        //Set next ptr in lastNode to tail
        lastNode->setNext(tail);

        //Delete the last node
        delete delNode;
    }
}

/*We assume that every object has << overloaded (use caution).
Used for testing... I want to write a real iterator instead.
*/
template <class T>
void LinkedList<T>::printList(){
    Node *current = head->getNext();
    int counter = 0;
    if(!isEmpty()){
        cout<<endl;
        while(current != tail){
            counter++;
            cout<<"Node " <<counter <<" = " <<current->getData() <<endl;
            current = current->getNext();
        }
    }
    else{
        cout<<endl;
        cout<<"The list is empty!\n";
    }

}

//Removes from the container all the elements that compare equal to val.
//This calls the destructor of these objects and reduces the container size by the number of elements removed.
template <class T>
void LinkedList<T>::remove(T inputData) {
    Node *newNode = new Node(inputData);

    if(!isEmpty()) {
        Node *current = head->getNext();
        while(current != tail) {
            if(current->data == newNode->data) {
                current->getNext()->setPrev(current->getPrev());
                current->getPrev()->setNext(current->getNext());
            }
            //Increments current
            current = current->getNext();
        }
    }
}

//Reverses the order of the elements in the list container.
template <class T>
void LinkedList<T>::reverse(){
    if(!isEmpty()){
        //The first Node which will end up as the last.
        Node *current = head->getNext();

        //Node that will be pushed to the front of the list.
        Node *newFirst = current->getNext();

        //Checks if there is more than 1 node
        if(newFirst != tail) {
            Node *temp = newFirst->getNext();

            //Attaching current to its new nodes
            current->setNext(temp);
            current->setPrev(newFirst);
            temp->setPrev(current);

            //Attaching the head and the first node.
            head->setNext(newFirst);
            newFirst->setPrev(head);
            newFirst->setNext(current);

            //Resetting the pointers
            newFirst = current->getNext();
            temp = newFirst->getNext();

            // Checks if there are more than 2 nodes.
            // If so, do not reset the prev on current.
            while(newFirst != tail){
                //Attaching current to its new nodes
                current->setNext(temp);
                temp->setPrev(current);

                //Attaching the head and the new first node.
                newFirst->setPrev(head);
                newFirst->setNext(head->getNext());
                head->getNext()->setPrev(newFirst);
                head->setNext(newFirst);

                //Resetting the pointers
                newFirst = current->getNext();
                temp = newFirst->getNext();
            }
        }
    }
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList() {
    //If list is empty
    if(isEmpty()){
        delete head;
        delete tail;
    }
    //If not empty
    else{
        Node *previous = head;
        Node *current = head->getNext();
        while(current != tail){
            delete previous;
            previous = current;
            current = current->getNext();
        }
        delete tail;
    }
}

//Returns an iterator pointing to the first element in the list container.
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin(){
    if(head->getNext() != tail)
        return LinkedList<T>::iterator(head->getNext());
    else
        return nullptr;

}

/*
Returns an iterator referring to the past-the-end element in the list container.
The past-the-end element is the theoretical element that would follow the last element in the list container.
It does not point to any element, and thus shall not be dereferenced.
*/
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end(){
    if(tail->getPrev() != head)
        return LinkedList<T>::iterator(tail);
    else
        return nullptr;
}

// Iterator class -----------------------------------------------------------

//Constructor
template <class T>
LinkedList<T>::iterator::iterator(Node *s){
    curr = s;
}

//Overloading the equals operator (==)
template <class T>
const bool LinkedList<T>::iterator::operator ==(const iterator& r){
    return curr == r.curr;
}

//Overloading the not equal operator (!=)
template <class T>
const bool LinkedList<T>::iterator::operator !=(const iterator& r){
    return curr != r.curr;
}

//Overloading the dereference operator (*)
template <class T>
const T LinkedList<T>::iterator::operator *(){
    return curr->getData();
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++(){
    //Goes to the next node
    if(curr->getNext() != nullptr){
        curr = curr->getNext();
    }
    return *this;
}
