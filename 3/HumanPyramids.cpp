#include "HumanPyramids.h"
#include "error.h"
#include "map.h"
using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
double weightOnBackOf(int row, int col, int pyramidHeight) {
    static Map<pair<int, int>, double> cache;
    if (cache.containsKey({row, col})) {
        return cache[{row, col}];
    }
    if (row < 0 || col > row || col < 0 || pyramidHeight < row + 1) {
        error("Human out of bounds");
    }
    if (row == 0) {
        cache[{0,0}] = 0;
        return 0;
    }
    else {
        if (col == 0) {
            double result = 80 + weightOnBackOf(row-1, col, pyramidHeight)/2;
            cache[{row, col}] = result;
            return result;
        } else if (col == row){
            double result = 80 + weightOnBackOf(row-1, col-1, pyramidHeight)/2;
            cache[{row, col}] = result;
            return result;
           } else {
            double result = 160 + weightOnBackOf(row-1, col, pyramidHeight)/2 + weightOnBackOf(row-1, col-1, pyramidHeight)/2;
            cache[{row, col}] = result;
            return result;
        }
    }
}






/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {


    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
