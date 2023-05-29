#include <stdio.h>
#include <ctype.h> /* toupper, isalpha */

void scan_word(int* occurrences) {
    char c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            *(occurrences + toupper(c) - 'A') += 1; //increment the occurrence of the letter in the array
        }
    }
}

int is_anagram(int* occurrences1, int* occurrences2) {
    int i;
    for (i = 0; i < 26; i++) {
        if (*(occurrences1 + i) != *(occurrences2 + i)) {
            return 0; //not an anagram, return false
        }
    }
    return 1; //anagram, return true
}

int main(void) {
    int occurrences1[26] = { 0 }; //array to store occurrences of letters in the first word
    int occurrences2[26] = { 0 }; //array to store occurrences of letters in the second word

    printf("Enter first word: \n");
    scan_word(occurrences1); //scan the first word and update the occurrences1 array

    printf("Enter second word: \n");
    scan_word(occurrences2); //scan the second word and update the occurrences2 array

    if (is_anagram(occurrences1, occurrences2)) {
        printf("The words are anagrams. \n"); //print if the words are anagrams
    }
    else {
        printf("The words are not anagrams. \n"); //print if the words are not anagrams
    }

    return 0;
}

