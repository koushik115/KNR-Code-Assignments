#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);
double asciitofloat(char src[]);
double asciitofloatver2(char src[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    double sum, asciitofloat(char []);
    int getLine(char line[], int max);

    char strOne[] = "banana";
    char strTwo[] = "na";

    
    sum = 0;
    while(getLine(line, MAXLINE) > 0)
    {
        printf("%.9f", sum += asciitofloatver2(line));
    }

    // return found;

    printf("%d", strrindex(strOne, strTwo));
    
}

int getLine(char s[], int lim)
{
    int i = 0, c = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int strindex(char source[], char searchfor[])
{
    int i, j, k;

    for(i = 0; source[i] != '\0'; i++)
    {
        for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++);

        if(k > 0 && (source[i] == searchfor[k]))
            return i;
    }

    return -1;
}

int strrindex(char s[], char t[])
{
    int i = 0, j = 0, k = 0;

    for(i = strlen(s) - 1; i >= 0; i--)
    {
        if(i < strlen(t) - 1)
            break;

        for(j = i, k = (strlen(t) - 1); k >= 0 && s[j] == t[k]; j--, k--)
            ;

        if(k == -1)
            return j + 1;
    }

    return -1;
}

double asciitofloat(char src[])
{
    double val = 0.0, power = 0.0;
    int i, sign;

    for(i = 0; src[i] == ' ' || src[i] == '\t'; i++);

    sign = src[i] == '-' ? -1 : 1;
    if(src[i] == '-' || src[i] == '+')
        ++i;

    for(val = 0.0; src[i] >= '0' && src[i] <= '9'; ++i)
        val = val * 10 + (src[i] - '0');

    if(src[i] == '.')
        ++i;

    for(power = 1.0; src[i] >= '0' && src[i] <= '9'; ++i)
    {
        val = val * 10 + (src[i] - '0');
        power *= 10;
    }
    
    
    return (sign * (val / power));
}

double asciitofloatver2(char src[])
{
    double value, power, exp;
    int i, j, sign, expsign, expbase;

    for(i = 0; src[i] == ' ' || src[i] == '\t'; i++);

    sign = src[i] == '-' ? -1 : 1;
    if(src[i] == '-')
        ++i;

    for(value = 0.0; src[i] >= '0' && src[i] <= '9'; ++i)
        value = value * 10.0 + (src[i] - '0');

    if(src[i] == '.')
        ++i;

    for(power = 1.0; src[i] >= '0' && src[i] <= '9'; ++i)
    {
        value = value * 10.0 + (src[i] - '0');
        power *= 10.0;
    }

    value /= power;

    if(src[i] == 'e' && (src[i + 1] == '-' || src[i + 1] == '+'))
        i += 1;

    expsign = src[i] == '-' ? -1 : 1;

    if(src[i] == '-' || src[i] == '+')
        ++i;

    for(expbase = 0; src[i] >= '0' && src[i] <= '9'; ++i)
          expbase = expbase * 10 + (src[i] - '0');
    
    for(exp = 1.0, j = 0; j < expbase; j++)
        exp *= 10;

    if(expsign == -1)
        return (sign * (value / exp));
    else
        return (sign * value * exp);
}
