class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = -1;
            
        if (find(nums.begin(),nums.end(),target) != nums.end())
        {
            return (find(nums.begin(),nums.end(),target)-nums.begin());
        }
        return pos;
    }
};