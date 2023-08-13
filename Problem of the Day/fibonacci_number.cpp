/*
Nth Fibonacci Number

https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
*/

class Solution {
  public:
    int nthFibonacci(int n){
        
        int a = 0, b = 1;
        
        if(n <= 1) return n;
        
        int c;
        
        for(int i = 2; i <= n; i++){
            c = (a+b)%1000000007;
            a = b;
            b = c;
        }
        
        return c;
    }
};
