class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node banaya
        // Isse starting node handle karna easy ho jata hai
        ListNode* dummyNode = new ListNode(-1);

        // temp merged list ke last node ko point karega
        ListNode* temp = dummyNode;

        // Jab tak dono lists mein nodes available hain
        while (list1 != NULL && list2 != NULL) {

            // Agar list1 ka current node chhota ya equal hai
            if (list1->val <= list2->val) {

                // list1 ke node ko merged list mein attach karo
                temp->next = list1;

                // temp ko naye last node par move karo
                temp = list1;

                // list1 ko next node par move karo
                list1 = list1->next;
            }

            else {

                // list2 ke node ko merged list mein attach karo
                temp->next = list2;

                // temp ko naye last node par move karo
                temp = list2;

                // list2 ko next node par move karo
                list2 = list2->next;
            }
        }

        // Agar list1 mein nodes bach gaye hain
        if (list1 != NULL)
            temp->next = list1;

        // Agar list2 mein nodes bach gaye hain
        else
            temp->next = list2;

        // Dummy node ko skip karke actual merged list return karo
        return dummyNode->next;
    }
};