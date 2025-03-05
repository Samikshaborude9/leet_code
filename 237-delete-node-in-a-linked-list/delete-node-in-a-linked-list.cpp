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
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) return; // Edge case

        node->val = node->next->val;       // Copy next node's value to current node
        ListNode* temp = node->next;       // Store the next node in temp
        node->next = node->next->next;     // Skip the next node
        delete temp;                       // Delete the copied node
    }
};
