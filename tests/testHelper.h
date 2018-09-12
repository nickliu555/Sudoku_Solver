// R. Tairas
// CS 3270
// Vanderbilt University

#ifndef TESTHELPER_H
#define TESTHELPER_H

#include "Sudoku.h"
#include <gtest/gtest.h>

/**
 * Returns the string that is printed to an output stream.
 */
inline std::string getString(const Sudoku& puzzle)
{
    std::ostringstream stream;
    stream << puzzle;
    return stream.str();
}

inline void printExpected(std::string name, const Sudoku& puzzle, const Sudoku& solution)
{
    std::cout << std::endl << "Attempt to solve \"" << name << "\" failed." << std::endl;
    std::cout << "Actual:" << std::endl;
    std::cout << puzzle;
    std::cout << "Expected:" << std::endl;
    std::cout << solution;
}

inline void printTiming(int startTime, int endTime)
{
    std::cout << "[xxxxxxxxxx] Manual timing: " << (endTime - startTime) / (double)CLOCKS_PER_SEC;
    std::cout << " seconds." << std::endl;
}

#endif // TESTHELPER_H
