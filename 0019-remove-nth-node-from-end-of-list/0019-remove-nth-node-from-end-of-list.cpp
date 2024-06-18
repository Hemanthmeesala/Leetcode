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
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is null, it means we need to remove the head node
        if (fast == nullptr) return head->next;

        // Move fast to the end, maintaining the gap
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the desired node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;  // Use delete instead of free for C++ 

        return head;
    }
};
