#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*טיוטה
מערך באורך אן לא ממוין של מספרים שלמים
הפונקציה מחזירה האם קיימת חלוקה של קבוצת המספרים למערך של קיי 
תתי קבוצות 
כל שסכום כל המספרים בכל תת קבוצה זהה
כל איבר שייך לתת קבוצה אחת ויחידה
בשאלות כאלה נחשוב על דרך פשוטה לפתור
קודם כל נעשה מערך עזר לסכום בגודל של החלוקה שלנו
כל תא יחשב סכום של תת קבוצה 
גודל הקבוצות לא רלוונטי אלא הסכום של כל קבוצה
אז פונקציה אחת לבדוק אם הסכום בכל אחד מהמקומות שווה לשני
נזכור שבמקרים כאלה צריך פונקצית מעטפת שאשתמש בפונקציה שנתנו בשאלה
*/
bool IsKSplittable (int arr[],int n, int k);
bool isEqual(int k, int sum[]);
bool IsKSplittable_work(int arr[],int n, int k, int current, int sum[]);
bool isEqual(int k, int sum[]){
    for(int i=1;i<k;i++){
        if(sum[i] != sum[i-1]) return false;
    }
    return true;
}
int main(){
    int arr[11] = {9,-2,3,17,5,3,8,4,1,1,2};
    int k1= 3, k2=4;
    printf("the answer is %d\n\n",IsKSplittable(arr,11,k1) );//true 1
    printf("the answer is %d\n\n",IsKSplittable(arr,11,k2) );//false 0
}
bool IsKSplittable (int arr[],int n, int k){
    int *sum = malloc(k*sizeof(int));
    int current = 0;
    bool answer = IsKSplittable_work(arr,n, k,current,sum);
    free(sum);
    return answer;

}
bool IsKSplittable_work(int arr[],int n, int k, int current, int sum[]){
    if (current == n){ // we made it to the end
       return  isEqual(k,sum);
    }
    for(int i=0; i<k;++i){
        sum[i] =  sum[i] + arr[current];
        if(IsKSplittable_work(arr,n, k,current+1,sum)) return true;
        sum[i] = sum[i] - arr[current];
    }
    return false;
}
