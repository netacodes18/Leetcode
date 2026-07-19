class Solution {
public:
    string smallestSubsequence(string s) {
     int n=s.length();
        vector<int> last(26,-1);
        vector<bool> taken(26,false);

        for(int i=0;i<n;i++){
            char ch=s[i];
            last[ch-'a']=i;
        }

        string ans="";

        for(int i=0;i<n;i++){
            char idx=s[i]-'a';
            char ch=s[i];
            if(taken[idx]==true) continue;
            
            while(ans.length()>0 && last[ans.back()-'a']>i && ans.back()>ch){
                 taken[ans.back()-'a']=false;
                 ans.pop_back();
            }
            ans.push_back(ch);
            taken[idx]=true;
        }

        return ans;   
    }
};