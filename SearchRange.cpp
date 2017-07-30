class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if (find(nums.begin(),nums.end(),target) == nums.end())
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        size_t pos = find(nums.begin(),nums.end(),target)-nums.begin();;
        res.push_back(pos);
        size_t lastPos = pos;
        
        while (pos+nums.begin() != nums.end())
        {
            pos = find(nums.begin()+lastPos+1,nums.end(),target)-nums.begin();
            if (pos+nums.begin() != nums.end())
                lastPos = pos;
        }
        res.push_back(lastPos);
        return res;
    }
};