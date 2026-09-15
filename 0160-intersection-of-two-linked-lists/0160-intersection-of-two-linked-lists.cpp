class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;  // List A ka pointer
        ListNode* temp2 = headB;  // List B ka pointer

        // Jab tak dono same node par nahi aate
        while (temp1 != temp2) {

            // List A ke end par pahunchne par
            // temp1 ko List B ke head par bhejo
            if (temp1 == NULL)
                temp1 = headB;
            else
                temp1 = temp1->next;

            // List B ke end par pahunchne par
            // temp2 ko List A ke head par bhejo
            if (temp2 == NULL)
                temp2 = headA;
            else
                temp2 = temp2->next;
        }

        // Intersection node return hoga.
        // Agar intersection nahi hai, toh NULL return hoga.
        return temp1;
    }
};