#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ABC 26
/*טיוטה
נתונות אן קוביות של אותיות. על כל פאה של כל ובייה מצוירת אות אנגלית אחת
אך בכל קובייה יתכן מספק שונה של פאות 
לכל קוביה צבע כאשר הצבע הוא מספר בין 0 לאן פחות אחת
פונקציות עזר 
בדיקת קלט- אם המילה באורך שיותר גדול מכמות הקוביות או שיותר גדול מכמות הצבעים
בודק גם אם אותיות לא נמצאות נשתמש בהיסטרו
*/
bool Scramble(char* cubes[], int n, int colors[], char* target);
bool Scramble_do(int count, char* cubes[], int n, int colors[], char* target, int l, int count_color[], int words[]);
bool checkInput(char* cubes[], int n, int colors[], char* target, int histro_letter[], int count_color[]);
int len(char* str);
bool isExistInStr(char*str, int words[],int count_color[], int color);

int main(){
    char* cubes[4] = {"ABC", "AEI", "EOU","LNRST"};
    int colors[4] = {0,0,1,2};
    printf("%d answer \n\n", Scramble(cubes,4,colors,"BOT"));
}
bool Scramble(char* cubes[], int n, int colors[], char* target){
    int histro_letter[ABC] = {0};
    int l = len(target);
    int* count_color = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        count_color[colors[i]]++;
    }
    int words[ABC] = {0};
    for(int i=0;i<n;i++){
        words[target[i]-'A']++;
    }
    if(!checkInput(cubes,n,colors,target,histro_letter, count_color)){
        free(count_color);
        return false;
    } 
    bool answer =  Scramble_do(0,cubes,n,colors,target,l,count_color,words);
    free(count_color);
    return answer;
   
}
bool Scramble_do(int count, char* cubes[], int n, int colors[], char* target, int l, int count_color[], int words[]){
    if(count==l){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isExistInStr(cubes[i], words, count_color,colors[i])){
            return Scramble_do(count+1, cubes,n,colors,target,l,count_color,words);
        }
    }
    return false;
}
bool checkInput(char* cubes[], int n, int colors[], char* target, int histro_letter[], int count_color[]){
    for(int i=0;i<n;i++){
        int l = len(cubes[i]);
        for(int j=0;j<l;j++){
            histro_letter[cubes[i][j] -'A']++;
        }
    }
    int l = len(target);
    for(int i=0; i<l;i++){
       if(histro_letter[target[i]-'A']==0){
        return false;
       }
        
    }
    int numColor=0;
    for(int i=0;i<n;i++){
        if(count_color[i]!=0) numColor++;
    }
    if(numColor<l){
        return false;
    } 
    return true;
}
int len(char* str){
    int len=0; 
    for(;str[len];len++);
    return len;
}
bool isExistInStr(char*str, int words[],int count_color[], int color){
    int l=len(str);
    bool isIn=false;
    bool isColor = false;
    for(int i=0;i<l;i++){
        if(words[str[i] -'A']>0){
            words[str[i] -'A']--;
            isIn=true;
        }
    }
    if(count_color[color]>0){
        isColor=true;
        count_color[color]=0;
    }
    return isIn&&isColor;
}



