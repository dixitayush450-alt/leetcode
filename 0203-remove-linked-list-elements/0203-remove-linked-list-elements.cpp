class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Jab tak head NULL nahi hai aur head ka data val ke equal hai
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        // Ab remaining list traverse karenge
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {

            // Agar next node ki value val ke equal hai
            if (temp->next->val == val) {

                // Next node ko skip kar do
                temp->next = temp->next->next;

            } 
            else {
                // Agar delete nahi karna hai,
                // toh temp ko aage move karo
                temp = temp->next;
            }
        }

        // Modified list ka head return
        return head;
    }
};