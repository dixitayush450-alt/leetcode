class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Agar list empty hai ya sirf 1 node hai,
        // toh kuch change karne ki zarurat nahi
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Odd position wali list ka pointer
        ListNode* odd = head;

        // Even position wali list ka pointer
        ListNode* even = head->next;

        // Even list ke first node ko save kar liya
        // Baad mein odd list ke end mein jodenge
        ListNode* evenHead = head->next;

        // Jab tak even aur uska next node available hai
        while (even != NULL && even->next != NULL) {

            // Odd node ko next odd-position node se jod do
            odd->next = odd->next->next;

            // Even node ko next even-position node se jod do
            even->next = even->next->next;

            // Odd pointer ko aage badhao
            odd = odd->next;

            // Even pointer ko aage badhao
            even = even->next;
        }

        // Odd list ke end mein even list jod do
        odd->next = evenHead;

        // Original head se poori list return karo
        return head;
    }
};