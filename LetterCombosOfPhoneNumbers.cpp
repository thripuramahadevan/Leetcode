class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string two = "abc";
        string three = "def";
        string four = "ghi";
        string five = "jkl";
        string six = "mno";
        string seven = "pqrs";
        string eight = "tuv";
        string nine = "wxyz";
        
        vector<string> res_str;
        
        vector<string> res;
        
        for (int i=0;i<digits.length();++i)
        {
            switch(digits[i])
            {
                case '2':
                    {
                        res.push_back(two);
                        break;
                    }
                    case '3':
                    {
                        res.push_back(three);
                        break;
                    }
                    case '4':
                    {
                        res.push_back(four);
                        break;
                    }
                    case '5':
                    {
                        res.push_back(five);
                        break;
                    }
                    case '6':
                    {
                        res.push_back(six);
                        break;
                    }
                    case '7':
                    {
                        res.push_back(seven);
                        break;
                    }
                    case '8':
                    {
                        res.push_back(eight);
                        break;
                    }
                    case '9':
                    {
                        res.push_back(nine);
                        break;
                    }
                default:
                    break;
            }
        }
        vector<string> s1;
        string s2;
        for (int i = 0; i < res.size();++i)
        {
            if (i == 0)
            {
                for (int j=0;j<res[0].size();++j)
                {
                    stringstream ss;
                    string tstr;
                    ss << res[0][j];
                    ss >> tstr;
                    res_str.push_back(tstr);
                }
                    
            }
            else
            {
                s1.clear();
                for (string s: res_str)
                    s1.push_back(s);
                res_str.clear();
                s2 = res[i];
                
                for (int a=0;a<s2.length();++a)
                {
                    for (int b=0;b<s1.size();++b)
                        res_str.push_back(s1[b]+s2[a]);
                }
            }
            
        }
        
        return res_str;
        
    }
};