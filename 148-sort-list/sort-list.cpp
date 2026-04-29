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

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // attach remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }

    // Function to find middle of linked list
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // important for splitting

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // mid node
    }

    ListNode* sortList(ListNode* head) {
        // base case
        if (!head || !head->next) return head;

        // Step 1: split list into two halves
        ListNode* mid = findMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;  // break the list

        // Step 2: sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Step 3: merge sorted halves
        return merge(left, right);
    }
};