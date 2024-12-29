#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq(26, 0);

        // Initialize frequency array for s1 and the first window in s2
        for (char c : s1) freq[c - 'a']--;
        for (int i = 0; i < s1.size(); i++) freq[s2[i] - 'a']++;

        // Count non-zero differences
        int diff = 0;
        for (int count : freq) {
            if (count != 0) diff++;
        }

        // Sliding window
        for (int i = s1.size(); i < s2.size(); i++) {
            if (diff == 0) return true;

            int addIdx = s2[i] - 'a', removeIdx = s2[i - s1.size()] - 'a';

            // Update diff for the new character added
            if (freq[addIdx] == 0) diff++;
            freq[addIdx]++;
            if (freq[addIdx] == 0) diff--;

            // Update diff for the character removed
            if (freq[removeIdx] == 0) diff++;
            freq[removeIdx]--;
            if (freq[removeIdx] == 0) diff--;
        }

        return diff == 0;
    }
};