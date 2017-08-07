class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if (nums.size() == 0) return 1;
        int res = 1;
        
        sort(nums.begin(),nums.end());
        
        int i;
        for (i=0;i<nums.size();++i)
        {
                if ((nums[i] != res))
                {
                    if ((nums[i] <= 0) || (nums[i] <= res))
                    {
                        continue;
                    }
                    else
                        return res;
                }
                else
                    ++res;
        }
        
        if(i == nums.size() && (res == nums[i-1]))
            return (res+1);
        
        if ((i == nums.size())  && 0 == nums[i-1])
            return res;
        
        if ((i == nums.size()) && (nums[i-1]>res))
            return res;
        
        return res;
        
    }
};