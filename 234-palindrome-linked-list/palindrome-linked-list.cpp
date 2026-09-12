class Solution {
public:

    // Linked list reverse karne ka function
    ListNode* reverseLinkedList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Empty list ya single node palindrome hoti hai
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Middle se pehle wale last node ko find karna
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Second half ko reverse karna
        ListNode* newHead = reverseLinkedList(slow->next);

        // First half ka pointer
        ListNode* first = head;

        // Reversed second half ka pointer
        ListNode* second = newHead;

        // Dono halves compare karna
        while (second != NULL) {

            if (first->val != second->val) {

                // List ko original form mein restore karna
                reverseLinkedList(newHead);

                return false;
            }

            first = first->next;
            second = second->next;
        }

        // List ko original form mein restore karna
        reverseLinkedList(newHead);

        return true;
    }
};