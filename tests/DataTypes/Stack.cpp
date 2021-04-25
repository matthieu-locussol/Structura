#include <DataTypes/Stack.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stack", "[DataTypes][Stack]")
{
    SECTION("Stack of integers")
    {
        Structura::Stack<int>* stack = new Structura::Stack<int>();

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
            REQUIRE(stack->size() == 0);
            REQUIRE_THROWS(stack->peek());

            stack->push(50);
            stack->push(100);

            REQUIRE(stack->pop() == 100);
            REQUIRE(stack->size() == 1);
            REQUIRE(stack->peek() == 50);
        }

        delete stack;
    }
}
