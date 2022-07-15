/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <cctype>
using namespace std;

string onlyConnectize(string phrase) {
    if (!phrase.size()) {
        return "";
    }
    if (!isalpha(phrase[0])) {
        return onlyConnectize(phrase.substr(1));
    }
    char c = phrase[0];
    if (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i' || c == 'A' || c == 'O' || c == 'E' || c == 'U' || c == 'I') {
        return onlyConnectize(phrase.substr(1));
    }

    return charToString(toupper(c)) + onlyConnectize(phrase.substr(1));
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

STUDENT_TEST("So tricky") {
    EXPECT_EQUAL(onlyConnectize("EE 364A"), "");
    EXPECT_EQUAL(onlyConnectize("For sale: baby shoes, never worn."), "FRSLBBYSHSNVRWRN");
    EXPECT_EQUAL(onlyConnectize("I'm the bad guy. (Duh!)"), "MTHBDGYDH");
}




