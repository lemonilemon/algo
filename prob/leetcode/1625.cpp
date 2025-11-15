#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string findLexSmallestString(string s, int a, int b) {
        set<int> offsets;
        int cur = 0;
        while (!offsets.count(cur)) {
            offsets.insert(cur);
            cur += a;
            cur %= 10;
        }

        int offset_gives_min[10];
        for (int i = 0; i < 10; ++i) {
            int mn = i;
            offset_gives_min[i] = 0;
            for (auto offset : offsets) {
                if ((i + offset) % 10 < mn) {
                    offset_gives_min[i] = offset;
                    mn = (i + offset) % 10;
                }
            }
        }
        string lex_smallest_candidate = s;
        int g = __gcd(b, (int)s.size());
        for (int rotation = 0; rotation < (int)s.size(); rotation += g) {
            string candidate;
            int offset_to_second_number =
                offset_gives_min[s[(rotation + 1) % s.size()] - '0'];
            int offset_to_first_number = 0;
            if (b % 2 == 1) { // even_index_nubmers can also apply operation 1
                offset_to_first_number = offset_gives_min[s[rotation] - '0'];
            }
            for (int j = 0; j < s.size(); ++j) {
                int current_idx = (rotation + j) % s.size();
                int val = (s[current_idx] - '0' +
                           ((j % 2 == 0) ? offset_to_first_number
                                         : offset_to_second_number)) %
                          10;
                candidate += val + '0';
            }
            lex_smallest_candidate = min(lex_smallest_candidate, candidate);
        }
        return lex_smallest_candidate;
    }
};

int main() {
    Solution sol;
    cout << sol.findLexSmallestString("5525", 9, 2) << '\n';
    cout << sol.findLexSmallestString("74", 5, 1) << '\n';
    cout << sol.findLexSmallestString("0011", 4, 2) << '\n';
}
