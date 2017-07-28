class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> numArr;
        
        cout << pairs.size() << " ";
        
        vector<vector<int>> nums;
        
        int count = 0;
        
        for (int i=0;i<pairs.size();++i)
        {
            for (int j=0;j<2;++j)
            {
                numArr.push_back(pairs[i][j]);
            }
        }
        
        sort(numArr.begin(),numArr.end());
        
        //for (auto num : numArr)
            //cout << num << " ";
        int j = 0,last = -1;
        
        while (j < (2*pairs.size()))
        {
            //cout << "nArr " << numArr[j] << " ";
            int i;
            for (i = 0; i < (pairs.size());++i)
            {
                //cout << "p " << pairs[i][0] << " ";
                
                if ((pairs[i][0] == numArr[j]) && (pairs[i][1] >= numArr[j+1]))
                {
                    cout << "Pushing " << pairs[i][0] << " and " << pairs[i][1] << " ";
                    nums.push_back(pairs[i]);
                    ++count;
                    last = pairs[i][1];
                    j+=2;                    
                    break;
                }
                else
                    continue;                
            }
            if (i == pairs.size() && last < numArr[j])
                j += 2;
            else
            {
                while ((numArr[j] <= last))
                    j+=2;
            }
        
        }
        
        
        return count;
    }
};