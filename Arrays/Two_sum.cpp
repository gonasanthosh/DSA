/*
========================================================
Problem: Two Sum
Platform: LeetCode
Topic: Arrays + Hashing
Difficulty: Easy

Approach:
- Use unordered_map to store:
      number -> index

- For every element:
      needed = target - current number

- Check if needed value already exists in hashmap.
- If exists:
      return both indices.

Time Complexity:
      O(n)

Space Complexity:
      O(n)
========================================================
*/

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {

public:

    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        // hashmap:
        // key   -> number
        // value -> index
        std::unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            // number needed to reach target
            int need = target - nums[i];

            // if needed number already exists
            if(mp.find(need) != mp.end()) {

                // return indices
                return {mp[need], i};
            }

            // store current number and index
            mp[nums[i]] = i;
        }

        // no solution found
        return {};
    }
};

int main() {

    std::vector<int> nums {1, 2, 4, 5, 8, 9};

    int target = 7;

    Solution s1;

    // store returned vector
    std::vector<int> result = s1.twoSum(nums, target);

    // print result
    std::cout << "[" << result[0]
              << ", "
              << result[1]
              << "]" << std::endl;

    return 0;
}