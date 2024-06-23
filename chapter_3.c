#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

int binarySearch(int keyNum, int *arrData, int size);
int binarySearchTwo(int keyNum, int *arrData, int size);
void count(void);
char *escape(char *stringOne, char *stringTwo);
int asciiToInteger(char *string);
void reverse(char *string);
void expand(char *stringOne, char *stringTwo);
void integerToString(int num, char *string);
void integertoBase(int num, char *string, int base);
int trim(char *string);

int newLength;

int arrData[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 21};
char string[] = "Koushik       ";
char shortData[] = "a-z";
char hexDigits[] = "0123456789ABCDEF";
char expandedData[50];
char result[50];

int main() {
    
    // int result = binarySearch(13, arrData, (sizeof(arrData)/sizeof(arrData[0])));
    // printf("%d is in %d position\n", 13, result);
    
    // int result = binarySearchTwo(13, arrData, (sizeof(arrData)/sizeof(arrData[0])));
    // printf("%d is in %d position\n", 13, result);
    
    // count();
    
    // char stringTwo[] = "Hello\tWorld!\nThis is a test string with backspace\b.";
    // char stringOne[2 * strlen(stringTwo) + 1]; 
    
    // escape(stringOne, stringTwo);
    // printf("Original: %s\nEscaped: %s", stringTwo, stringOne);
    
    // printf("%d", asciiToInteger("-1234567890"));
    
    // reverse(string);
    // printf("%s", string);
    
    // expand(shortData, expandedData);
    // printf("%s", expandedData);
    
    // integerToString(-1234, result);
    // printf("%s", result);
    
    // integertoBase(80, result, 16);
    // printf("%s", result);
    
    // newLength = trim(string);
    // printf("%d\t%s\n", newLength, string);
    
    
    return 0;
}

int binarySearch(int keyNum, int *arrData, int size) {
    int low = 0, mid = 0, high = size - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        
        if(keyNum < arrData[mid]) {
            high = mid - 1;
        }
        else if(keyNum > arrData[mid]) {
            low = mid + 1;
        }
        else
            return mid;
    }
    
    return -1;
}

int binarySearchTwo(int keyNum, int *arrData, int size) {
    int low = 0, mid = 0, high = size - 1;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(keyNum == arrData[mid])
            return mid;
            
        if(keyNum < arrData[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return - 1;
}

void count() {
    int i, c, nwhite, nother, ndigit[10];
    
    nwhite = nother = 0;
    
    for(int i = 0; i < 10; i++)
        ndigit[i] = 0;
        
    while((c = getchar()) != EOF) {
        switch(c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ++ndigit[c - '0'];
                break;
            
            case ' ':
            case '\n':
            case '\t':
                ++nwhite;
                break;
            
            default:
                ++nother;
                break;
        }
        
        printf("digits = ");
        
        for(int i = 0; i < 10; i++)
            printf(" %d", ndigit[i]);
            
        printf(", whirespace = %d, other = %d\n", nwhite, nother);
    }
}

char *escape(char *stringOne, char *stringTwo) {
    int i = 0, j = 0;
    while(stringTwo[i] != '\0') {
        switch(stringTwo[i]) {
            case '\n':
                stringOne[j++] = '\\';
                stringOne[j++] = 'n';
                i++;
                break;
                
            case '\t':
                stringOne[j++] = '\\';
                stringOne[j++] = 't';
                i++;
                break;
                
            case '\b':
                stringOne[j++] = '\\';
                stringOne[j++] = 'b';
                i++;
                break; 
                
            default:
                stringOne[j++] = stringTwo[i++];
                break;
        }
    }
    
    stringOne[j] = '\0';
    
    return stringOne;
}

int asciiToInteger(char *string) {
    int i = 0, n = 0, sign;
    
    for(i = 0; (string[i] == '\n' || string[i] == '\t' || string[i] == ' '); i++)
        ;
        
    sign = (string[i] == '-') ? -1 : 1;
    
    if((string[i] == '+' || string[i] == '-'))
        i++;
        
    for(; (string[i] >= '0' && string[i] <= '9'); i++)
        n = n * 10 + (string[i] - '0');
        
    return sign * n;
}

void reverse(char *string) {
    int i = 0, j = 0;
    char temp;
    
    for(i = 0, j = (strlen(string) - 1); i < j; i++, j--) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

void expand(char *stringOne, char *stringTwo) {
    int start = stringOne[0], end = stringOne[(strlen(stringOne) - 1)];
    int j = 0;
    
    if(start == 'a' && end == 'z') {
        for(char currentChar = start; currentChar <= end; currentChar++) {
            stringTwo[j++] = currentChar;
        }
        
        stringTwo[j] = '\0';
    } 
}

void integerToString(int num, char *string) {
    int i = 0, sign = 0;
    
    if((sign = num) < 0)
        num = -num;
    
    do {
        string[i++] = num % 10 + '0';
        num /= 10;
    } while(num > 0);
    
    if(sign < 0) {
        string[i++] = '-';
    }
    
    string[i] = '\0';
    
    reverse(string);
}

void integertoBase(int num, char *string, int base) {
    int i = 0, sign = 0;
    
    if((sign = num) < 0)
        num = -num;
        
    if(base == 2) {
        if(num == 0) {
            string[i++] = '0';
            string[i] = '\0';
        }
        
        do {
            string[i++] = (num % 2) + '0';
            num /= 2;
        } while (num > 0);
        
        string[i] = '\0';
        
        reverse(string);
    }
    else if(base == 10) {
        if(num == 0) {
            string[i++] = '0';
            string[i] = '\0';
        }
        
        do {
            string[i++] = (num % 10) + '0';
            num /= 10;
        } while(num > 0);
        
        if(sign < 0) {
            string[i++] = '-';
        }
        
        string[i] = '\0';
        
        reverse(string);
    }
    else if(base == 16) {
        if(num == 0) {
            string[i++] = '0';
            string[i] = '\0';
        }
        
        do {
            string[i++] = hexDigits[num % 16];
            num /= 16;
        } while(num > 0);
        
        
        string[i] = '\0';
        
        reverse(string);
    }
    
}

int trim(char *string) {
    int n;
    
    for(n = (strlen(string) - 1); n >= 0; n--) {
        if(string[n] != ' ' && string[n] != '\n' && string[n] != '\t')
            break;
    }
    
    string[n + 1] = '\0';
    
    return n;
}
