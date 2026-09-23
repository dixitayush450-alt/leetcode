class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Agar list empty hai
        if (head == NULL)
            return NULL;

        // STEP 1:
        // Har original node ke turant baad uska clone insert karo
        Node* temp = head;

        while (temp != NULL) {

            // Current node ka clone
            Node* copy = new Node(temp->val);

            // Clone ko original ke baad insert karo
            copy->next = temp->next;
            temp->next = copy;

            // Next original node par jao
            temp = copy->next;
        }


        // STEP 2:
        // Clone nodes ke random pointers set karo
        temp = head;

        while (temp != NULL) {

            // Agar original ka random exist karta hai
            if (temp->random != NULL) {

                // temp->next = current node ka clone
                // temp->random->next = random node ka clone
                temp->next->random = temp->random->next;
            }

            // Next original node par jao
            temp = temp->next->next;
        }


        // STEP 3:
        // Original aur cloned list ko alag karo
        temp = head;

        // Clone list ka head
        Node* cloneHead = head->next;

        while (temp != NULL) {

            // Current original ka clone
            Node* copy = temp->next;

            // Original list restore karo
            temp->next = copy->next;

            // Clone list ka next set karo
            if (copy->next != NULL)
                copy->next = copy->next->next;

            // Next original node
            temp = temp->next;
        }

        // Cloned list ka head return
        return cloneHead;
    }
};