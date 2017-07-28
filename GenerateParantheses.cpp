#include <algorithm>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        string parStr;
        
        for (int i=0;i<n;++i)
            parStr += "()";
        
        sort(parStr.begin(),parStr.end());
        do 
        {
            //cout << parStr << " ";
            int numOpen = 0,i;
            for (i=0;i<parStr.length();++i)
            {
                if (parStr[i] == '(')
                    ++numOpen;
                else if(numOpen == 0)
                    break;
                else
                    --numOpen;
            }
            if ((numOpen == 0) && (i == parStr.length())) res.push_back(parStr);
        } while(std::next_permutation(parStr.begin(), parStr.end()));
        
        return res;
    }
};