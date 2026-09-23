class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL|| k==0) return head;
        ListNode*slow=head;
        ListNode*fast=head;
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        for(int i=0;i<k;i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};