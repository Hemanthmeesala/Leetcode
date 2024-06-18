class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        if(fast==NULL || fast->next==NULL) return NULL;
        ListNode*temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
            if(temp==slow) break;
        }
        return temp;
    }
};