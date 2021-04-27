#pragma once

#ifndef LISTS_LINKEDLIST_HPP
#define LISTS_LINKEDLIST_HPP

#include <string>

namespace St {
    template <typename T>
    class LinkedList {
    public:
        LinkedList() = default;
        LinkedList(LinkedList&&) = default;
        LinkedList(const LinkedList&) = delete;

        LinkedList& operator=(LinkedList&&) = default;
        LinkedList& operator=(const LinkedList&) = delete;

        std::string serialize() const;
        const T& get(int position = 0) const;
        const int& remove(int position = 0);
        const int& insert(const T& value, int position = 0);
        const int& append(const T& value);
        const int& size() const;
        bool isEmpty() const;

        ~LinkedList();

    private:
        struct Node {
            T _value;
            Node* _next = nullptr;

            Node(const T& value, Node* next) : _value(value), _next(next){};
        };

        int _size = 0;
        Node* _head = nullptr;
    };
} // namespace St

#include <Lists/LinkedList.inl>

#endif