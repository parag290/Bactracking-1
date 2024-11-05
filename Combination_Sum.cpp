// Apporach 1 and 2 
// Time Complexity : 2^(n+m) ..... 2^n because of making two choices at each element
//                           ..... m is target which is also deciding factor here
// Space Complexity : O(n + m) ......  for call stack
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
/*
Leetcode : 


Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target 
is less than 150 combinations for the given input.
*/

 
 class Solution {
    vector<vector<int>>result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        dfs(candidates, target, 0, path);
        return result;
    }

    void dfs(vector<int> &candidates, int target, int i, vector<int>&path){
        if(target < 0 || i >= candidates.size()){
            return;
        }

        if(target == 0){
            vector<int>storage(path.begin(), path.end());
            result.push_back(storage);
            return;
        }

        //not choosing
        dfs(candidates, target, i+1, path);

        //choosing
        int val = candidates[i];
        path.push_back(val);
        dfs(candidates, target-val, i, path);
        //backtracking
        path.pop_back();
    }
};



/**
 * Approach 2 : DFS using for loop with backtracking 
 * 
*/

class Solution {
    vector<vector<int>>result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        dfs(candidates, target, 0, path);
        return result;
    }

    void dfs(vector<int> &candidates, int target, int pivot, vector<int>&path){
        if(target < 0){
            return;
        }

        if(target == 0){
            vector<int>storage(path.begin(), path.end());
            result.push_back(storage);
            return;
        }

        for(int i = pivot; i < candidates.size(); i++){
            int val = candidates[i];
            path.push_back(val);
            dfs(candidates, target-val, i, path);
            //backtracking
            path.pop_back();
        }
    }
};