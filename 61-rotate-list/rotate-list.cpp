class Solution {
public:

    // k-th node find karne ke liye helper function
    ListNode* findNthNode(ListNode* temp, int k) {

        int cnt = 1;

        while (temp != NULL) {

            // Agar required position mil gayi
            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        // Agar list empty hai ya k = 0 hai
        // toh rotation ki zarurat nahi hai
        if (head == NULL || k == 0)
            return head;

        // Tail find karenge
        ListNode* tail = head;

        // Length initially 1
        int len = 1;

        // List ke end tak jao
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Agar k list ki length se bada hai,
        // toh unnecessary rotations remove kar do
        k = k % len;

        // Agar k = 0 ho gaya,
        // toh list same rahegi
        if (k == 0)
            return head;

        // Tail ko head se connect karke
        // circular linked list bana do
        tail->next = head;

        // New tail ki position = len - k
        ListNode* newLastNode = findNthNode(head, len - k);

        // New head new tail ke next par hoga
        head = newLastNode->next;

        // Circular connection tod do
        newLastNode->next = NULL;

        return head;
    }
};