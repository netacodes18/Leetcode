class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();

        vector<int> start(26,-1);
        vector<int> end(26,-1);
        vector<bool> isValid(26,true);

        for(int i=0;i<n;i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }

        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;
            for(int i=start[c];i<end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isValid[c]=false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
        }

        int last=INT_MAX;

        vector<string> res;

        for(int i=n-1;i>=0;i--){
            int c=s[i]-'a';
            if(isValid[c]==false) continue;

            if(i==start[c] && end[c]<last){
                res.push_back(s.substr(i,end[c]-i+1));
                last=i;
            }
        }
        return res;
    }
};