#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string smallestString(string s) {
        bool flag = false;
        for (auto &c : s) {
            if (c == 'a') {
                if (flag)
                    break;
                else
                    continue;
            }
            c -= 1;
            flag = true;
        }
        if (!flag)
            s.back() = 'z';
        return s;
    }
};
