
/*

Leetcode - https://leetcode.com/problems/expression-add-operators/

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

 

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.





Watch video for more understanding : https://www.youtube.com/watch?v=xHkzICxwCP4

*/




class Solution {
public:
    vector<string> ans;
    
    vector<string> addOperators(string s, int target) {
        helper(s,target, 0, "", 0, 0);
        return ans;
    }
    void helper(string s, int target,int i, const string& path, long eval, long residual) {
        // bc
        if(i==s.length()){
            if(eval==target){
                ans.push_back(path);
                return;
            }
        } 
        string currStr;
        long num=0;
        // backtracking loop
        for(int j=i;j<s.length();j++){
            // handle 0
            if(j>i && s[i]=='0') return;
            currStr+= s[j]; 
            num= num*10 + s[j]- '0';
            if(i==0){
                helper(s,target, j+1,path+ currStr,num, num);
            }
            else{
                helper(s,target,j+1,path + "+" + currStr, eval + num, num);
                helper(s,target,j+1,path + "-" + currStr, eval - num, -num);
                helper(s,target,j+1,path + "*" + currStr, eval -residual + residual*num , residual*num);

            }
        }
        
        
    }
};