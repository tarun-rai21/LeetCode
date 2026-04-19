/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        temp->next = head;

        //count total nodes
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }

        ListNode* curr = &dummy;
        for(int i=0; i<count-n-1; i++){
            curr = curr->next;
        }        
        curr->next = curr->next->next;

        return dummy.next;
    }
};