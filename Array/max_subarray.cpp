#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

// Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int num: nums){
            currSum += num;
            maxSum = max(currSum, maxSum);
            if(currSum < 0){
                currSum = 0;
            }

        }
        return maxSum; 
    }

// Brute Force Approach
int maxSubArray2(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for(int i=0; i<nums.size(); i++){
            int currSum = 0;
            for(int j=i+1; j<nums.size(); j++){
                currSum += nums[j];
                maxSum = max(currSum, maxSum);
            }
        }

        return maxSum; 

        }

};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray2(nums) << endl;
}