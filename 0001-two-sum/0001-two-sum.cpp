class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rem = tar-nums[i];
            if(mp.find(rem)!=mp.end()){
                return {mp[rem],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};