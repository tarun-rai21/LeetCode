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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(101);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr && curr->next){
            if(curr && curr->val == curr->next->val){
                int val = curr->val; // duplicate block found

                while(curr && curr->val == val){
                    curr = curr->next;
                }
            prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};