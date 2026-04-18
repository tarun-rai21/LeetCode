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
    int getDecimalValue(ListNode* head) {
        
        if(head == NULL) return 0;
        
        // count number of nodes
        int nodes = 0;
        ListNode* temp1 = head;
        while(temp1){
            nodes++;
            temp1 = temp1->next;
        }

        int num = 0;
        ListNode* temp2 = head;
        for(int i = nodes-1; i>=0; i--){
            num += temp2->val * pow(2, i);
            temp2 = temp2->next;
        }

        return num;
    }
};