
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

template <class T>
LinkedList<T>::Node::~Node() {}

template <class T>
LinkedList<T>::LinkedList() {
    head = new Node(nullptr, nullptr, 7);
}

template <class T>
const T LinkedList<T>::Node::getData() const {
    return data;
}

template <class T>
LinkedList<T>::~LinkedList() {
    if(head != nullptr) {
        delete head;
    }
}
