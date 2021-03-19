// Prints all strings with length "k" where the characters are in sorted order
int numChars = 26;

void printSortedStrings(int remaining) {
    printSortedStrings(remaining, "");
}

void printSortedStrings(int remaining, String prefix) {
    if(remaining == 0) {
        if(isInOrder(prefix)) {
            System.out.println(prefix);
        } 
    } else {
        for(int i = 0; i < numChars; i++) {
            char c = ithLetter(i);
            printSortedStrings(remaining - 1, prefix + c)
        }
    }
}

boolean isInOrder(String s) {
    for(int i = 1; i < s.length(); i++) {
        int prev = ithLetter(s.charAt(i - 1));
        int curr = ithLetter(s.chartAt(i));
        if(prev > curr) return false;
    }

    return true;
}

char ithLetter(int i) {
    return (char) (((int) 'a') + i);
}

// O(kc^k) => k = length of the string, c = number of characters in the alphabet
// It takes O(c^k) to generate each string and O(k) to check if it is sorted.