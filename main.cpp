#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>


int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int maxLength = 0;
    std::unordered_set<char> charSet;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        if (charSet.count(s[right]) == 0) {
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        } else {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
        }
    }
    
    return maxLength;
}


int main(){

    std::string s = "pwwkew";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

}
// hello