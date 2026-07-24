class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> s2;
        for(int pairxor:s1){
            for(int i=0;i<nums.size();i++){
                s2.insert(pairxor^nums[i]);
            }
        }
        return s2.size();
    }
};