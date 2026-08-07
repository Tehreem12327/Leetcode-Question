class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            
            // agar duplicate mil jaye
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // unique character add karo
            st.insert(s[right]);

            // max length update
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};