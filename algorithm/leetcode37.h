//
// Created by Oliver on 2025/6/9.
//

#ifndef LEETCODE37_H
#define LEETCODE37_H

#include "../util.h"

namespace LeetCode37 {
    class Solution {
    private:
        bool found = false;
    public:
        void solveSudoku(vector<vector<char>>& board) {
            backTrack(board, 0);
        }

        bool isValid(vector<vector<char>>& board, int row, int col, char num) {
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == num) {
                    return false;
                }

                if (board[i][col] == num) {
                    return false;
                }

                if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) {
                    return false;
                }
            }
            return true;
        }

        void backTrack(vector<vector<char>>& board, int index) {
            int row = index / 9;
            int col = index % 9;
            if (found) return;

            if (index == 81) {
                found = true;
                return;
            }

            if (board[row][col] != '.') {
                backTrack(board, index + 1);
                return;
            }

            for (char c = '1'; c <= '9'; c++) {
                if (!isValid(board, row, col, c)) {
                    continue;
                }

                board[row][col] = c;

                backTrack(board, index + 1);

                if (found) return;
                board[row][col] = '.';
            }
        }
    };
}

#endif //LEETCODE37_H
