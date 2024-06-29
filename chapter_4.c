#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXLINE 100U

char pattern[] = "ould";
uint8_t getLine(char *line, uint8_t max);
int stringIndex(char *src, char *searchFor);
int lastOccurence(char *src, char *searchFor);
float asciiToFloat(char *string);
float asciiToFloatVersionTwo(char *string);

int main(void) {
    // char line[MAXLINE];
    // uint8_t found = 0;
   
    // while(getLine(line, MAXLINE) > 0) {
    //     if(stringIndex(line, pattern) >= 0) {
    //         printf("%s", line);
    //         found++;
    //     }
    // }
   
    // char stringOne[] = "This is an example of a string containing the word example multiple times. Let's find the last example.";
    
    // uint8_t position = lastOccurence(stringOne, "example");
    // printf("%u", position);
    
    // printf("%f", asciiToFloat("-23.68"));

    printf("%f", asciiToFloatVersionTwo("123.45e+5"));

    return 0;
}

uint8_t getLine(char *line, uint8_t max) {
    uint8_t index = 0, character = 0;
    
    while(max > 0 && (character = getchar()) != EOF && character != '\n') {
        line[index++] = character;
        max--;
    }
    
    if(character == '\n')
        line[index++] = character;
        
    line[index++] = '\0';
    
    return index;
}

int stringIndex(char *src, char *searchFor) { // src = "He would"; searchFor = "ould";
    uint8_t i = 0, j = 0, k = 0;
    
    for(i = 0; src[i] != '\0'; i++) {
        for(j = i, k = 0; searchFor[k] != '\0' && src[j] == searchFor[k]; j++, k++);
        
        if(k > 0 && searchFor[k] == '\0')
            return i;
    }
    
    return -1;
}

int lastOccurence(char *src, char *searchFor) {
    uint8_t i = 0, j = 0, k = 0;
    int lastOccurence = -1;
    
    for(i = 0; src[i] != '\0'; i++) {
        for(j = i, k = 0; src[j] == searchFor[k] && searchFor[k] != '\0'; j++, k++);

    if(k > 0 && searchFor[k] == '\0')
        lastOccurence = i;
            
    }
    
    return lastOccurence;
}

float asciiToFloat(char *string) {
    double floatValue, power;
    int i, sign;
    
    for(i = 0; string[i] == '\t' || string[i] == '\b' || string[i] == ' '; i++); // Skip the Whitespace
    
    sign = (string[i] == '-') ? -1 : 1;
    
    if(string[i] == '-' || string[i] == '+')
        i++;
        
    for(floatValue = 0.0; string[i] >= '0' && string[i] <= '9'; i++) {
        floatValue = floatValue * 10.0 + (string[i] - '0');
    }
        
    if(string[i] == '.')
        i++;
            
    for(power = 1.0; string[i] >= '0' && string[i] <= '9'; i++) {
        floatValue = floatValue * 10.0 + (string[i] - '0');
        power *= 10.0;
    }
    
    return (floatValue / power) * sign;
}

float asciiToFloatVersionTwo(char *string) {
    double floatValue = 0.0, power, base = 1.0;
    int i, sign;
    
    for(i = 0; string[i] == ' ' || string[i] == '\n' || string[i] == '\b' || string[i] == '\t'; i++);  // Skip Whitespaces
    
    sign = (string[i] == '-') ? -1 : 1;
    
    if(string[i] == '-' || string[i] == '+')
        i++;
        
    for(i = 0; string[i] >= '0' && string[i] <= '9'; i++)
        floatValue = floatValue * 10.0 + (string[i] - '0');
        
    if(string[i] == '.')
        i++;
        
    for(power = 1.0; string[i] >= '0' && string[i] <= '9'; i++) {
        power = power * 10.0;
        floatValue = floatValue * 10.0 + (string[i] - '0');
    }
    
    floatValue = (floatValue / power) * sign;
    
    if(string[i] == 'e' || string[i] == 'E')
        i++;
        
    for(; string[i] == ' ' || string[i] == '\n' || string[i] == '\b' || string[i] == '\t'; i++);  // Skip Whitespaces
    
    switch(string[i]) {
        case '-' :  for(; string[i] == ' ' || string[i] == '\n' || string[i] == '\b' || string[i] == '\t'; i++);  // Skip Whitespaces
                    
                    i++;
                    for(power = 0.0; string[i] >= '0' && string[i] <= '9'; i++) {
                        power = power * 10.0 + (string[i] - '0');
                    }
                    
                    while(power != 0.0) {
                        base = base * 10.0;
                        power--;
                    }
                    
                    floatValue = (floatValue) / base;
                    break;
                    
        case '+':   for(; string[i] == ' ' || string[i] == '\n' || string[i] == '\b' || string[i] == '\t'; i++);  // Skip Whitespaces
                    
                    i++;
                    for(power = 0.0; string[i] >= '0' && string[i] <= '9'; i++) {
                        power = power * 10.0 + (string[i] - '0');
                    }
                    
                    while(power != 0.0) {
                        base = base * 10.0;
                        power--;
                    }
                    
                    floatValue = (floatValue) * base;
                    break;
    }
    
    return floatValue;
}
