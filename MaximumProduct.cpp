class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3,res;
        
        sort(nums.begin(),nums.end());
        
        max1 = nums[nums.size()-1];
        max2 = nums[nums.size()-2];
        max3 = nums[nums.size()-3];
            
        if (nums[0] >= 0)
        {
            
            res = max1*max2*max3;
        }
        else if (nums[0] < 0 && nums[1] < 0)
        {
            res = nums[0] * nums[1] * nums[nums.size()-1];
            if (res < (max1*max2*max3))
                res = max1*max2*max3;
        }
        else if(nums[0] < 0 && nums[1] > 0)
        {
            res = max1*max2*max3;
        }
        
        
        
        return res;
        
    }
};