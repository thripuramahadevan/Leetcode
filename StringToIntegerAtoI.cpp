class Solution {
public:
    int myAtoi(string str) {
        
        int len = str.length();
        
        if (len == 0) return 0;
        
        stringstream ss;
        
        ss << str;
        
        int num;
        ss >> num;
        
        return num;
        
    }
};