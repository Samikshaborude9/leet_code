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
        // Step 1: Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0, head);
        
        // Step 2: Initialize two pointers: fast and slow
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3: Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Step 4: Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Remove the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        // Optional: delete the removed node to avoid memory leak
        delete nodeToDelete;

        // Step 6: Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;  // Don't forget to clean up dummy node
        return newHead;
    }
};
