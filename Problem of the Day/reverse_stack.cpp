/*
Reverse a Stack

https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
*/

class Solution{
public:

    void insert(stack<int>& St, int num){
        if(St.empty()){
            St.push(num);
            return;
        }
        
        int temp = St.top();
        St.pop();
        
        insert(St, num);
        
        St.push(temp);
    }

    void Reverse(stack<int> &St){
        
        if(St.empty()){
            return;
        }
        
        int temp = St.top();
        St.pop();
        
        Reverse(St);
        
        insert(St, temp);
    }
};
