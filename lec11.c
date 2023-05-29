#include <stdio.h>
#include <ctype.h> /* toupper, isalpha */
#include <stdbool.h> /* bool type */

void scan_word(int occurrences[26]); // Function prototype for scanning a word
bool is_anagram(int occurrences1[26], int occurrences2[26]); // Function prototype for checking anagrams

int main(void) {
    int occurrences1[26] = {0}; // Array to store occurrences of each letter in the first word
    int occurrences2[26] = {0}; // Array to store occurrences of each letter in the second word

    printf("Enter first word: \n");
    scan_word(occurrences1); // Scan the first word and update occurrences array

    printf("Enter second word: \n");
    scan_word(occurrences2); // Scan the second word and update occurrences array

    bool result = is_anagram(occurrences1, occurrences2); // Check if the words are anagrams

    if (result) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

void scan_word(int occurrences[26]) {
    char c;
    while ((c = getchar()) != '\n') { // Read characters until newline is encountered
        if (isalpha(c)) { // Check if the character is alphabetic
            occurrences[toupper(c) - 'A']++; // Increment the corresponding index in the occurrences array
        }
    }
}

bool is_anagram(int occurrences1[26], int occurrences2[26]) {
    for (int i = 0; i < 26; i++) { // Iterate through each index of the arrays
        if (occurrences1[i] != occurrences2[i]) { // Compare the elements at the same index
            return false; // If any element differs, the words are not anagrams
        }
    }
    return true; // If all elements match, the words are anagrams
}

