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
    ListNode* rotateRight(ListNode* head, int k) {
        // special case
        if(head==0) return NULL;
        // finding the length og linked list
        int length=0;
        ListNode*temp=head;
        ListNode*tail=NULL;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            length++;
        }
        k= k % length;
        // I have to place temp at (length-k)th position
        temp=head;
        for(int i=1;i<(length-k);i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};