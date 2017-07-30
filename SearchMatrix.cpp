class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> nums;
        
        for (int i=0;i<matrix.size();++i)
        {
            for (int j=0;j<matrix[0].size();++j)
                nums.push_back(matrix[i][j]);
        }
        
        if (find(nums.begin(),nums.end(),target) != nums.end())
            return true;
        else
            return false;
        
    }
};