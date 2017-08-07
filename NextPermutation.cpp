class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        
        if (sz <= 1) return;
            
        int k,l;   
      
        for (k = (sz-2);k>=0;--k)
        {
            if (nums[k] < nums[k+1])
                break;
        }
        
        if (k < 0)
        {
            //reverse all the nums.
            for (int i=0;i<sz/2;++i)
            {
                swap(nums[i],nums[sz-1-i]);
            }
            return;
        }
        
        if (k == (sz-2) && (nums[k] == nums[k+1]))
            return;

        for (l=sz-1;l>k;--l)
        {
            if (nums[k]<nums[l])
                break;
        }

        swap(nums[k], nums[l]);

        for (int i=k+1;i<(sz+k+1)/2;++i)
        {
            swap(nums[i],nums[sz+k-i]);
        }

            
        return;        
    }
};