#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
	}
	CHECK( a.size() == 1000 );
}

TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<1000; i++){
		s.push("Item " + std::to_string(i));
	}
	for(int i=0; i<500; i++){
		std::cout << s.pop() << std::endl;
	}
	CHECK( s.size() == 500 );
}

TEST_CASE ("Copy constructor test","[creation]"){
    AUDS<int> a;

    for(int i=0; i<150; i++){
        a.push(i);
    }

    AUDS<int> b = a;

    a.push(150);

    CHECK( a.size() == 151 );
    CHECK( b.size() == 150 );
}

TEST_CASE ("Copy operator test","[creation]"){
    AUDS<int> a, b;

    a.push(1);
    a.push(2);
    b.push(3);

    CHECK ( a.size() == 2 );
    CHECK ( b.size() == 1 );

    b = a;
    
    //check that they're copies
    CHECK ( a.size() == b.size() );

    a.pop();
    a.pop();

    //check that they don't refer to the same object
    CHECK ( a.size() == 0 );
    CHECK ( b.size() == 2 );
}

TEST_CASE ("Empty pop test", "[error]") {
    AUDS<int> a;
    REQUIRE_THROWS_WITH(a.pop(), "Cannot pop empty AUDS");
}
