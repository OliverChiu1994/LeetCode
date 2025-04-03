//
// Created by Oliver on 2025/4/2.
//

#ifndef LEETCODE40_H
#define LEETCODE40_H

#include <vector>
#include "util.h"

using namespace std;

namespace LeetCode40 {
    class Solution {
    private:
        vector<vector<int>> res;
        vector<int> curVec;

        vector<vector<int>> freq;
    public:
        void dfs(int index, int target) {
            if (target == 0) {
                res.push_back(curVec);
                return;
            }
            if (index == freq.size() || target < freq[index][0]) {
                return;
            }
            dfs(index + 1, target);

            int maxTime = min(target / freq[index][0], freq[index][1]);
            for (int i = 1; i <= maxTime; i++) {
                curVec.push_back(freq[index][0]);
                dfs(index + 1, target - freq[index][0] * i);
            }
            for (int i = 1; i <= maxTime; i++) {
                curVec.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            for (int i = 0; i < candidates.size(); i++) {
                if (i == 0) {
                    freq.push_back({candidates[i], 1});
                    continue;
                }
                if (candidates[i] == freq.back()[0]) {
                    freq.back()[1]++;
                } else {
                    freq.push_back({candidates[i], 1});
                }
            }
            dfs(0, target);
            return res;
        }
    };

    void test() {
        vector<int> candidates{10,1,2,7,6,1,5};
        Solution s;
        auto res = s.combinationSum2(candidates, 8);
        print(res);
    }
}

#endif //LEETCODE40_H
