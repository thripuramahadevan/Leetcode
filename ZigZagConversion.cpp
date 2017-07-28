class Solution {
public:
    string convert(string s, int numRows) {
        
        int len = s.length();
                
        if ((numRows > len) || (numRows == 1)) return s;
        
        vector<string> res(numRows);
        string result;
        
        int j = 0;
        bool inc = true;
        int i=0;
        while (s[i] != '\0')
        {
            res[j] += s[i];
            if (j == 0)
            {
                inc = true;
                ++j;
            }
            else if(j == numRows-1)
            {
                --j;
                inc = false;
            }
            else if(inc)
                ++j;
            else
                --j;
            ++i;
        }
        for (int i=0;i<numRows;++i)
        {
            result += res[i];
        }
        return result;
    }
};