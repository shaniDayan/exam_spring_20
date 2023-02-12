#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ABC 26
/*טיוטה
גיוון פונטי זה קבוצת התווים שמופיעים במחרוזת בלי חזרות
צריך פונקציה שמחזירה את האורך של תת מחרוזת הקצרה ביותר בעלת גיוון שזהה לזה של המחרוזת
נגיד בדוגמא זה יחזיר 7 כי קודם נבדוק את הגיוון בפונקציה אחרת ואז נעבור 
כמו בתרגיל הקודם על הכל ונשווה בין דברים
נתשמש בהיסטוגרמה 
*/
int ShortestSubstring(char* str);
int lenght(char* str);
bool comparStr(int histro [], int subHistro[]);
int main(){
    char str[]="aabcaadefacebaa";
    printf("answer = %d\n\n", ShortestSubstring(str));
}
int lenght(char* str){
    int len=0;
    for(;str[len];len++);
    return len;
}
bool comparStr(int histro [], int subHistro[]){
    for(int i=0;i<ABC;i++){
        if(histro[i] != subHistro[i]){
            return false;
        }
    }
    return true;
}
int countS(int histro[]){
    int count=0;
    for(int i=0;i<ABC;++i){
        if(histro[i]>0) count++;
    }
    return count;
}
int ShortestSubstring(char*str){
    int len = lenght(str);
    int count=0, min=len, current=0;
    int histro[ABC]= {0};
    for(int i=0;i<len;i++){
        histro[str[i] -'a']++;
    }
    while(current<len){
        int subHistro[ABC] = {0};
        for (int i=current; i<len;i++){
            subHistro[str[i]-'a']++;
        }
        if(comparStr(histro, subHistro)){
            if(countS(histro)<min){
                min=countS(histro)+1;
            }
        }
         for (int i=current; i<len;i++){
            subHistro[str[i]-'a']=0;
        }
        current++;
    }
    return min;
}
