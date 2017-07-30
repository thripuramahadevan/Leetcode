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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptemp, *pNthNode, *temp;
        
        int i=0;
        
        ptemp = head;
        pNthNode = head;
        
        if (head == NULL)
            return head;
        
        for (;i<n;++i)
        {
            ptemp = ptemp->next;    
        }
        
        if ((ptemp == NULL) && (pNthNode == head))
        {
            temp = head;
            head = head->next;
            free(temp);
            if (head == NULL)
                return NULL;
            else
                return head;
        }
        
        while (ptemp->next != NULL)
        {
            ptemp = ptemp->next;
            pNthNode = pNthNode->next;
        }
        temp = pNthNode->next;
        pNthNode->next = pNthNode->next->next;
        free(temp);
        return head;
    }
};