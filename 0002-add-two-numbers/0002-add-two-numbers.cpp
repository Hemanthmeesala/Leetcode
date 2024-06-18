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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // what a question
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        //create dummy node
        ListNode* dummynode=new ListNode(-1);
        ListNode *curr=dummynode;
        int carry=0,sum;
        while(temp1!=nullptr || temp2!=nullptr)
        {
           sum=0;
           sum+=carry;
           if(temp1) sum+=temp1->val;
           if(temp2) sum+=temp2->val;
           //create newnode 
          

           ListNode* newnode=new ListNode(sum%10);
           carry=sum/10;
           curr->next=newnode;
           curr=curr->next;

           if(temp1) temp1=temp1->next;
           if(temp2) temp2=temp2->next;
           
        }
        if(carry)
        {
            ListNode *newnode= new ListNode(carry);
            curr->next=newnode;
        }
        
        return dummynode->next;
        
    }
};