class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Fast aur slow dono ko head par rakho
        ListNode* fast = head;
        ListNode* slow = head;

        // Fast ko n steps aage le jao
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Agar fast NULL ho gaya, toh head hi delete hoga
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;

            // Purane head ko memory se delete karo
            delete temp;

            return head;
        }

        // Fast aur slow ko ek-ek step aage badhao
        // Jab fast last node par hoga,
        // slow delete hone wali node ke previous par hoga
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete hone wali node ko temp mein store karo
        ListNode* temp = slow->next;

        // Slow ko delete hone wali node ke next se jod do
        slow->next = slow->next->next;

        // Delete hone wali node ko memory se remove karo
        delete temp;

        return head;
    }
};