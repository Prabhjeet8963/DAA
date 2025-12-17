# Palindrome Partitioning Project

## Design and Analysis of Algorithms (DAA) Lab

### Objective
The primary objective of this project is to analyze and implement the Palindrome Partitioning problem. This work demonstrates the application of Dynamic Programming and Backtracking to solve combinatorial optimization problems efficiently.

### Problem Statement
Given a string `s`, the goal is to partition `s` such that every substring of the partition is a palindrome. The algorithm must identify all possible partition schemes.

### Algorithmic Approach
This project implements an optimized solution using a hybrid of Dynamic Programming (DP) and Depth First Search (DFS).

1.  **Dynamic Programming (Precomputation)**:
    A 2D boolean table `pal[n][n]` is constructed where `pal[i][j]` is true if the substring `s[i...j]` is a palindrome. This table is built in a bottom-up manner.
    -   **Base Case**: Single characters are always palindromes.
    -   **Recursive Step**: `s[i...j]` is a palindrome if `s[i] == s[j]` and the inner substring `s[i+1...j-1]` is also a palindrome.
    This reduces the palindrome check complexity from O(n) to O(1) during the partitioning phase.

2.  **Backtracking (Partitioning)**:
    A recursive function traverses the string. At each index `start`, it iterates through all possible end indices `i`. If `pal[start][i]` is true, the substring `s[start...i]` is added to the current partition, and the function recurses for the remaining string.

### Research Insights
Based on the analysis of the associated research literature, the following observations guided the implementation:
-   **Overlapping Subproblems**: Naive recursive checking re-evaluates the same substrings multiple times. DP eliminates this redundancy.
-   **Worst-Case Complexity**: The number of partitions can be exponential, specifically O(n * 2^n) in the worst case (e.g., a string of identical characters).
-   **Space-Time Tradeoff**: Using O(n^2) space for the DP table is a justifiable tradeoff to achieve O(1) query time for palindrome checks, which is critical for larger inputs.

### Project Structure
-   **Palindrome.html**: A web-based visualizer that allows users to interactively test the algorithm. It includes controls for result limits and displays distinct palindromic substrings found.
-   **Palindrome.cpp**: A C++ implementation of the core logic, mirroring the algorithmic approach used in the visualizer for consistency.

### Usage
1.  **Visualizer**: Open `Palindrome.html` in a web browser. Enter a string and click "Partition" to observe the results. Use the limit controls to manage output size.
2.  **C++ Program**: Compile `Palindrome.cpp` using a standard C++ compiler (e.g., `g++ Palindrome.cpp -o palindrome`) and run the executable to process inputs via the command line.
