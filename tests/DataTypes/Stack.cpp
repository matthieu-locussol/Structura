#include <DataTypes/Stack.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stack", "[DataTypes][Stack]")
{
    SECTION("Stack of integers")
    {
        Structura::Stack<int>* stack = new Structura::Stack<int>();

        REQUIRE(stack->isEmpty());
        REQUIRE(stack->size() == 0);
        REQUIRE_THROWS(stack->peek());

        SECTION("Push method")
        {
            stack->push(15);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 15);

            stack->push(20);
            stack->push(25);
            REQUIRE(stack->size() == 3);
            REQUIRE(stack->peek() == 25);
        }

        SECTION("Pop method")
        {
            stack->push(30);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 30);

            REQUIRE(stack->pop() == 30);
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);
            REQUIRE_THROWS(stack->peek());

            stack->push(50);
            stack->push(100);
            REQUIRE(stack->pop() == 100);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 50);
        }

        SECTION("Duplicate method")
        {
            stack->duplicate();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);

            stack->push(70);
            stack->duplicate();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->pop() == 70);
            REQUIRE(stack->pop() == 70);
            REQUIRE_THROWS(stack->pop());
        }

        SECTION("Swap method")
        {
            stack->swap();
            REQUIRE(stack->isEmpty());
            REQUIRE(stack->size() == 0);

            stack->push(80);
            stack->swap();
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 80);

            stack->push(90);
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 90);
            stack->swap();
            REQUIRE(stack->size() == 2);
            REQUIRE(stack->peek() == 80);

            stack->push(95);
            stack->swap();
            REQUIRE(stack->size() == 3);
            REQUIRE(stack->peek() == 80);

            stack->swap();
            REQUIRE(stack->pop() == 95);
            REQUIRE(stack->pop() == 80);
            REQUIRE(stack->pop() == 90);
        }

        delete stack;
    }
}
