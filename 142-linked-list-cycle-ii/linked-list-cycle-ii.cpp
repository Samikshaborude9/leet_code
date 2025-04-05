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
    ListNode *detectCycle(ListNode *head) {
    if(!head || !head -> next) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    //Step1
    while(fast && fast -> next){
        slow = slow-> next;
        fast = fast  -> next-> next;

        if(slow == fast){
            //find the start of the cycle 
            slow = head;
            while( slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return nullptr;
    }
};