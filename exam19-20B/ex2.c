#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*טיוטה
נתון מערך בינארי שמכיל רק אפסים ואחדים ונתון מספר שלם קיי
צריך למצוא את האורך של תת סדרה רציפה ארוכה ביותר של איי שכוללת לכל היותר קיי אפסים

*/
int LongesrSequence(int a[], int n, int k);
int main(){
    int a[12] = {1,1,0,1,1,0,1,1,1,1,0,0};
    int k1 = 0; //4
    int k2 = 1; //7
    int k3 = 2; //10
    int k4 = 3; //11
    printf("answer k=0 %d\n\n" , LongesrSequence(a,12,k1));
    printf("answer k=1 %d\n\n" , LongesrSequence(a,12,k2));
    printf("answer k=2 %d\n\n" , LongesrSequence(a,12,k3));
    printf("answer k=3 %d\n\n" , LongesrSequence(a,12,k4));
}
int LongesrSequence(int a[], int n, int k){
    int current=0, max=0,temp=0, count=-1, start=0;
    while(current<n){
        while(temp<=k && current<n){
            if(a[current]==0){
                count++;
                temp++;
                current++;
            }
            else{
                count++;
                current++;
            }
            
        }
        temp = 0;
        if(count>max){
            max=count;
        }
        start++;
        current = start;
        count=-1;
    }
    return max;
}
