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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode* temp = head;
        int count = 1;
        
        while(temp->next){
            temp = temp->next;
            count++;
        }
        k = k % count;
        if(k==0) return head;

        temp->next = head; //circular list

        int steps = count - k;
        while(steps--){
            temp = temp->next;
        }

        // break circle
        ListNode* new_head = temp->next;
        temp->next = NULL;

        return new_head;
    }
};