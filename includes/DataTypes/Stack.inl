#include <stdexcept>

namespace St {

    //! @ingroup DataTypes
    //! @class St::Stack
    //! @brief DataTypes class that represents a Stack data structure
    //!
    //! A stack is a data structure used to store a collection of objects. Individual items
    //! can be added and stored in a stack using a `push` operation. Objects can be retrieved
    //! using a `pop` operation, which removes an item from the stack.

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

    //! The `push` method adds an element to the stack.
    //!
    //! @param value The value to add to the stack.
    //! @returns The new size of the stack.
    //! @see duplicate
    template <typename T>
    int Stack<T>::push(const T& value)
    {
        Node* node = new Node(value, this->_head);

        this->_head = node;
        return ++this->_size;
    }

    //! The `duplicate` method adds an element to the stack which has the same value as
    //! the current head. If the stack is empty, it leaves it unchanged.
    template <typename T>
    void Stack<T>::duplicate()
    {
        if (this->_size > 0) {
            const T value = this->_head->_value;
            this->push(value);
        }
    }

    //! The `swap` method exchange places of the two topmost items in the stack. If the stack
    //! contains less than 2 elements, it leaves it unchanged.
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

    //! The `rotateLeft` method will rotate the stack by moving the last element
    //! to the top position. The top element will then become the second, the
    //! second the third, and so on. If the stack contains less than 2 elements,
    //! it leaves it unchanged.
    //!
    //! @see rotateRight
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

    //! The `rotateRight` method will rotate the stack by moving the top element
    //! to the last position. The second element will become the first, the third
    //! will become the second, and so on. If the stack contains less than 2
    //! elements, it leaves it unchanged.
    //!
    //! @see rotateLeft
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

    //! The `pop` method removes the most recently added element from the stack
    //! (i.e. the top element). If the stack is empty, throws an out_of_range exception.
    //!
    //! @returns The removed top element.
    //! @see peek
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

    //! The `peek` method observes the top element without removing it from the stack.
    //!
    //! @returns The top element.
    //! @see pop
    template <typename T>
    const T& Stack<T>::peek() const
    {
        if (this->_size == 0) {
            throw std::out_of_range("Can not peek from an empty stack!");
        }

        return this->_head->_value;
    }

    //! The `size` method returns the current number of elements in the stack.
    //!
    //! @returns The number of elements in the stack.
    template <typename T>
    const int& Stack<T>::size() const
    {
        return this->_size;
    }

    //! The `isEmpty` method returns whether the stack contains element or not.
    //!
    //! @returns  `true` is there is no element in the stack, `false` otherwise.
    template <typename T>
    bool Stack<T>::isEmpty() const
    {
        return this->_size == 0;
    }
} // namespace St