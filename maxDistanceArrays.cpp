class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max = -10000, min = 10000, diff = 0;
        
        int result = 0;
        
        for (int i=0;i<arrays.size();++i)
        {
            for (int j=0;(j!=i)&& (j<arrays.size());++j)
            {
                if (arrays[j][arrays[j].size()-1]-arrays[i][0] > diff)
                    diff = arrays[j][arrays[j].size()-1]-arrays[i][0];
                if (arrays[i][arrays[i].size()-1]-arrays[j][0] > diff)
                    diff = arrays[i][arrays[i].size()-1]-arrays[j][0];
            }
            
                
        }
        
        return diff;
    }
};