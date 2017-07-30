class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> allP;
        vector<int> perm;
        
        sort(nums.begin(),nums.end());
        do
        {
            if (find(res.begin(),res.end(),nums) == res.end())
                res.push_back(nums);
        } while(next_permutation(nums.begin(),nums.end()));
        
        return res;
        
    }
};