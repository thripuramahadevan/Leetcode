/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = 0, len2 = 0, i,carry = 0;
        
        vector<int> v1, v2, resVec;
        
        ListNode *res=NULL, *resCurr, *curr = l1;
        
        while (curr != NULL)
        {
            ++len1;
            v1.push_back(curr->val);
            curr = curr->next;            
        }
        
        curr = l2;
        
        while (curr != NULL)
        {
            ++len2;
            v2.push_back(curr->val);
            curr = curr->next;            
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        
        if (len1 > len2)
        {
            carry = 0;
            
            for (i=0;i<len2;++i)
            {
                resVec.push_back((v1[i]+v2[i]+carry)%10);
                carry = (v1[i]+v2[i]+carry)/10;
            }
            for (;i<len1;++i)
            {
                resVec.push_back((v1[i]+carry)%10);
                carry = (v1[i]+carry)/10;
            }
            if (carry>0)
                resVec.push_back(carry);
            
            reverse(resVec.begin(),resVec.end());
            
            for (int j=0;j<resVec.size();++j)
            {
                curr = new ListNode(resVec[j]);
                if (res == NULL)
                {
                    res = curr;
                    resCurr = curr;
                }
                else
                {
                    resCurr->next = curr;
                    resCurr = resCurr->next;
                }
            }
            
        }
        else
        {
            carry = 0;
            
            int i;
            for (i=0;i<len1;++i)
            {
                resVec.push_back((v1[i]+v2[i]+carry)%10);
                carry = (v1[i]+v2[i]+carry)/10;
            }
            for (;i<len2;++i)
            {
                resVec.push_back((v2[i]+carry)%10);
                carry = (v2[i]+carry)/10;
            }
            if (carry>0)
                resVec.push_back(carry);
            
            reverse(resVec.begin(),resVec.end());
            
            cout << "len1=" << len1 << ",len2=" << len2;
            for (auto res1 : resVec)
                cout << res1;
            
            for (int j=0;j<resVec.size();++j)
            {
                curr = new ListNode(resVec[j]);
                if (res == NULL)
                {
                    res = curr;
                    resCurr = curr;
                }
                else
                {
                    resCurr->next = curr;
                    resCurr = resCurr->next;
                }
            }
        }
        
        return res;
    }
};