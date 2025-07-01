
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void func(vector<vector<char>> &path, vector<vector<int>> &maze, vector<char> &multi, int x, int y) {
        int n = maze.size();

        // Check if reached the bottom-right corner
        if (x == n - 1 && y == n - 1) {
            path.push_back(multi);
            return;
        }

        // Mark the current cell as visited
        maze[x][y] = 0;

        // Explore all possible directions
        if (x + 1 < n && maze[x + 1][y] == 1) {
            multi.push_back('D');
            func(path, maze, multi, x + 1, y);
            multi.pop_back(); // backtrack
        }
        if (x - 1 >= 0 && maze[x - 1][y] == 1) {
            multi.push_back('U');
            func(path, maze, multi, x - 1, y);
            multi.pop_back(); // backtrack
        }
        if (y + 1 < n && maze[x][y + 1] == 1) {
            multi.push_back('R');
            func(path, maze, multi, x, y + 1);
            multi.pop_back(); // backtrack
        }
        if (y - 1 >= 0 && maze[x][y - 1] == 1) {
            multi.push_back('L');
            func(path, maze, multi, x, y - 1);
            multi.pop_back(); // backtrack
        }

        // Unmark the current cell as visited (backtrack)
        maze[x][y] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<char> multi;
        vector<vector<char>> path;
        vector<vector<int>> maze = m; // Make a copy of maze

        // Check if the starting point is accessible
        if (maze[0][0] == 1) {
            int x = 0;
            int y = 0;

            func(path, maze, multi, x, y);
        }

        // Convert vector<vector<char>> path to vector<string> result
        vector<string> result;
        for (auto &vec : path) {
            string s(vec.begin(), vec.end());
            result.push_back(s);
        }

        return result;
    }
};
