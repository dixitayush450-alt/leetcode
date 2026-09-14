class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node result linked list ke starting point ke liye
        ListNode* dummy = new ListNode(0);

        // temp result list mein naye nodes attach karega
        ListNode* temp = dummy;

        // Carry extra value store karega
        int carry = 0;

        // Jab tak l1, l2 mein node hai ya carry bacha hua hai
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // Current addition ki starting value carry hogi
            int sum = carry;

            // Agar l1 mein node available hai
            if (l1 != NULL) {
                sum += l1->val;   // l1 ki value add karo
                l1 = l1->next;    // l1 ko next node par move karo
            }

            // Agar l2 mein node available hai
            if (l2 != NULL) {
                sum += l2->val;   // l2 ki value add karo
                l2 = l2->next;    // l2 ko next node par move karo
            }

            // Current digit result mein add hoga
            // Example: sum = 15, toh digit = 5
            ListNode* node = new ListNode(sum % 10);

            // Naye node ko result list ke end mein attach karo
            temp->next = node;

            // temp ko naye node par move karo
            temp = temp->next;

            // Next addition ke liye carry calculate karo
            // Example: sum = 15, toh carry = 1
            carry = sum / 10;
        }

        // Dummy node ko skip karke actual result return karo
        return dummy->next;
    }
};