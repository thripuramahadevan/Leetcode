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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp, *curr = head, *firstEven = NULL, *lastOdd = NULL, *prev=head;
        
        if (head == NULL || head->next == NULL)
            return head;
        int i=1;
        
        while(curr != NULL)
        {
            if (i%2 != 0) 
            {
                if (lastOdd == NULL)
                {
                    lastOdd = curr;
                }
                
            }
			else
            {
                if (firstEven == NULL)
                    firstEven = curr;
                //swap with next node
                lastOdd->next = curr->next;
                curr->next = curr->next->next;
                lastOdd->next->next = firstEven;
                lastOdd = lastOdd->next;
                ++i;
            }             
            curr = curr->next;
            ++i;
            if ((curr == NULL) || (curr->next == NULL))
                return head;
        }
        return head;
    }
};