class Solution {
public:

    // --------------------------------------------------
    // STEP 1: List ka middle node find karna
    // --------------------------------------------------
    ListNode* findMiddleNode(ListNode* head) {

        // Agar list empty hai ya sirf 1 node hai,
        // toh wahi node middle hai
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Slow 1 step chalega
        // Fast 2 steps chalega
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Fast ko 2 steps safely move karna hai
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow middle ke previous node par rukega
        return slow;
    }


    // --------------------------------------------------
    // STEP 2: Do sorted linked lists ko merge karna
    // --------------------------------------------------
    ListNode* merge(ListNode* list1Head, ListNode* list2Head) {

        // Dummy node banaya, taaki first node handle karna easy ho
        ListNode* dummyNode = new ListNode(-1);

        // Temp result list mein nodes add karega
        ListNode* temp = dummyNode;

        // Jab tak dono lists mein nodes available hain
        while (list1Head != NULL && list2Head != NULL) {

            // Agar list1 ka node chhota ya equal hai
            if (list1Head->val <= list2Head->val) {

                // List1 ka node result list mein jod do
                temp->next = list1Head;

                // Temp ko naye node par le jao
                temp = list1Head;

                // List1 mein aage badho
                list1Head = list1Head->next;
            }

            // Agar list2 ka node chhota hai
            else {

                // List2 ka node result list mein jod do
                temp->next = list2Head;

                // Temp ko naye node par le jao
                temp = list2Head;

                // List2 mein aage badho
                list2Head = list2Head->next;
            }
        }

        // Agar list1 mein nodes bach gaye hain,
        // toh unhe directly result mein jod do
        if (list1Head != NULL) {
            temp->next = list1Head;
        }

        // Agar list2 mein nodes bach gaye hain,
        // toh unhe directly result mein jod do
        else {
            temp->next = list2Head;
        }

        // Dummy ke next se actual sorted list start hoti hai
        return dummyNode->next;
    }


    // --------------------------------------------------
    // STEP 3: Merge Sort lagana
    // --------------------------------------------------
    ListNode* sortList(ListNode* head) {

        // Agar list empty hai ya sirf 1 node hai,
        // toh list already sorted hai
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Middle ke previous node ko find karo
        ListNode* mid = findMiddleNode(head);

        // Left half ka first node
        ListNode* leftHead = head;

        // Right half ka first node
        ListNode* rightHead = mid->next;

        // List ko do alag parts mein tod do
        mid->next = NULL;

        // Left half ko recursively sort karo
        leftHead = sortList(leftHead);

        // Right half ko recursively sort karo
        rightHead = sortList(rightHead);

        // Dono sorted halves ko merge karke return karo
        return merge(leftHead, rightHead);
    }
};