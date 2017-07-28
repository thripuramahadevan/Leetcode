class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> perm;
        
        sort(nums.begin(),nums.end());
        
        do{
            perm.clear();
            for (auto num : nums)
                perm.push_back(num);
            res.push_back(perm);
        } while (std::next_permutation(nums.begin(),nums.end()));
       return res; 
    }
};