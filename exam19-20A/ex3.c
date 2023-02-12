#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*טיוטה עבורי
הפונקציה מקבלת מחרוזת המכילה מילים המופרדות ברווחים
ותשנה את המחוזת כך שסדר המילים יתהפך
בסיבוכיות של אן כלומר של אורך הפונקציה

לשים לב שהכמות רווחים צריכה להיות אותו דבר 

*/
void reverse_words(char* str);
int lenght(char* str);
void reverse(int start, int end, char *str);
int main(){
    char str[] = "z    we are so  bad";
     reverse_words(str);
    //"bad  so are we"
    // "dab  od "
}

void reverse_words(char* str){
    int n = lenght(str);
    for(int i=0; i<n; i++, n--){
        char temp = str[i];
        str[i] = str[n-1];
        str[n-1] = temp;
    }
    int i=0;
    n = lenght(str);
    while(i<n){
        while(str[i] == ' ') i++;
        int start=i;
        while(str[i] != ' ' && i<n) i++;
        int end = i - 1;
        reverse(start, end, str);
    }
}
void reverse(int start, int end, char *str){
    for(;start<end; start++, end--){
        char temp = str[start];
        str[start] = str[end];
        str[end] =temp;
    }

}
int lenght(char* str){
    int l=0;
    for(;str[l]!='\0';l++);
    return l;
}