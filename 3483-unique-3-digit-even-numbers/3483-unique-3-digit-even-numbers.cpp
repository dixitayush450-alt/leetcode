class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        set<int> numbers;

        // Pehla digit choose kar rahe hain
        for(int i = 0; i < digits.size(); i++) {

            // Doosra digit choose kar rahe hain
            for(int j = 0; j < digits.size(); j++) {

                // Teesra digit choose kar rahe hain
                for(int k = 0; k < digits.size(); k++) {

                    // Same array position ko dobara use nahi karna
                    if(i == j || i == k || j == k)
                        continue;

                    // First digit 0 nahi ho sakta
                    if(digits[i] == 0)
                        continue;

                    // Last digit even hona chahiye
                    if(digits[k] % 2 != 0)
                        continue;

                    // 3 digits ko mila kar 3-digit number bana rahe hain
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    // Number ko set mein daal rahe hain
                    // Duplicate number automatically ignore ho jayega
                    numbers.insert(num);
                }
            }
        }

        // Set mein jitne unique numbers hain, wahi answer hai
        return numbers.size();
    }
};