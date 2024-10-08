class Solution {
public:
    int solve(vector<int>&nums , int target , int i){
        if(i == nums.size()) return target == 0 ? 1 :0;

        int plus = solve(nums , target -nums[i] , i+1);
        int minus = solve(nums , target + nums[i] , i+1);
        return plus + minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
        
    }
};


class Solution {
public:
// we can also use{i , target}
    int solve(vector<int>&nums , int target , int i , map<pair<int , int> , int>&dp){
        if(i == nums.size()) return target == 0 ? 1 :0;
        if(dp.find({target , i }) != dp.end()) return dp[{target , i}];

        int plus = solve(nums , target -nums[i] , i+1 , dp);
        int minus = solve(nums , target + nums[i] , i+1 ,dp);
        return dp[{target , i }] = plus + minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        map<pair<int , int> , int>dp; //{i , target} -> no. of ways 
        return solve(nums , target , 0 , dp);
        
    }
};

class Solution {
public:
    int solve(vector<int>&nums , int target){
        map<pair<int , int> , int>dp;
        dp[{nums.size() , 0}] = 1 ;

        int total = 0;
        for(auto num:nums) total +=num;

        for(int i = nums.size() -1 ; i>=0 ; --i){
            for(int sum = -total ; sum<=total ; ++sum){
                //if(dp.find({target , i }) != dp.end()) return dp[{target , i}];

                int plus = dp.find({i+1 , sum-nums[i]}) != dp.end() ? dp[{i+1,sum-nums[i]}] : 0;
                int minus = dp.find({i+1 , sum+nums[i]}) != dp.end() ? dp[{i+1,sum+nums[i]}] : 0;
                dp[{i,sum}] = plus + minus ;
    
            }

        }
        return dp[{0 ,target}];
    }        
        
    int findTargetSumWays(vector<int>& nums, int target) {

       // map<pair<int , int> , int>dp; //{i , target} -> no. of ways 
        return solve(nums , target);
        
    }
};



