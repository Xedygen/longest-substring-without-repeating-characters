#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s);

int main(void) {
    int len, len1, len2;
    char s[] = "abcabcbb";
    char s1[] = "bbbbb";
    char s2[] = "pwwkew";
    int (*point)(char *) = lengthOfLongestSubstring;

    len = point(s);
    printf("%d\n", len);

    len1 = point(s1);
    printf("%d\n", len1);

    len2 = point(s2);
    printf("%d\n", len2);

    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int p1 = 0;
    int p2 = 0;
    size_t l = strlen(s);
    if (s == NULL || l < 2) {
        return l;
    }
    int maxl = 0;
    int seen[256] = {0}; 

    while (p2 < l) {
        seen[(unsigned char)s[p2]]++;
        while (seen[(unsigned char)s[p2]] > 1) {
            seen[(unsigned char)s[p1]]--;
            p1++;
        }

        if (p2 - p1 + 1 > maxl) {
            maxl = p2 - p1 + 1;
        }
        p2++;
    }
    return maxl;
}