class Solution {
public:
    bool isPal(string s)
    {
        if (s.length() == 0) return true;
        int len = (int)s.length();
        for (int i=0, j=s.size()-1;i<j;++i, --j)
        {
            while (isalnum(s[i]) == false && i<j) ++i;
            while (isalnum(s[j]) == false && i<j) --j;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true; 
    }
    
    int countSubstrings(string s) {
        int count = 0;
        
        count += s.length();
        
        int len = s.length();
        
        for (int i=0;i<len;++i)
        {
            for (int j=2;j+i<=len;++j)
            {
                if (isPal(s.substr(i,j)))
                    ++count;
            }
        }
        return count;
    }
};