> **The Academic Honor Policy (see Brightspace) is applicable to all work you do in CS 3270/5270.**

# CS 3270: Programming Languages
## Project 1

## Goal

Gain experience in advanced C++ OOP programming and recursive backtracking algorithms.

## Assignment

Create a **Sudoku** solver.

Sudoku is a popular puzzle where you fill in numbers on a grid, trying to keep certain conditions true. To learn more about how Sudoku works, check out <http://en.wikipedia.org/wiki/Sudoku>. You'll find a sample puzzle and an explanation of the rules.

Write a C++ class that reads a file containing an unfinished Sudoku puzzle, then solves the puzzle using a recursive backtracking algorithm.

The input file will simply contain the numbers in the puzzle delimited by spaces on each line, where zeroes are used to indicate unknowns. For example, the example puzzle below (from <http://commons.wikimedia.org/wiki/Image:Sudoku-by-L2G-20050714.gif>) would be represented in an input as:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

When your program prints out the Sudoku puzzle, it should print in the format given below. For example, given the following code:

```C++
// Create object.
Sudoku sudoku;
sudoku.loadFromFile("../txt/sudoku-test1.txt");

// Print initial Sudoku puzzle.
std::cout << "Puzzle:\n\n" << sudoku;

// Solve puzzle.
sudoku.solve();

// Print solved Sudoku puzzle.
std::cout << "\nSolution:\n\n" << sudoku;
```

The output will be:

```
Puzzle:

  4 3 |   8   | 2 5
6     |       |
      |     1 |   9 4
------+-------+------
9     |     4 |   7
      | 6   8 |
  1   | 2     |     3
------+-------+------
8 2   | 5     |
      |       |     5
  3 4 |   9   | 7 1

Solution:

1 4 3 | 9 8 6 | 2 5 7
6 7 9 | 4 2 5 | 3 8 1
2 8 5 | 7 3 1 | 6 9 4
------+-------+------
9 6 2 | 3 5 4 | 1 7 8
3 5 7 | 6 1 8 | 9 4 2
4 1 8 | 2 7 9 | 5 6 3
------+-------+------
8 2 1 | 5 6 7 | 4 3 9
7 9 6 | 1 4 3 | 8 2 5
5 3 4 | 8 9 2 | 7 1 6
```

Note: it is okay to have trailing whitespace at the end of each line. For example, it is okay to have three trailing whitespaces after `5` on the first line of the unsolved puzzle above.

## Functional specifications

You are to create a C++ class called `Sudoku`. This class should be implemented in the files `Sudoku.h` and `Sudoku.cpp`. The public interface of this class is as follows:

* `Sudoku()`: Default constructor. Should initialize the object with an empty puzzle (81 zeroes).
* `void loadFromFile(string filename)`: Reinitializes the object with a new puzzle from the specified file. The passed string will be the relative path of the text file (e.g., `"../txt/sudoku1-test.txt"`). You may assume the input file has the specified format. Note: It is recommended that you use the extraction operator to read in the values, as it will automatically skip all white spaces (blanks, newlines) for you.
* `bool solve()`: The entry point for your solver. Returns `true` if a solution was found, otherwise returns `false`. If no solution was found, you may leave the puzzle in either (1) its initial state, or (2) the state when you determined no solution was possible.
* `bool equals(const Sudoku& other) const`: Determines if two puzzles are equal.
* `ostream& operator<<(ostream& out, const Sudoku& sudoku)`: A *friend* function that prints to the output stream `out` the current puzzle contents in a nicely formatted manner as seen above. Instead of printing to `std::cout`, print to the passed output stream `out` and return it.

**DO NOT** add or remove any item in the public interface. However, you may add items in the private interface (e.g., helper functions).

## Grading

Programming style will be a part of your grade so use good style  and document your code with comments. Linter will be one of the test builds on Travis like previous C++ assignments (make sure to run `clang-format`). Also, add block comments to the top of all files that you altered and include an academic honesty statement (as you have done in previous assignments).

For comparison purposes, we will time your solution program. We want this information so that we can compare our C++ code against solutions written in other programming languages. How fast your program finds a solution will not be a part of your grade – unless your solution is grossly inefficient. We will define "grossly inefficient" as being 5x slower than our simple-minded solver, or one that exhausts all stack space. Note that we will test your submission on several more puzzles in addition to the two puzzles provided for you.

An executable version of our solution is available on Brightspace under **Content | Assignments** in the `solution-executables.zip` file. The output of the program includes the time it took to solve a puzzle. You can use this to compare with your solution. Note that the program will ask for the name of the text file containing the puzzle that you want it to solve.

## Deliverables

To make sure everyone is making sufficient progress on this project, we will have two deadlines. The required deliverables for each deadline is given below.

* **Checkpoint deadline**: Submission of code to date on GitHub. The bulk of your code should be written (though not fully operational) at this time. It is okay if the test cases fail for this checkpoint submission (you can disable a Travis build by including `[skip ci]` without the double quotes in any part of your commit message). It is expected that you have completed at least the following at this checkpoint: the constructor, the `loadFromFile()` method, the `equals()` method, and the `operator<<` function. Failure to have made progress to this point will cost you 10% of your final grade on the project.
* **Final deadline**: Final project submission on GitHub.

## Academic honesty

As stated in class, there are many solutions to Sudoku in many different programming languages available on the Internet. Do not look at the code you may find there. Using code that you find on the Internet is unethical, and of course you would miss the learning opportunity that you get by developing this yourselves. This instructor will report any violations to the university's Honor Council.

## Reminders

* Ensure that your name, VUnetID, email address, and the honor code appear in the header comments at the top of `Sudoku.cpp` and `Sudoku.h`.

* You are required to implement `Sudoku.cpp` and `Sudoku.h`. Do not alter any of the existing project files! You must use the supplied `CMakeLists.txt` file as is. You may technically edit files other then `Sudoku.cpp` and `Sudoku.h`, to for example, temporarily disable a test or add some debugging code. However, you must return the files to their original state before your final submission. Failure to do so will result in lost points. Your implementation must run correctly on the original content of the provided files.

* All files necessary to compile and run your program must reside in the GitHub repository.

* For full credit, your program must compile with a recent version of `clang` or `gcc` and run successfully with Travis CI.
  * Your code will be treated as if it failed to compile if you do not turn Travis builds on.

  * You will need to push to GitHub in order to trigger a Travis build.

  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.
