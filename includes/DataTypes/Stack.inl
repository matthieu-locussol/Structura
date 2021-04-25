#include <iostream>

namespace Structura {
    template <typename T>
    Stack<T>::~Stack()
    {
        Node* current = this->_head;

        while (current != nullptr) {
            const Node* item = current;
            _print(current);
            current = current->next;
            delete (item);
        }

        this->_size = 0;
    }

    template <typename T>
    void Stack<T>::push(const T& value)
    {
        Node* node = new Node(value, this->_head);

        if (this->_head == nullptr) {
            this->_tail = node;
        }

        this->_head = node;
        ++this->_size;
    }

    template <typename T>
    const T& Stack<T>::pop()

    {
        if (this->_size == 0) {
            throw std::out_of_range("Can not pop from an empty stack!");
        }

        if (this->_head->next == nullptr) {
            this->_tail = nullptr;
        }

        const Node* node = this->_head;
        this->_head = this->_head->next;
        --this->_size;

        const T& value = node->value;
        delete node;

        return value;
    }

    template <typename T>
    const T& Stack<T>::peek() const
    {
        if (this->_size == 0) {
            throw std::out_of_range("Can not peek from an empty stack!");
        }

        return this->_head->value;
    }

    template <typename T>
    const int& Stack<T>::size() const
    {
        return this->_size;
    }

    template <typename T>
    void Stack<T>::_print(Node* node) const
    {
        std::cout << "============================" << std::endl;
        std::cout << "Me: " << node << std::endl;
        std::cout << "Value: " << node->value << std::endl;
        std::cout << "Next: " << node->next << std::endl;
    }
} // namespace Structura