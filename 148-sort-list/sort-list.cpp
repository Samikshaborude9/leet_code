class Solution {
public:
    // Function to sort the list
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (!head || !head->next) return head;

        // Step 1: Split the list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 2: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Helper function to find the middle and split the list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the first half from the second
        if (prev) prev->next = nullptr;

        return slow;
    }

    // Helper function to merge two sorted lists
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

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
