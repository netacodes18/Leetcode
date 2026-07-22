class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int i=0;
        vector<int> inactive;
        int active=count(begin(s),end(s),'1');
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0') i++;
                
                inactive.push_back(i-start);
            }
            else i++;
        }

        int maxL=0;
        for(int i=1;i<inactive.size();i++) maxL=max(maxL,inactive[i]+inactive[i-1]);

        return maxL+active;
    }
};