class Solution {
public:
    string countAndSay(int n, string s = "1") {
        if(n==1) return s;
        int count;
        string ans;
        for(int i=0;i<s.size();i++) {
            count=1;
            while(i+1<s.size() && s[i]==s[i+1])
            {
                count++;
                i++;
            }
            ans+= to_string(count) + s[i];
        }
        return countAndSay(n-1, ans);
    }
};
//O(NK) N is n and K is the max length of result string
//O(K) K is the max length of result/temp string
