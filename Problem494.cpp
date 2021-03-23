/**
 * This problem was asked by Facebook.
 * 
 * Given a circular array, compute its maximum subarray sum in O(n) time. A
 * subarray can be empty, and in this case the sum is 0.
 * For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4,
 * and 8 where the 8 is obtained from wrapping around.
 * Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
**/

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &nums);

int main() {
  vector<int> nums {8, -1, 3, 4};
  // vector<int> nums {-4, 5, 1, 0};
  // vector<int> nums {8, -1, 3, 4, -2, 6, -15};
  // vector<int> nums {8, -12, 9};

  cout<<"Maximum subarray sum: "<<maxSubarraySum(nums);

  return 0;
}

int maxSubarraySum(vector<int> &nums) {
  vector<int> extend_nums(nums);
  extend_nums.insert(extend_nums.end(),nums.begin(),nums.end());
  
  int maxSum = 0, sum = 0, l = 0, i = 0;
  while(i<extend_nums.size()) {
    if(sum+extend_nums[i]<=0) {
      sum = 0;
      l = i+1;
    } else {
      sum += extend_nums[i];
      if(i-l>=nums.size()) {
        sum -= extend_nums[l++];
        while(extend_nums[l]<=0 && l<i) {
          sum -= extend_nums[l++];
        }
      }
      if(sum>maxSum)
        maxSum = sum;
    }
    i++;
  }
  
  return maxSum;
}