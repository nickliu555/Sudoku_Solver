// Author: Shuyi ( Nick ) Liu
// userid: lius15
// Email: shuyi.liu@vanderbilt.edu
// Honor Statement: I have neither given nor received unauthorized help on this assignment.

#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <iostream>
#include <string>

class Sudoku {
public:
    /**
     * Default constructor. Should initialize the object with an empty puzzle (81 zeroes)
     */
    Sudoku();

    /**
     * Reinitializes the object with a new puzzle from the specified file in parameter. The passed
     * string will be the relative path of the text file filename - the name of the input file
     */
    void loadFromFile(std::string filename);

    /**
     * The entry point for your solver. Returns true if a solution was found, otherwise returns
     * false
     */
    bool solve();

    /**
     * Determines if the sudoku puzzle passed in the parameter is equal to this sudoku puzzle
     * other - the other sudoku puzzle to be compared
     */
    bool equals(const Sudoku& other) const;

    /**
     * Operator overload
     * A friend function that prints to the output stream the current puzzle contents in a nicely
     * formatted manner
     */
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);

private:
    /**
     * 9 by 9 blocks that define the sudoku puzzle
     */
    int puzzle[9][9];

    /**
     * Checks if that value (in parameter) can be placed in the 1st subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid1(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 2st subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid2(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 3rd subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid3(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 4th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid4(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 5th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid5(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 6th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid6(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 7th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid7(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 8th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid8(int val);

    /**
     * Checks if that value (in parameter) can be placed in the 9th subgrid in its current state
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkSubGrid9(int val);

    /**
     * Checks if that value can be placed in that block given the subgrid that its in (subgrid is
     * determined based on block position) row - row number val - value return true if it is valid,
     * false otherwise
     */
    bool checkSubGridValid(int row, int col, int val);

    /**
     * Checks if that value can be placed in that block given the column
     * col - column number
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkCol(int col, int val);

    /**
     * Checks if that value can be placed in that block given the row
     * row - row number
     * val - value
     * return true if it is valid, false otherwise
     */
    bool checkRow(int row, int val);
};

#endif // SUDOKU_H