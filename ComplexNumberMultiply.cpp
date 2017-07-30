class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,b1,c1,d1, a11,b11;
        
        stringstream ss;
        
        string str, res;
        
        size_t pos = a.find("+",0);
        str = a.substr(0,pos);
        ss << str;
        ss >> a1;
        str.clear();
        ss.clear();
        size_t pos2 = a.find('i');
        str = a.substr(pos+1,pos2-pos-1);
        cout << "str=" << str << " ";
        if(str[0] == '-')
        {
            str = str.substr(1);
            ss << str;
            ss >> b1;
            b1 = -b1;
        }
        else
        {
            ss << str;
            ss >> b1;
        }
        
        str.clear();
        ss.clear();
        pos = b.find("+",0);
        str = b.substr(0,pos);
        //cout << "str=" << str << " ";
        ss << str;
        ss >> c1;
        str.clear();
        ss.clear();
        pos2 = b.find('i');
        //cout << "pos " << pos << "," << pos2 << " ";
        str = b.substr(pos+1,pos2-pos-1);
        //cout << "str=" << str << " ";
        if(str[0] == '-')
        {
            str = str.substr(1);
            ss << str;
            ss >> d1;
            d1 = -d1;
        }
        else
        {
            ss << str;
            ss >> d1;
        }
            
        cout << a1 << "," << b1 << "," << c1 << "," << d1 << " ";
        
        a11 = (a1)*(c1) - (b1)*(d1);
        b11 = (a1)*(d1) + (b1)*(c1);
        
        res = to_string(a11) + "+" + to_string(b11) + "i";
        
        return res;
        
    }
};