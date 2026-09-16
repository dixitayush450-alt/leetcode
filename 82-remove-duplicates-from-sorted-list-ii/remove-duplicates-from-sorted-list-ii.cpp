class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Dummy node banaya taaki head ko bhi easily delete kar sake
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = head;

        while (temp != NULL) {

            // Check karo ki current value duplicate hai ya nahi
            if (temp->next != NULL && temp->val == temp->next->val) {

                // Duplicate value save kar lo
                int duplicate = temp->val;

                // Jab tak same value aa rahi hai,
                // temp ko aage move karte raho
                while (temp != NULL && temp->val == duplicate) {
                    temp = temp->next;
                }

                // Duplicate group ko poora skip kar do
                prev->next = temp;

            }
            else {

                // Duplicate nahi hai,
                // prev aur temp dono aage move karenge
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};