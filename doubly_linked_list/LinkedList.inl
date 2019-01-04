
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
    else
        cout<<"The list is empty!\n";
}

template <class T>
LinkedList<T>::~LinkedList() {
    if(head != nullptr) {
        delete head;
    }
}
