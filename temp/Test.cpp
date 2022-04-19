#include "doctest.h"
#include <iostream>
using namespace std;






/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	// erase(input, ' ');
	// erase(input, '\t');
	// erase(input, '\n');
	// erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	// CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
	// 												 "@-------@\n"
	// 												 "@-@@@@@-@\n"
	// 												 "@-@---@-@\n"
	// 												 "@-@@@@@-@\n"
	// 												 "@-------@\n"
	// 												 "@@@@@@@@@"));
	// /* Add more test here */
}

TEST_CASE("Bad input") {
    // CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
}


/* Add more test cases here */

// TEST_CASE("Good inputs")
// {
//     SUBCASE("Operator check not throw")
//     {
       
//     }

//     SUBCASE("Operators correc")
//     {
        
//     }
//     // if (strcmp(w, "1") == 0)
//     //     for (int i = 0; i < 200000; i++)
//     //     {
//     //         write(listenFd, "PUSH Hello-1\0", 13);
//     //         read(listenFd, r, BUFFSIZE);
//     //         puts(r);
//     //     }
//     // else if(strcmp(w, "2") == 0)
//     // {
//     //     for (int i = 0; i < 200000; i++)
//     //     {
//     //         write(listenFd, "PUSH Hello-2\0", 13);
//     //         read(listenFd, r, BUFFSIZE);
//     //         puts(r);
//     //     }
//     // }else{
//     //     for (int i = 0; i < 200000; i++)
//     //     {
//     //         write(listenFd, "PUSH Hello-3\0", 13);
//     //         read(listenFd, r, BUFFSIZE);
//     //         puts(r);
//     //     }
//     // }
// }

// TEST_CASE("Bad inputs")
// {
//     SUBCASE("invalid Matrix size")
//     {
        
        
//     }
// }
int main(){

    return 1;
}