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
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL)
            return NULL;
        
        if (head->next == head)
            return head;
        
        ListNode *curr = head;
        
        while (curr != NULL)
        {
            ListNode *node = head;
            while (node != curr)
            {
                if (node == curr->next)
                    return node;
                node = node->next;
            }
            if (curr == curr->next)
                return curr;
            
            curr = curr->next;
        }
        
        return NULL;
        
    }
};