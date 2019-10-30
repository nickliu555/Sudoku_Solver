// Author: Shuyi ( Nick ) Liu

#include "Sudoku.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

/**
 * Default constructor. Should initialize the object with an empty puzzle (81 zeroes)
 */
Sudoku::Sudoku()
{
    // goes to every element in the 2D array and initializes it to 0
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            puzzle[r][c] = 0;
        }
    }
}

/**
 * Reinitializes the object with a new puzzle from the specified file in parameter. The passed
 * string will be the relative path of the text file filename - the name of the input file
 */
void Sudoku::loadFromFile(std::string filename)
{
    // declare input stream
    std::ifstream inFile;
    // Open the file stream
    inFile.open(filename);
    // check if file was opened
    if (!inFile) {
        std::cout << "Unable to open the file";
        exit(1); // call system to stop
    }
    // variable used to store the read values
    int readVal = -1;
    int row = 0;
    int col = 0;
    while (inFile >> readVal) {
        // this should not happen if the input is a valid puzzle
        if (row >= 9)
            break;

        // store the read value
        puzzle[row][col] = readVal;

        // go to the next block appropriately
        if (col >= 8) {
            row++;
            col = 0;
        } else {
            col++;
        }
    }
    // close input stream
    inFile.close();
}

/**
 * The entry point for your solver. Returns true if a solution was found, otherwise returns false
 */
bool Sudoku::solve()
{
    // initially assume that board is full
    bool boardFull = true;
    // this is to check if the board is full or not
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (puzzle[r][c] == 0)
                boardFull = false;
        }
    }

    // BASE CONDITION
    // if the board is true that means that solution is found
    if (boardFull) {
        return true;
    } else {
        // FINDS NEXT EMPTY BLOCK LOCATION
        int emptyRow = -1; // row of the empty block
        int emptyCol = -1; // column of the empty block
        int r = 0; // used to traverse the 9x9 puzzle
        int c = 0; // used to traverse the 9x9 puzzle
        bool foundEmpty = false; // whether an empty block has been found or not
        // keeps traversing though the blocks until an empty block has been found
        while (foundEmpty == false) {
            // if run into empty block
            if (puzzle[r][c] == 0) {
                emptyRow = r;
                emptyCol = c;
                foundEmpty = true;
            }

            // increment to the next block appropriately
            if (c >= 8) {
                r++;
                c = 0;
            } else
                c++;
        }

        // TEST EACH VALUE 1-9 IN THIS EMPTY BLOCK
        for (int val = 1; val < 10; val++) {
            // checks if the row, col, and subgrid of the block allow for the value
            bool rowGood = checkRow(emptyRow, val);
            bool colGood = checkCol(emptyCol, val);
            bool subGridGood = checkSubGridValid(emptyRow, emptyCol, val);
            // if row, col, and subgrid of the block does allow for the value
            if (rowGood && colGood && subGridGood) {
                // update the puzzle with the new value in the empty block
                puzzle[emptyRow][emptyCol] = val;
                // do a recursive call
                bool recursive = solve();
                // if the child recursive call returned true then return true
                if (recursive)
                    return recursive;
                // if the child recursive call returned false then just test the next possible value
                // for the empty block (revert back changes first)
                else
                    puzzle[emptyRow][emptyCol] = 0; // revert back changes
            }
        }
    }
    // if you reach this point then this has failed
    return false;
}

/**
 * Determines if the sudoku puzzle passed in the parameter is equal to this sudoku puzzle
 * other - the other sudoku puzzle to be compared
 */
bool Sudoku::equals(const Sudoku& other) const
{
    // goes thru all of the blocks for both puzzles, if any of them are not equal then return false
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (puzzle[r][c] != other.puzzle[r][c])
                return false;
        }
    }
    return true;
}

/**
 * Operator overload
 * A friend function that prints to the output stream the current puzzle contents in a nicely
 * formatted manner
 */
std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku)
{
    int row = 0;
    int col = 0;
    while (row <= 8) {
        // if it is at the beginning of the 4th or 7th row then print the "dividers"
        if (col == 0 && (row == 3 || row == 6)) {
            out << "------+-------+------\n";
        }

        // if its at the 4th or 7th column then it needs | before
        if (col == 3 || col == 6) {
            out << "| ";
        }

        // last column doesnt need space at the end but needs to goto next line
        if (col >= 8) {
            // if its 0 then just print a blank
            if (sudoku.puzzle[row][col] == 0)
                out << " \n";
            // otherwise print the actual value
            else
                out << std::to_string(sudoku.puzzle[row][col]) + "\n";
            row++;
            col = 0;
        }
        // normally just print the value followed by a space
        else {
            // if its 0 then just print a blank
            if (sudoku.puzzle[row][col] == 0)
                out << "  ";
            // otherwise print the actual value
            else
                out << std::to_string(sudoku.puzzle[row][col]) + " ";
            col++;
        }
    }
    return out;
}

/**
 * Checks if that value can be placed in that block given the column
 * col - column number
 * val - value
 * return true if it is valid, false otherwise
 */
bool Sudoku::checkCol(int col, int val)
{
    for (int r = 0; r < 9; r++) {
        // if this value is already present in another blocks of this column then return false
        if (puzzle[r][col] == val)
            return false;
    }
    // if passes then return true
    return true;
}

/**
 * Checks if that value can be placed in that block given the row
 * row - row number
 * val - value
 * return true if it is valid, false otherwise
 */
bool Sudoku::checkRow(int row, int val)
{
    for (int c = 0; c < 9; c++) {
        // if this value is already present in another blocks of this row then return false
        if (puzzle[row][c] == val)
            return false;
    }
    // if passes then return true
    return true;
}

/**
 * Checks if a value can be placed in that block given the subgrid that its in (subgrid is
 * determined based on block position)
 *
 * row - the row ([0,8])
 * col- the column ([0,8])
 * val - the value ([1,9]))
 *
  * return true if it is valid, false otherwise
 */
bool Sudoku::checkSubGridValid(int row, int col, int val)
{
    int rowStart = row - (row % 3);
    int rowEnd = rowStart + 3;
    
    int colStart = col - (col % 3);
    int colEnd = colStart + 3;
    
    for (int r = rowStart; r < rowEnd; r++) {
        for (int c = colStart; c < colEnd; c++) {
            // if this value is already on other blocks of the subgrid then return false
            if (puzzle[r][c] == val)
                return false;
        }
    }
    // if passes then return true
    return true;
}
