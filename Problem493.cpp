/**
 * This problem was asked by Triplebyte.
 * 
 * You are given n numbers as well as n probabilities that sum up to 1. Write a
 * function to generate one of the numbers with its corresponding probability.
 * For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2],
 * your function should return 1 10% of the time, 2 50% of the time, and 3 and
 * 4 20% of the time.
 * You can generate random numbers between 0 and 1 uniformly.
**/

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int getRandomNumber(vector<int> &, vector<int> &);
int binarySearch(vector<int> &probs, int rand_num);

int main() {
  vector<int> nums {1, 2, 3, 4};
  // vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  vector<int> probs {10, 50, 20, 20};   // probs in unit of out of 100.
  // vector<int> probs {0, 50, 0, 50};
  // vector<int> probs {10,30,10,0,0,0,20,0,0,0,30};

  srand(time(NULL));        // https://www.learncpp.com/cpp-tutorial/random-number-generation/ 
  rand();

  cout<<"Random number: "<<getRandomNumber(nums, probs);

  return 0;
}

int getRandomNumber(vector<int> &nums, vector<int> &probs) {
  vector<int> probs_prefix_sum;
  
  probs_prefix_sum.push_back(probs[0]);
  for(int i=1; i<probs.size(); i++)
    probs_prefix_sum.push_back(probs_prefix_sum[i-1]+probs[i]);

  // get a random number between 0 and 1 & then convert it to 
  // a random number between 0 to 100.
  int rand_num = ((double) rand() / (RAND_MAX))*100;

  int num_index = binarySearch(probs_prefix_sum, rand_num);

  return nums[num_index];
}

int binarySearch(vector<int> &numbers, int target) {
  int l = 0, r = numbers.size()-1;

  if(target==0) {
    while(numbers[l]==0)
      l++;
    return l;
  }
  
  while(l<=r && r>0) {
    int mid = (l+r)/2;
    if(mid>0 && target>numbers[mid-1] && target<=numbers[mid])
      return mid;
    if(target>numbers[mid] && mid<numbers.size()-1 && target<=numbers[mid+1])
      return mid+1;
    if(target<=numbers[mid])
      r = mid;
    else if(target>numbers[mid])
      l = mid+1;
  }

  return l;
}
