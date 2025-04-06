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
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalfHead = reverseList(slow);
        ListNode* firstHalfHead = head;

        // Step 3: Compare both halves
        ListNode* tempSecond = secondHalfHead;
        while (tempSecond) {
            if (firstHalfHead->val != tempSecond->val)
                return false;
            firstHalfHead = firstHalfHead->next;
            tempSecond = tempSecond->next;
        }

        // Optional: reverse again to restore the list
        // reverseList(secondHalfHead);

        return true;
    }
};
