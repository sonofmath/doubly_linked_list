
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
Exchanges the content of the container by the content of x, which is another list of the same type.
Sizes may differ.
*/
template <class T>
void LinkedList<T>::swap(LinkedList<T>& obj){
    //Set up ptr to first & last nodes in this object's list
    Node *firstNode = head->getNext();
    Node *lastNode = tail->getPrev();

    //Set up ptr to first & last nodes in obj list
    Node *firstNodeObj = obj.head->getNext();
    Node *lastNodeObj = obj.tail->getPrev();

    //Swap the heads & set the links (this object 1st):
    Node *temp = head;
    head = obj.head;
    head->setNext(firstNodeObj);
    firstNodeObj->setPrev(head);

    //Now other object (obj)
    obj.head = temp;
    obj.head->setNext(firstNode);
    firstNode->setPrev(obj.head);

    //Swap the tails & set links (this object 1st):
    temp = tail;
    tail = obj.tail;
    tail->setPrev(lastNodeObj);
    lastNodeObj->setPrev(obj.tail);

    //Now other object (obj)
    obj.tail = temp;
    obj.tail->setPrev(lastNode);
    lastNode->setNext(obj.tail);
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

//Empty container constructor (default constructor)
template <class T>
LinkedList<T>::LinkedList() {
    init();
}

template <class T>
void LinkedList<T>::init(){
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

//Constructs a container with n elements. Each element is a copy of val.
template <class T>
LinkedList<T>::LinkedList(int n, T val){
    init();

    //Push elements with the same data...
    for(int i = 1; i <= n; ++i){
        this->push_back(val);
    }
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

template <class T>
void LinkedList<T>::resize(int n) {
    int count = 0;

    if(!isEmpty()) {
        Node *current = head->getNext();

        //Get a count of nodes in the list
        while(current != tail) {
            //Increment the counter
            count++;

            //Increment current
            current = current->getNext();
        }

        //Checks to see if there are more nodes than the new resized value
        if(count > n) {
            current = current->getPrev();
            while(count > n) {
                Node *temp = current;
                current->getPrev()->setNext(tail);
                tail->setPrev(current->getPrev());
                current = current->getPrev();
                delete temp;
                count--;
            }
        }
        //Checks to see if there are less nodes than the new resized value
        else if(count < n) {
            current = current->getPrev();
            while(count < n) {
                Node *newNode = new Node(0);
                newNode->setPrev(current);
                newNode->setNext(tail);

                current->setNext(newNode);
                tail->setPrev(newNode);

                current = newNode;
                count++;
            }
        }
    }
}

template <class T>
void LinkedList<T>::resize(int n, T newData) {
    int count = 0;

    if(!isEmpty()) {
        Node *current = head->getNext();

        //Get a count of nodes in the list
        while(current != tail) {
            //Increment the counter
            count++;

            //Increment current
            current = current->getNext();
        }

        //Checks to see if there are more nodes than the new resized value
        if(count > n) {
            current = current->getPrev();
            while(count > n) {
                Node *temp = current;
                current->getPrev()->setNext(tail);
                tail->setPrev(current->getPrev());
                current = current->getPrev();
                delete temp;
                count--;
            }
        }
        //Checks to see if there are less nodes than the new resized value
        else if(count < n) {
            current = current->getPrev();
            while(count < n) {
                Node *newNode = new Node(newData);
                newNode->setPrev(current);
                newNode->setNext(tail);

                current->setNext(newNode);
                tail->setPrev(newNode);

                current = newNode;
                count++;
            }
        }
    }
}

template <class T>
void LinkedList<T>::unique() {
    if(!isEmpty()) {
        Node *current = tail->getPrev();
        Node *temp = NULL;

        while(current != head) {
            bool solo = true;
            //val->data = current->data;
            temp = head->getNext();
            while(temp != current) {
                if(current->data == temp->data) {
                    solo = false;
                    Node *delNode = current;
                    current = current->getPrev();

                    current->setNext(delNode->getNext());
                    delNode->getNext()->setPrev(current);

                    delete delNode;
                } else {
                    temp = temp->getNext();
                }
            }
            if (solo) {
                current = current->getPrev();
            }
        }
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
                Node *delNode = current;
                current->getNext()->setPrev(current->getPrev());
                current->getPrev()->setNext(current->getNext());

                //Increment current
                current = current->getNext();

                //Delete the node
                delete delNode;
            } else {
                //Increment current
                current = current->getNext();
            }
        }
    }
    delete newNode;
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

/*
Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.
*/
template <class T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin(){
    if(tail->getPrev() != head)
        return LinkedList<T>::reverse_iterator(tail->getPrev());
    else
        return nullptr;
}

/*
Returns a reverse iterator pointing to the theoretical element preceding the first
element in the list container (which is considered its reverse end).
*/
template <class T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend(){
    if(head->getNext() != tail)
        return LinkedList<T>::reverse_iterator(head);
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

//Overloading the increment operator (++)
template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++(){
    //Goes to the next node
    if(curr->getNext() != nullptr){
        curr = curr->getNext();
    }
    return *this;
}

// Reverse Iterator class -----------------------------------------------------------

//Constructor
template<class T>
LinkedList<T>::reverse_iterator::reverse_iterator(typename LinkedList<T>::Node *s){
    curr = s;
}

//Overloading the equals operator (==)
template <class T>
const bool LinkedList<T>::reverse_iterator::operator ==(const reverse_iterator& r){
    return curr == r.curr;
}

//Overloading the not equal operator (!=)
template <class T>
const bool LinkedList<T>::reverse_iterator::operator !=(const reverse_iterator& r){
    return curr != r.curr;
}

//Overloading the dereference operator (*)
template <class T>
const T LinkedList<T>::reverse_iterator::operator *(){
    return curr->getData();
}

//Overloading the increment operator (++)
template <class T>
typename LinkedList<T>::reverse_iterator& LinkedList<T>::reverse_iterator::operator++(){
    //Goes to the next node
    if(curr->getPrev() != nullptr){
        curr = curr->getPrev();
    }
    return *this;
}