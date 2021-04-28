#include <stdexcept>

namespace St {

    //! @ingroup Lists
    //! @class St::LinkedList
    //! @brief Lists class that represents a LinkedList data structure
    //!
    //! A linked list data structure includes a series of connected nodes. Here, each node
    //! store the data and the address of the next node.

    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        Node* current = this->_head;

        while (current != nullptr) {
            const Node* item = current;
            current = current->_next;
            delete item;
        }

        this->_size = 0;
    }

    //! The `serialize` method returns a string representation of the elements contained in
    //! the linked list.
    //!
    //! @returns A string representing the linked list elements.
    template <typename T>
    std::string LinkedList<T>::serialize() const
    {
        std::string listString = "[";
        Node* current = this->_head;

        while (current != nullptr) {
            const Node* item = current;
            current = current->_next;

            listString += std::to_string(item->_value);
            if (current != nullptr) {
                listString += ", ";
            }
        }

        listString += "]";

        return listString;
    }

    //! The `get` method retrieves an element from the linked list given its position. If no
    //! position is provided, it returns the first element of the list.
    //!
    //! @param position The position of the element to retrieve.
    //! @returns The element at that position.
    template <typename T>
    const T& LinkedList<T>::get(int position) const
    {
        if (position < 0) {
            throw std::out_of_range("Position can not be a negative number!");
        }

        if (position + 1 > this->_size) {
            throw std::out_of_range("There is no element at the given position!");
        }

        Node* node = this->_head;
        for (int i = 0; i < position; ++i) {
            node = node->_next;
        }

        return node->_value;
    }

    //! The `remove` method removes the element at a given position. If no position is
    //! provided, it removes the first element from the linked list.
    //!
    //! @param position The position of the element to remove.
    template <typename T>
    const int& LinkedList<T>::remove(int position)
    {
        if (position < 0) {
            throw std::out_of_range("Position can not be a negative number!");
        }

        if (position + 1 > this->_size) {
            throw std::out_of_range("There is no element at the given position!");
        }

        Node* previousNode = nullptr;
        Node* node = this->_head;
        for (int i = 0; i < position; ++i) {
            previousNode = node;
            node = node->_next;
        }

        if (previousNode != nullptr) {
            previousNode->_next = node->_next;
        }

        delete node;
        return --this->_size;
    }

    //! The `insert` method inserts a new element at the specified position in the linked
    //! list. If no position is provided, insert the element at the beginning of the list.
    //!
    //! @param value The value to insert in the linked list.
    //! @param position The index at which you want to insert the value (starts at 0).
    //! @returns The number of elements in the linked list.
    template <typename T>
    const int& LinkedList<T>::insert(const T& value, int position)
    {
        if (position < 0) {
            throw std::out_of_range("Position can not be a negative number!");
        }

        if (position > this->_size) {
            throw std::out_of_range("Position can not be greater than the list size!");
        }

        Node* previousNode = nullptr;
        Node* nextNode = this->_head;
        for (int i = 0; i < position; ++i) {
            previousNode = nextNode;
            nextNode = nextNode->_next;
        }

        Node* node = new Node(value, nextNode);
        if (position == 0 || this->_size == 0) {
            this->_head = node;
        }
        else {
            previousNode->_next = node;
        }

        return ++this->_size;
    }

    //! The `append` method inserts a new element at the tail of the linked list.
    //!
    //! @param value The value to append in the linked list.
    //! @returns The number of elements in the linked list.
    template <typename T>
    const int& LinkedList<T>::append(const T& value)
    {
        if (this->_size == 0) {
            return this->insert(value);
        }
        else {
            const int position = this->_size;
            return this->insert(value, position);
        }
    }

    //! The `size` method returns the current number of elements in the linked list.
    //!
    //! @returns The number of elements in the stack.
    template <typename T>
    const int& LinkedList<T>::size() const
    {
        return this->_size;
    }

    //! The `isEmpty` method returns whether the linked list contains element or not.
    //!
    //! @returns  `true` is there is no element in the linked list, `false` otherwise.
    template <typename T>
    bool LinkedList<T>::isEmpty() const
    {
        return this->_size == 0;
    }
} // namespace St