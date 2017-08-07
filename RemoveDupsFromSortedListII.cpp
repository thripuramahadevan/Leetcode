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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || (head->next == NULL)) return head;
        
        ListNode *node,*curr = head, *prev = head;
        
        int delVal;
        
        if (head->val == head->next->val)
        {
            delVal = head->val;
            node = head;
            curr = curr->next;
            free(node);
            if (curr == NULL || curr->next == NULL)
                return NULL;
            while (curr->val == delVal)
            {
                node = curr;
                curr = curr->next;
                free(node);
                if (curr->next == NULL)
                {
                    if (curr->val == delVal)
                        head = NULL;
                    else
                        head = curr;
                    return head;
                }
                else if(curr->val == curr->next->val)
                    delVal = curr->val;
            }
            head = curr;            
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
        while (curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                delVal = curr->val;
                prev->next = curr->next->next;
                node = curr;
                curr = curr->next;
                if (curr == NULL || curr->next == NULL)
                {
                    prev->next = NULL;
                    node->next = NULL;
                    return head;
                }
                free(node);
                while(curr->val == delVal)
                {
                    node = curr;
                    curr = curr->next;
                    if (curr == NULL)
                    {
                        prev->next = NULL;
                        return head;
                    }
                    else if(curr->next == NULL)
                    {
                        if (curr->val == delVal)
                            prev->next = NULL;
                        else
                            prev->next = curr;
                        return head;
                    }
                    free(node);
                }
                prev->next = curr;
            }
            else
            {    
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};