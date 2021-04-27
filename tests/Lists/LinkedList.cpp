#include <Lists/LinkedList.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("LinkedList", "[Lists][LinkedList]")
{
    St::LinkedList<int>* list = new St::LinkedList<int>();

    REQUIRE(list->isEmpty());
    REQUIRE(list->size() == 0);

    SECTION("Insert method")
    {
        SECTION("Empty list")
        {
            const int size = list->insert(15);
            REQUIRE(size == 1);
            REQUIRE(list->size() == 1);
        }

        SECTION("List with many elements")
        {
            list->insert(20);
            const int size = list->insert(25);
            std::cout << size << std::endl;
            REQUIRE(size == 2);
            REQUIRE(list->size() == 2);
            REQUIRE_THROWS(list->insert(999, -1));
            REQUIRE_THROWS(list->insert(999, 3));

            list->insert(18, 1);
            REQUIRE(list->size() == 3);

            list->insert(26, 3);
            REQUIRE(list->size() == 4);
            list->insert(28, 3);
        }
    }

    SECTION("Append method")
    {
        SECTION("Empty list")
        {
            const int size = list->append(30);
            REQUIRE(size == 1);
            REQUIRE(list->size() == 1);
        }

        SECTION("List with many elements")
        {
            list->append(35);
            const int size = list->append(40);
            REQUIRE(size == 2);
            REQUIRE(list->size() == 2);

            list->insert(55, 1);
            list->insert(60, 1);
            list->insert(65, 1);
            list->insert(999, 5);
            list->append(0);
        }
    }

    SECTION("Get method")
    {
        SECTION("Empty list")
        {
            REQUIRE_THROWS(list->get(0));
        }

        SECTION("List with many elements")
        {
            list->insert(85);
            list->insert(90);
            list->insert(95);
            REQUIRE_THROWS(list->insert(999, 5));

            REQUIRE(list->get(0) == 95);
            REQUIRE(list->get(1) == 90);
            REQUIRE(list->get(2) == 85);
            REQUIRE_THROWS(list->get(5));

            REQUIRE(list->get() == 95);
        }
    }

    SECTION("Remove method")
    {
        SECTION("Empty list")
        {
            REQUIRE_THROWS(list->remove());
        }

        SECTION("List with many elements")
        {
            list->insert(85);
            list->insert(90);
            list->insert(95);
            list->insert(105);
            list->insert(110);

            REQUIRE_THROWS(list->remove(-1));
            REQUIRE_THROWS(list->remove(6));

            REQUIRE(list->get(1) == 105);
            const int size = list->remove(1);
            REQUIRE(size == 4);
            REQUIRE(list->size() == 4);
            REQUIRE(list->get(1) == 95);
        }
    }

    delete list;
}