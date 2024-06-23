#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strToNum(char *str);
char* lower(char *str);
int hexToDec(char *hex);
char *squeeze(const char *strOne, const char *strTwo);
int any(const char *strOne, const char *strTwo);
int bitCount(unsigned int x);
char *lowerTwo(char *str);

int main() {
     
    // printf("%d", strToNum("1000"));
    // char *lowerStr = lower("KOUSHIK BHAT");
    // printf("%s", lowerStr);
    // printf("%d", hexToDec("0x1F"));
    // char *strResult = squeeze("Koushik", "Krishna");
    // printf("%s", strResult);
    // printf("%d", any("Koushik", "Ankit"));
    // printf("%d", bitCount(25));
    char *lowStrTwo = lowerTwo("KOUSHIK BHAT");
    printf("%s", lowStrTwo);
}

/*
 * Function: strToNum
 * -----------------
 * Converts a string representation of a positive integer to an actual integer.
 *
 * Parameters:
 *   - str: A pointer to a null-terminated C-style string containing digits.
 *
 * Returns:
 *   - The integer value obtained from the string.
 */
int strToNum(char *str) {
    int num = 0;
    
    for(int i = 0; str[i] != '\0'; i++)
        num = (str[i] - '0') + num * 10;
        
    return num;
}

/*
 * Function: lower
 * ---------------
 * Converts all uppercase letters in the input string to lowercase.
 *
 * Parameters:
 *   - str: A pointer to a null-terminated C-style string.
 *
 * Returns:
 *   - A dynamically allocated pointer to the resulting lowercase string.
 *
 * Memory Management:
 *   - The caller is responsible for freeing the memory allocated for the new string.
 */
char* lower(char *str) {
    char *newStr = malloc(strlen(str) + 1);
    
    int i;
    
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            newStr[i] = str[i] - 'A' + 'a';
        else
            newStr[i] = str[i];
    }
    
    newStr[i] = '\0';
    
    return newStr;
}

/*
 * Function: hexToDec
 * ------------------
 * Converts a hexadecimal string to its decimal (base 10) equivalent.
 *
 * Parameters:
 *   - hex: A pointer to a null-terminated C-style string representing a hexadecimal number.
 *
 * Returns:
 *   - The decimal value obtained from the hexadecimal string.
 */
int hexToDec(char *hex) {
    int dec = 0;
    int i = 0;
    
    if(hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X'))
        i += 2;
        
    for(; hex[i] != '\0'; i++) {
        if(hex[i] >= '0' && hex[i] <= '9')
            dec = dec * 16 + (hex[i] - '0');
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            dec = dec * 16 + (hex[i] - 'A' + 10);
        else if(hex[i] >= 'a' && hex[i] <= 'f')
            dec = dec * 16 + (hex[i] - 'a' + 10);
    }
    
    return dec;
}

/*
 * Function: squeeze
 * -----------------
 * Removes characters from the input string strOne that are also present in strTwo.
 * Creates a new string strResult containing only the characters from strOne that do not appear in strTwo.
 *
 * Parameters:
 *   - strOne: A pointer to a null-terminated C-style string (input string).
 *   - strTwo: A pointer to a null-terminated C-style string (characters to be removed).
 *
 * Returns:
 *   - A dynamically allocated pointer to the resulting string (strResult).
 *
 * Memory Management:
 *   - The caller is responsible for freeing the memory allocated for strResult after use.
 */
char *squeeze(const char *strOne, const char *strTwo) {
    char *strResult = malloc(strlen(strOne) + 1);
    
    int i, j, found;
    int pos = 0;
    
    for(i = 0; strOne[i] != '\0'; i++) {
        found = 0;
        for(j = 0; strTwo[j] != '\0'; j++) {
            if(strOne[i] == strTwo[j]) {
                found = 1;
                break;
            }
        }
        
        if(!found) {
            strResult[pos++] = strOne[i];
        }
    }
    
    strResult[pos] = '\0';
    
    return strResult;
}

/*
 * Function: any
 * -------------
 * Searches for the first occurrence of any character from strTwo in strOne.
 *
 * Parameters:
 *   - strOne: A pointer to a null-terminated C-style string (searched string).
 *   - strTwo: A pointer to a null-terminated C-style string (characters to search for).
 *
 * Returns:
 *   - The index of the first matching character in strOne.
 *   - If no match is found, returns -1.
 */
int any(const char *strOne, const char *strTwo) {
    int i, j;
    
    for(i = 0; strOne[i] != '\0'; i++) {
        for(j = 0; strTwo[j] != '\0'; j++) {
            if(strOne[i] == strTwo[j]) {
                return i;
            }
        }

    }
    return -1;
}

/*
 * Function: bitCount
 * ------------------
 * Counts the number of set (1) bits in the binary representation of an unsigned integer.
 *
 * Parameters:
 *   - x: The unsigned integer for which to count the set bits.
 *
 * Returns:
 *   - The total count of set bits (number of 1s) in the binary representation of x.
 */
int bitCount(unsigned int x) {
    int bitCount;
    
    for(bitCount = 0; x != 0; x >>= 1) {
        if(x & 1)
            bitCount++;
    }
    
    return bitCount;
}

/*
 * Function: lowerTwo
 * ---------------
 * Converts all uppercase letters in the input string to lowercase.
 *
 * Parameters:
 *   - str: A pointer to a null-terminated C-style string.
 *
 * Returns:
 *   - A dynamically allocated pointer to the resulting lowercase string.
 *
 * Memory Management:
 *   - The caller is responsible for freeing the memory allocated for the new string.
 */
char *lowerTwo(char *str) {
    char *newStr = malloc(strlen(str) + 1);
    int i = 0;
    
    for(i = 0; str[i] != '\0'; i++) {
        newStr[i] = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
    }
    
    newStr[i] = '\0';
    
    return newStr;
}
