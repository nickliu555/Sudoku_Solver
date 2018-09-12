// R. Tairas
// CS 3270
// Vanderbilt University

#include "Sudoku.h"
#include "./testHelper.h"
#include <ctime>

/**
 * The fixture for testing Sudoku class.
 */
class SudokuTest : public ::testing::Test {
protected:
    virtual void SetUp()
    {
        puzzle.loadFromFile("../txt/sudoku-test1.txt");
        solution.loadFromFile("../txt/sudoku-test1-solution.txt");
    }

    Sudoku puzzle;
    Sudoku solution;
};

TEST_F(SudokuTest, EqualsMethod)
{
    Sudoku puzzleCopy(puzzle);
    Sudoku solutionCopy(solution);

    // Test that a puzzles are equal.
    ASSERT_TRUE(puzzle.equals(puzzle));
    ASSERT_TRUE(puzzle.equals(puzzleCopy));

    // Test that a puzzles are equal.
    ASSERT_TRUE(solution.equals(solution));
    ASSERT_TRUE(solution.equals(solutionCopy));

    // Test two differing puzzle states.
    ASSERT_FALSE(puzzle.equals(solution));
    ASSERT_FALSE(solution.equals(puzzle));
}

TEST_F(SudokuTest, Print)
{
    Sudoku puzzle;
    puzzle.loadFromFile("../txt/sudoku-test1.txt");

    // The expected output of printing the puzzle.
    // NOTE: the expected output does not contain trailing whitespace. However, your implementation
    // can have trailing whitespace, because in the test below, all trailing whitespace will be
    // removed. Hence, it is okay if after every digit you automatically include one whitespace
    // (even the last digit or missing digit in each line).
    std::string expected[] = { "  4 3 |   8   | 2 5", "6     |       |", "      |     1 |   9 4",
        "------+-------+------", "9     |     4 |   7", "      | 6   8 |", "  1   | 2     |     3",
        "------+-------+------", "8 2   | 5     |", "      |       |     5",
        "  3 4 |   9   | 7 1" };

    // Get string output of a puzzle.
    std::string str = getString(puzzle);

    std::istringstream f(str);
    std::string line;

    int i = 0;

    // Check that every line in the output returned by operator<< matches the expected output.
    // NOTE: for each line, trailing whitespace and new line character are removed.
    while (std::getline(f, line)) {
        line.erase(
            std::find_if(line.rbegin(), line.rend(), [](int ch) { return !std::isspace(ch); })
                .base(),
            line.end());
        EXPECT_EQ(line, expected[i]);
        i++;
    }
}

TEST_F(SudokuTest, SolveOne)
{
    // Test single puzzle (sudoku-test1.txt).
    clock_t startTime = clock();
    bool result = puzzle.solve();
    clock_t endTime = clock();

    // Print the manually recorded execution time.
    printTiming(startTime, endTime);

    // solve() should return true.
    ASSERT_TRUE(result);

    // The state of the puzzle should equal the solved puzzle.
    EXPECT_TRUE(puzzle.equals(solution));
}

TEST_F(SudokuTest, SolveMultiple)
{
    // Test puzzle in sudoku-test1.txt.
    clock_t startTime = clock();
    bool result = puzzle.solve();
    clock_t endTime = clock();

    printTiming(startTime, endTime);

    ASSERT_TRUE(result);
    EXPECT_TRUE(puzzle.equals(solution));

    // If the puzzle outputs differ, show both puzzle outputs.
    if (!puzzle.equals(solution)) {
        printExpected("test1", puzzle, solution);
    }

    // Test puzzle in sudoku-test2.txt.
    solution.loadFromFile("../txt/sudoku-test2-solution.txt");
    puzzle.loadFromFile("../txt/sudoku-test2.txt");

    // The two initialized puzzle states should not be equal.
    EXPECT_FALSE(puzzle.equals(solution));

    startTime = clock();
    result = puzzle.solve();
    endTime = clock();

    printTiming(startTime, endTime);

    ASSERT_TRUE(result);
    EXPECT_TRUE(puzzle.equals(solution));

    if (!puzzle.equals(solution)) {
        printExpected("test2", puzzle, solution);
    }
}

TEST_F(SudokuTest, Unsolvable)
{
    puzzle.loadFromFile("../txt/sudoku-impossible.txt");

    // Test puzzle in sudoku-impossible.txt.
    clock_t startTime = clock();
    bool result = puzzle.solve();
    clock_t endTime = clock();

    printTiming(startTime, endTime);

    EXPECT_FALSE(result);
}