#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*טיוטה עבורי
נתון מערך ממויון של מספרים שלמים
המספרים שבמערך שונים זה משה
נקודת שבת אם המקום של המערך שווה לערך של המערך
צריך לממש פונקציה שמחזיק את אחת מהנקודות אם היא קיימת
הסיבוכיות היא של לוג אז נשתמש בחיפוש בינארי
*/
int FindFixedPoint (int arr[], int n);
int main(){
    int arr[8]={-1,0,1,2,4,6,13,42}; // 4
    int arr2[5] = {0,1,5,6,7}; // 0
    int arr3[7] = {-3,0, 2,5,6,7,8};//2
    printf("\n\nthe answer is %d\n\n", FindFixedPoint(arr3,7));
}
// log n סיבוכיות לשים לב

int FindFixedPoint (int arr[], int n){
    int low =0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==mid){
            return arr[mid];
        } 
        else if(arr[mid]<mid){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;

}

    
    


