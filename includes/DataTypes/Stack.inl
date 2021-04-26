#include <stdexcept>

namespace Structura {
    template <typename T>
    Stack<T>::~Stack()
    {
        Node* current = this->_head;

        while (current != nullptr) {
            const Node* item = current;
            current = current->_next;
            delete item;
        }

        this->_size = 0;
    }

    template <typename T>
    void Stack<T>::push(const T& value)
    {
        Node* node = new Node(value, this->_head);

        this->_head = node;
        ++this->_size;
    }

    template <typename T>
    void Stack<T>::duplicate()
    {
        if (this->_size > 0) {
            const T value = this->_head->_value;
            this->push(value);
        }
    }

    template <typename T>
    void Stack<T>::swap()
    {
        if (this->_size >= 2) {
            Node* oldHead = this->_head;
            Node* oldSecond = this->_head->_next;

            this->_head = oldSecond;
            oldHead->_next = oldSecond->_next;
            this->_head->_next = oldHead;
        }
    }

    template <typename T>
    void Stack<T>::rotateLeft()
    {
        if (this->_size == 2) {
            this->swap();
        }
        else if (this->_size >= 3) {
            Node* tailPrevious = this->_head->_next;
            while (tailPrevious->_next->_next != nullptr) {
                tailPrevious = tailPrevious->_next;
            }
            Node* tail = tailPrevious->_next;

            tail->_next = this->_head;
            tailPrevious->_next = nullptr;
            this->_head = tail;
            tail = tailPrevious;
        }
    }

    template <typename T>
    void Stack<T>::rotateRight()
    {
        if (this->_size == 2) {
            this->swap();
        }
        else if (this->_size >= 3) {
            Node* tailPrevious = this->_head->_next;
            while (tailPrevious->_next->_next != nullptr) {
                tailPrevious = tailPrevious->_next;
            }
            Node* tail = tailPrevious->_next;

            tail->_next = this->_head;
            this->_head = this->_head->_next;
            tail = tail->_next;
            tail->_next = nullptr;
        }
    }

    template <typename T>
    const T Stack<T>::pop()

    {
        if (this->_size == 0) {
            throw std::out_of_range("Can not pop from an empty stack!");
        }

        const Node* node = this->_head;
        this->_head = this->_head->_next;
        --this->_size;

        const T value = node->_value;
        delete node;

        return value;
    }

    template <typename T>
    const T& Stack<T>::peek() const
    {
        if (this->_size == 0) {
            throw std::out_of_range("Can not peek from an empty stack!");
        }

        return this->_head->_value;
    }

    template <typename T>
    const int& Stack<T>::size() const
    {
        return this->_size;
    }

    template <typename T>
    bool Stack<T>::isEmpty() const
    {
        return this->_size == 0;
    }
} // namespace Structura