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
  vector<int> probs {10, 50, 20, 20};   // probs in unit of out of 100.
  
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
  // 10 60  80  100   // 70
  
  while(l<=r) {
    int mid = (l+r)/2;
    if(target<=numbers[l])
      return l;
    if(r>0 && target>numbers[r-1])
      return r;
    if(target==numbers[mid])
      return mid;
    if(target>numbers[mid])
      l = mid;
    else if(target<numbers[mid])
      r = mid;
  }

  return l;
}
