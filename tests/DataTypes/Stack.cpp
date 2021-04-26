#include <DataTypes/Stack.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stack", "[DataTypes][Stack]")
{
    Structura::Stack<int>* stack = new Structura::Stack<int>();

    REQUIRE(stack->isEmpty());
    REQUIRE(stack->size() == 0);
    REQUIRE_THROWS(stack->peek());

    SECTION("Push method")
    {
        SECTION("Empty stack")
        {
            stack->push(15);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 15);
        }

        SECTION("Stack with many elements")
        {
            stack->push(20);
            stack->push(25);
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 25);
        }
    }

    SECTION("Pop method")
    {
        SECTION("Empty stack")
        {
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
            REQUIRE_THROWS(stack->peek());
        }

        SECTION("Stack with 1 element")
        {
            stack->push(30);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 30);
            REQUIRE(stack->pop() == 30);
        }

        SECTION("Stack with many elements")
        {
            stack->push(1);
            stack->push(2);
            stack->push(3);
            stack->push(50);
            stack->push(100);
            REQUIRE(stack->pop() == 100);
            REQUIRE(stack->size() == 4);
            REQUIRE(stack->peek() == 50);
        }
    }

    SECTION("Duplicate method")
    {
        SECTION("Empty stack")
        {
            stack->duplicate();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
        }

        SECTION("Stack with 1 element")
        {
            stack->push(70);
            stack->duplicate();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->pop() == 70);
            REQUIRE(stack->pop() == 70);
            REQUIRE_THROWS(stack->pop());
        }

        SECTION("Stack with many elements")
        {
            stack->push(68);
            stack->push(69);
            stack->push(70);
            stack->duplicate();
            REQUIRE(stack->size() == 4);
            REQUIRE(stack->pop() == 70);
            REQUIRE(stack->pop() == 70);
        }
    }

    SECTION("Swap method")
    {
        SECTION("Empty stack")
        {
            stack->swap();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
        }

        SECTION("Stack with 1 element")
        {
            stack->push(80);
            stack->swap();
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 80);
        }

        SECTION("Stack with 2 elements")
        {
            stack->push(80);
            stack->push(90);
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 90);
            stack->swap();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 80);
        }

        SECTION("Stack with many elements")
        {
            stack->push(80);
            stack->push(90);
            stack->push(95);
            stack->swap();
            REQUIRE(stack->size() == 3);
            REQUIRE(stack->peek() == 90);

            stack->swap();
            REQUIRE(stack->pop() == 95);
            REQUIRE(stack->pop() == 90);
            REQUIRE(stack->pop() == 80);
        }
    }

    SECTION("RotateLeft method")
    {
        SECTION("Empty stack")
        {
            stack->rotateLeft();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
        }

        SECTION("Stack with 1 element")
        {
            stack->push(11);
            stack->rotateLeft();
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 11);
        }

        SECTION("Stack with 2 elements")
        {
            stack->push(11);
            stack->push(22);
            stack->rotateLeft();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 11);
        }

        SECTION("Stack with 3 elements")
        {
            stack->push(11);
            stack->push(22);
            stack->push(33);
            stack->rotateLeft();
            REQUIRE(stack->size() == 3);
            REQUIRE(stack->peek() == 11);
            REQUIRE(stack->pop() == 11);
            REQUIRE(stack->pop() == 33);
            REQUIRE(stack->pop() == 22);
        }

        SECTION("Stack with many elements")
        {
            stack->push(22);
            stack->push(11);
            stack->push(33);
            stack->push(44);
            REQUIRE(stack->size() == 4);
            stack->rotateLeft();
            REQUIRE(stack->peek() == 22);
            stack->rotateLeft();
            REQUIRE(stack->peek() == 11);
            stack->rotateLeft();
            REQUIRE(stack->peek() == 33);
            stack->rotateLeft();
            REQUIRE(stack->peek() == 44);
            stack->rotateLeft();
            REQUIRE(stack->peek() == 22);
        }
    }

    SECTION("RotateRight method")
    {
        SECTION("Empty stack")
        {
            stack->rotateRight();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
        }

        SECTION("Stack with 1 element")
        {
            stack->push(11);
            stack->rotateRight();
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 11);
        }

        SECTION("Stack with 2 elements")
        {
            stack->push(11);
            stack->push(22);
            stack->rotateRight();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 11);
        }

        SECTION("Stack with 3 elements")
        {
            stack->push(11);
            stack->push(22);
            stack->push(33);
            stack->rotateRight();
            REQUIRE(stack->size() == 3);
            REQUIRE(stack->peek() == 22);
            REQUIRE(stack->pop() == 22);
            REQUIRE(stack->pop() == 11);
            REQUIRE(stack->pop() == 33);
        }

        SECTION("Stack with many elements")
        {
            stack->push(22);
            stack->push(11);
            stack->push(33);
            stack->push(44);
            REQUIRE(stack->size() == 4);
            stack->rotateRight();
            REQUIRE(stack->peek() == 33);
            stack->rotateRight();
            REQUIRE(stack->peek() == 11);
            stack->rotateRight();
            REQUIRE(stack->peek() == 22);
            stack->rotateRight();
            REQUIRE(stack->peek() == 44);
            stack->rotateRight();
            REQUIRE(stack->peek() == 33);
        }
    }

    delete stack;
}
