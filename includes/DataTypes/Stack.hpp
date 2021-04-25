#pragma once

#ifndef DATATYPES_STACK_HPP
#define DATATYPES_STACK_HPP

namespace Structura {
    template <typename T>
    class Stack {
    public:
        Stack() = default;
        Stack(Stack&&) = default;
        Stack(const Stack&) = delete;

        Stack& operator=(Stack&&) = default;
        Stack& operator=(const Stack&) = delete;

        void push(const T& value);
        void duplicate();
        void swap();

        const T pop();
        const T& peek() const;
        const int& size() const;
        bool isEmpty() const;

        ~Stack();

    private:
        struct Node {
            T value;
            Node* next = nullptr;

            Node(const T& value, Node* next) : value(value), next(next){};
        };

        int _size = 0;
        Node* _head = nullptr;
        Node* _tail = nullptr;

        void _print(const Node* node) const;
    };
} // namespace Structura

#include <DataTypes/Stack.inl>

#endif