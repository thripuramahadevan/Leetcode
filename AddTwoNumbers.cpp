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
        ListNode *res=NULL, *l1Dup, *l2Dup, *travRes;
        
        int carry = 0;

        l1Dup = l1;
        
        while (l1Dup != NULL)
        {
            ListNode *temp = new ListNode(l1Dup->val);
            
            if (res) travRes = res;
            else travRes = NULL;
            
            if (travRes == NULL)
            {
                res = temp;
                travRes = res;
            }
            else
            {
                while (travRes->next != NULL)
                    travRes = travRes->next;
                travRes->next = temp;
            }
            l1Dup = l1Dup->next;
        }
        
        
        
        l2Dup = l2;
                   
        travRes = res;
        
        while (l2Dup != NULL)
        {
            
            int sum = (travRes->val + l2Dup->val + carry) % 10;
            carry = (travRes->val + l2Dup->val + carry) / 10;
            travRes->val = sum;
            l2Dup = l2Dup->next;
            if (travRes->next != NULL) travRes = travRes->next;
            else if (l2Dup || (carry > 0))
            {
            
               ListNode *temp = new ListNode(0); 
                travRes->next = temp;
                travRes = travRes->next;
            }
            
        }
        while (carry > 0)
        {
            travRes->val += carry;
            if (travRes->val >= 10)
            {
                cout << "For " << travRes->val;
                carry = (travRes->val)/10;
                travRes->val = (travRes->val)%10;
                cout << " now " << travRes->val;
                
                
                if (travRes->next != NULL) travRes = travRes->next;
                else
                {
                    ListNode *temp = new ListNode(carry);
                    travRes->next = temp;
                    
                    carry = 0;
                }
                
            }
            else
                carry = 0;
        }
        
        return res;
    }
};