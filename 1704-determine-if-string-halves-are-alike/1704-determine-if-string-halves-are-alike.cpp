class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int vow=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')
            vow++;
        }
        int vow2=0;
        for(int i=n/2;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')
            vow2++;
        }

        if(vow==vow2) return true;

        return false;
    }
};