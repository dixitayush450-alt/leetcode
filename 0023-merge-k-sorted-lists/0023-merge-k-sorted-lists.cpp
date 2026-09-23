class Solution {
public:

    // Q21 wala function:
    // Do sorted linked lists ko merge karta hai
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node banaya
        ListNode* dummyNode = new ListNode(-1);

        // Merged list ka current/last node
        ListNode* temp = dummyNode;

        // Jab tak dono lists mein nodes hain
        while (list1 != NULL && list2 != NULL) {

            // Chhota node merged list mein add karo
            if (list1->val <= list2->val) {

                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else {

                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        // Jo list bach gayi hai usko directly attach kar do
        if (list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        // Dummy ko skip karke actual head return
        return dummyNode->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Agar koi list hi nahi hai
        if (lists.size() == 0)
            return NULL;

        // Pehli list ko starting merged list maan lo
        ListNode* head = lists[0];

        // Baaki har list ko ek-ek karke merge karo
        for (int i = 1; i < lists.size(); i++) {

            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};