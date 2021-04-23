#include <Utils/Multiplication.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Multiplication works", "[single-file]" ) {
    REQUIRE( multiplication( 2, 4 ) == 8 );
    REQUIRE( multiplication( 2, 6 ) == 12 );
}
