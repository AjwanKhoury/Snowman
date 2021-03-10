#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    //The Hat
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //strow hat
    CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )")); //mexican hat
    CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\n(.,.)\n( : )\n( : )")); //fez hat
    CHECK(nospaces(snowman(41114411)) == nospaces("___\n(_*_)\n(.,.)\n( : )\n( : )")); //russian hat

    //The Nose
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //normal
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )")); //dot
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )")); //line
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(..)\n( : )\n( : )")); //none

    //Left Eye
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //dot
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )")); //bigger dot
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )")); //biggest dot
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )")); //closed

    //Right Eye
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //dot
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )")); //bigger dot
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )")); //biggest dot
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )")); //closed

    //Left Arm
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )")); //normal arm
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )")); //upwards arm
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )")); //downwards arm
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //none

    //Right Arm
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));//normal arm
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )")); //upwards arm
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )")); //downwards arm
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //none

    //Torso
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //Buttons 
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )")); //vest
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )")); //inward arms 
    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(   )\n( : )")); //none

    //Base
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); //buttons
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(" ")")); //feet
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)")); //flat
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )")); //none
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555)); //smallNumber input
    CHECK_THROWS(snowman(1111441455)); //bigNumber input 

    CHECK_THROWS(snowman(-1)); //negativeNumber input
    CHECK_THROWS(snowman(-11114414));//negativeNumber input

    CHECK_THROWS(snowman(51114411));//invalidNumber for hat
    CHECK_THROWS(snowman(16114411));//invalidNumber for Nose
    CHECK_THROWS(snowman(11714411));//invalidNumber for left eye
    CHECK_THROWS(snowman(11184411));//invalidNumber for right eye
    CHECK_THROWS(snowman(11119411));//invalidNumber for left arm
    CHECK_THROWS(snowman(11114011));//invalidNumber for right arm
    CHECK_THROWS(snowman(11114401));//invalidNumber for torso
    CHECK_THROWS(snowman(11114410));//invalidNumber for base

}