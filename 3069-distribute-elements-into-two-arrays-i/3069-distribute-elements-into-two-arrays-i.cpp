class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int x=2;
 
        while(x<n){
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
                arr1.push_back(nums[x++]);
            }
            else arr2.push_back(nums[x++]);
        }

        vector<int> result;

        for(int a:arr1) result.push_back(a);
        for(int b:arr2) result.push_back(b);

        return result;
    }
};