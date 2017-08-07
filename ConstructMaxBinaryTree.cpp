/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>

class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int sz = nums.size();
        
        vector<int> nodes, sortedNums(sz);
        
        TreeNode *root, *node, *curr;
        
        for (int i=0;i<sz;++i)
            sortedNums[i] = nums[i];
        
        mergeSort(sortedNums,0,sz-1); 
        
        node = new TreeNode(sortedNums[sz-1]);
        root = node;
        
        
        int rootPos = find(nums.begin(),nums.end(),sortedNums[sz-1])-nums.begin();
        for (int b=sz-2;b>=0;--b)
        { 
            int pos = find(nums.begin(),nums.end(),sortedNums[b])-nums.begin();
        
                       
            curr = root;
            
            int newRootPos = rootPos;
            node = new TreeNode(sortedNums[b]);
            
            while (true)
            {
                if(pos < newRootPos)
                {
                    
                   
                    if (curr->left == NULL)
                    {
                        curr->left = node;
                        //cout << "Adding " << sortedNums[b];
                        break;
                    }
                    else
                    {
                        curr = curr->left;
                        newRootPos = find(nums.begin(),nums.end(),curr->val)-nums.begin();
                    }
                }   
                else
                {
                    if (curr->right == NULL)
                    {    
                        curr->right = node;
                        //cout << "Adding " << sortedNums[b];
                        break;
                    }
                    else
                    {
                        curr = curr->right;
                        newRootPos = find(nums.begin(),nums.end(),curr->val)-nums.begin();
                    }
                }

            }
            
        }
        
        
                                       
        return root;
    }
};