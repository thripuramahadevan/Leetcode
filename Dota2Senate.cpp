class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        int countR = std::count(senate.begin(),senate.end(),'R');
        int countD = std::count(senate.begin(),senate.end(),'D');
        
        string skip(len,'f');
        
        int skipCount = 0;
        int skipCountR = 0;
        int skipCountD = 0;
        
        while(true)
        {
            for (int i=0;i<len;++i)
            {
                if (skip[i] == 't')
                    continue;
                else if((senate[i] == 'R') && (skipCountD == countD))
                    return "Radiant";
                else if((senate[i] == 'D') && (skipCountR == countR))
                        return "Dire";
                else if (senate[i] == 'R')
                {
                    bool done = false;
                    for(size_t pos=senate.find('D',i+1); pos!=std::string::npos; pos=senate.find('D',pos+1)) 
                    {
                        if(skip[pos] == 't')
                            continue;
                        else
                        {
                            //cout << "Found D at " << pos << " ";
                            skip[pos] = 't';
                            ++skipCount;
                            ++skipCountD;
                            done = true;
                            break;
                        }
                    }
                    if (!done)
                    {
                        for (size_t pos = senate.find('D',0); pos<i;pos=senate.find('D',pos+1))
                        {
                            if(skip[pos] == 't')
                                continue;
                            else
                            {
                                //cout << "Found D at " << pos << " ";
                                skip[pos] = 't';
                                ++skipCount;
                                ++skipCountD;
                                done = true;
                                break;
                            }   
                        }
                    }
                }
                else
                {
                    bool done = false;
                    for(size_t pos=senate.find('R',i+1); pos!=std::string::npos; pos=senate.find('R',pos+1)) 
                    {
                        if(skip[pos] == 't')
                            continue;
                        else
                        {
                            //cout << "Found R at " << pos << " ";
                            skip[pos] = 't';
                            ++skipCount;
                            ++skipCountR;
                            done = true;
                            break;
                        }
                    }
                    if (!done)
                    {
                        for (size_t pos = senate.find('R',0); pos<i;pos=senate.find('R',pos+1))
                        {
                            if(skip[pos] == 't')
                                continue;
                            else
                            {
                                //cout << "Found R at " << pos << " ";
                                skip[pos] = 't';
                                ++skipCount;
                                ++skipCountR;
                                done = true;
                                break;
                            }   
                        }
                    }
                }                    
            }
        }                    
        return "";
    }
};