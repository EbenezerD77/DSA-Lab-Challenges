
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         // Create a map to store the complement (target - current number) and its index.
        // This allows for efficient lookup of the complement.
        map<int, int> complements;

         // Iterate through the input vector 'nums'.
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current number 'nums[i]' exists as a complement in the map.
            // If it does, it means we have found the two numbers that add up to the target.
            auto complementIndex = complements.find(nums[i]);
            if (complementIndex != complements.end()) {
                // Return the indices of the two numbers.
                // complementIndex->second gives the index of the complement.
                // i gives the index of the current number.
                return {complementIndex -> second, i};  
            }
            // If the current number is not a complement, store its complement (target - nums[i])
            // and its index in the map.
            // This allows us to quickly check if a future number is the complement of the current one.
            complements[target - nums[i]] = i;
        }

        // If no solution is found, return an empty vector.
        // According to the problem's constraints, there will always be exactly one solution,
        // so this line should ideally not be reached.
        return {};  
    }
};

