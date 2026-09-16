class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Empty list check
        if (head == NULL) {
            return head;
        }

        ListNode* temp = head;

        // temp aur temp->next dono exist hone chahiye
        while (temp != NULL && temp->next != NULL) {

            // Agar current aur next value same hai
            if (temp->val == temp->next->val) {

                // Duplicate node ko skip/delete from list
                temp->next = temp->next->next;
            }
            else {

                // Different value hai, aage badho
                temp = temp->next;
            }
        }

        return head;
    }
};