#pragma once

#ifndef DATATYPES_STACK_HPP
#define DATATYPES_STACK_HPP

namespace St {
    template <typename T>
    class Stack {
    public:
        Stack() = default;
        Stack(Stack&&) = default;
        Stack(const Stack&) = delete;

        Stack& operator=(Stack&&) = default;
        Stack& operator=(const Stack&) = delete;

        int push(const T& value);
        void duplicate();
        void swap();
        void rotateLeft();
        void rotateRight();

        const T pop();
        const T& peek() const;
        const int& size() const;
        bool isEmpty() const;

        ~Stack();

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

#include <DataTypes/Stack.inl>

#endif