#include <stdio.h>
#include <string.h>
void swap(char *x, char *y) {
    // TODO
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(char *str, int start, int end) {
    if (start == end) {
        // TODO: Print the current permutation
        printf("%s\n", str);
        return;
    } else {
        for (int i = start; i <= end; i++) {
            // TODO: Swap the current character with the character at index ’i’
            swap(&str[i], &str[start]);
            // TODO: Recursively generate permutations for the next character
            generatePermutations(str, start + 1, end);
            // TODO: Backtrack (swap back to restore the original string)
            swap(&str[i], &str[start]);
        }
    }
}

int main() {
    char str[] = "CAT";
    int n = strlen(str); // Length of the string
    // TODO: Call the function with proper arguments to generate permutations
    generatePermutations(str, 0, n - 1);
    return 0;
}

//time omplexity: O(n^2). 
//for each element, it needs to be swaped with n elements, so it's n * n