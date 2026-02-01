class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = 0;

        for (char target = 'A'; target <= 'Z'; target++) {
            int left = 0;
            int changes = 0;

            for (int right = 0; right < s.size(); right++) {

                if (s[right] != target) {
                    changes++;
                }

                while (changes > k) {
                    if (s[left] != target) {
                        changes--;
                    }
                    left++;
                }

                answer = max(answer, right - left + 1);
            }
        }

        return answer;
    }
};
