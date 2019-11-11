class Solution {
public:
    string minWindow(string s, string t)
    {
        
        unordered_map<char,int>hash;
        for(int i=0;i<t.size();i++)
        {
            if(hash.find(t[i])==hash.end())
            {
                hash[t[i]]=1;
            }
            else
            {
                hash[t[i]]++;
            }
        }
        int i=0;
        int cnt=0;
        int L=-1;
        int len=INT_MAX;
        int start=0;
        while(i<s.size())
        {
            if(hash.find(s[i])!=hash.end())
            {
                hash[s[i]]--;
                if(hash[s[i]]==0)
                {
                    cnt++;
                }
            }
            while(cnt==hash.size()&&start<=i)
            {
                //update window
                int tmpL=i-start+1;
                if(tmpL<len)
                {
                    len=tmpL;
                    L=start;
                }
                //update table
                if(hash.find(s[start])!=hash.end())
                {
                    hash[s[start]]++;
                    if(hash[s[start]]==1)
                        cnt--;
                }
                start++;
            }
            i++;
        }
        if(L==-1)return "";
        return s.substr(L,len);
        
    }
};
