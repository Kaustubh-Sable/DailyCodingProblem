/**
 * Problem Statement:
 * Write a program that checks whether an integer is a palindrome. For example,
 * 121 is a palindrome, as well as 888. 678 is not a palindrome. Do not convert
 * the integer into a string.
**/

#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(int);
bool isPalindrome_optimized(int);

int main() {
  int num = 121;
  if(isPalindrome_optimized(num))
    cout<<"The number is a palindrome.";
  else 
    cout<<"The number is not a palindrome.";

  return 0;
}

bool isPalindrome(int num) {
  if(num<0)
      return false;
  
  stack<int> s;
  int n = num;
  while(n>0) {
      s.push(n%10);
      n/=10;
  }
  
  int n_digits = s.size();
  
  while(!s.empty())
      s.pop();
  
  n = num;
  for(int i=0;i<n_digits/2;i++) {
      s.push(n%10);
      n/=10;
  }
  
  if(n_digits%2!=0)
      n/=10;
  
  for(int i=0;i<n_digits/2;i++) {
      if(s.top()!=n%10)
          return false;
      s.pop();
      n/=10;
  }
  
  return true;
}

bool isPalindrome_optimized(int num) {
  if(num<0 || (num%10==0 && num!=0))
      return false;
  
  int reverse = 0;
  while (num>reverse) {
      reverse = reverse*10 + num%10;
      num /= 10;
  }
  
  return num==reverse || num==reverse/10;
}
