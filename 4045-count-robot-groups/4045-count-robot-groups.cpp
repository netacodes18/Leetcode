class Solution {
public:
    int countGroups(vector<int>&position,vector<int>&speed,int distance) {
        int n = position.size();
        int ans = 1;
        int sp = speed[n-1];
        for(int i = n-2;i>=0;i--){
            if(position[i+1]-position[i] > distance && sp >= speed[i]){
                sp = speed[i];
                ans++;
            }
        }
        return ans;
    }
};