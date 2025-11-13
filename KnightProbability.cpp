#include <iostream>     // lets us use input and output (like cout)
#include <cstring>      // lets us use memset to clear arrays
using namespace std;    // so we don’t have to write std:: each time

// Create a class called Solution
class Solution {
public:
    // Function that finds the probability that a knight stays on the board
    // n = board size, k = number of moves, row and column = starting position
    double knightProbability(int n, int k, int row, int column) {

        // Make a 3D array to store probabilities
        // dp[m][i][j] means: probability of being at (i, j) after m moves
        double dp[k + 1][n][n]; 

        // Set all values in dp to 0 at the start
        memset(dp, 0, sizeof(dp));

        // The knight starts at (row, column) with 100% chance (probability = 1)
        dp[0][row][column] = 1.0;

        // Arrays that show how the knight moves in 8 directions
        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // Loop through each move number from 1 to k
        for (int moveCount = 1; moveCount <= k; ++moveCount) {

            // Loop through every row on the chessboard
            for (int i = 0; i < n; ++i) {

                // Loop through every column on the chessboard
                for (int j = 0; j < n; ++j) {

                    // Try all 8 possible directions the knight could come from
                    for (int dir = 0; dir < 8; ++dir) {

                        // Find the position the knight could come from
                        int prevRow = i - dx[dir];
                        int prevCol = j - dy[dir];

                        // Check if that previous position is still inside the board
                        if (prevRow >= 0 && prevRow < n && prevCol >= 0 && prevCol < n) {

                            // Add the probability of coming from that position
                            // Divide by 8 because each move has equal chance (1/8)
                            dp[moveCount][i][j] += dp[moveCount - 1][prevRow][prevCol] / 8.0;
                        }
                    }
                }
            }
        }

        // After all moves, add up all probabilities where the knight is still on board
        double ans = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans += dp[k][i][j];

        // Return the final probability result
        return ans;
    }
};
//Main Function
int main() {
    Solution sol;                                   // Create an object of the Solution class
    cout << sol.knightProbability(3, 2, 0, 0)       // Call the function with board size 3x3,
         << endl;                                   // 2 moves, and starting position (0, 0)
}
