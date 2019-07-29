#ifndef ALGORITHMS_TREE_COMMON_NODE_H_
#define ALGORITHMS_TREE_COMMON_NODE_H_

template <typename T>
class Node {
public:
    Node();
    Node(T val);
    ~Node();

    Node<T>* left() const;
    Node<T>* right() const;
    T data() const;

    void left(Node<T>* left);
    void right(Node<T>* right);
    void data(T val);

private:
    T m_data;
    Node<T>* m_left;
    Node<T>* m_right;
};

template <typename T>
Node<T>::Node() : m_data(0), m_left(nullptr), m_right(nullptr) {}

template <typename T>
Node<T>::Node(T val) : m_data(val), m_left(nullptr), m_right(nullptr) {}

template <typename T>
Node<T>::~Node() {
    if (m_left) delete m_left;
    if (m_right) delete m_right;
}

template <typename T>
Node<T>* Node<T>::left() const {
    return m_left;
}

template <typename T>
Node<T>* Node<T>::right() const {
    return m_right;
}

template <typename T>
T Node<T>::data() const {
    return m_data;
}

template <typename T>
void Node<T>::left(Node<T>* left) {
    m_left = left;
}

template <typename T>
void Node<T>::right(Node<T>* right) {
    m_right = right;
}

template <typename T>
void Node<T>::data(T val) {
    m_data = val;
}

#endif // ALGORITHMS_TREE_COMMON_NODE_H_
