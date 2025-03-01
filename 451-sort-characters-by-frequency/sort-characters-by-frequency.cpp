class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq; // Store frequency of each character
        for (char c : s) freq[c]++; // Count occurrences

        // Max heap (priority queue) to store characters sorted by frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push({count, ch}); // Store {frequency, character}
        }

        string result = "";
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top(); maxHeap.pop();
            result.append(count, ch); // Append character 'count' times
        }

        return result;
    }
};
