class Solution {
public:
    int fact(int num)
    {
        if (num <= 1)
            return 1;
        else
            return (num*fact(num-1));
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        
        int sz = nums.size();
        
        sort(nums.begin(),nums.end());
        
        res.push_back(nums);
        
        if (sz <= 1) 
        {
            return res;
        }
        
        int numPerm = fact(sz);
        int k,l;
        
         for (int a=1;a<numPerm;++a)
        {
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
            return res;
        }
        
        if (k == (sz-2) && (nums[k] == nums[k+1]))
            return res;

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
        
        if(find(res.begin(),res.end(),nums) == res.end())
            res.push_back(nums);
        }
        
        
        
        return res;
    }
};