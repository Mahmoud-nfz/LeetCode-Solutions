class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruit1 = -1, fruit2 = -1, lastOccFruit1, lastOccFruit2;
        int maxLen = 0, i = 0, start = 0;

        // Iterate through the fruit trees in the farm
        while (i < fruits.size()) {
            if (fruit1 == -1) {
                // If fruit1 has not been assigned, set it as the current fruit and record its occurrence.
                fruit1 = fruits[i];
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit1) {
                // If the current fruit is the same as fruit1, update its last occurrence.
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit2) {
                // If the current fruit is the same as fruit2, update its last occurrence.
                lastOccFruit2 = i;
            } else if (fruit2 == -1) {
                // If we encounter a different fruit type and fruit2 is not assigned, change fruit2 and record its occurrence.
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            } else {
                // We need to switch one of the fruit types as we've encountered a third type.
                // Choose which fruit to keep based on the most recent occurrence.
                if (lastOccFruit2 < lastOccFruit1) {
                    swap(fruit1, fruit2);
                    swap(lastOccFruit1, lastOccFruit2);
                }
                start = lastOccFruit1 + 1;
                // Update fruit1 to the new type and its last occurrence.
                fruit1 = fruit2;
                lastOccFruit1 = lastOccFruit2;
                // Set fruit2 as the current fruit type and record its occurrence.
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            }
            // Update maxLen with the maximum length of collected fruits.
            maxLen = max(maxLen, i - start + 1);
            i++;
        }
        // Print the maximum length (for debugging, you can remove this line)
        cout << maxLen << endl;
        return maxLen; // Return the maximum number of fruits you can pick
    }
};
