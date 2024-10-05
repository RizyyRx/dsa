#include <stdio.h>

//give two pointers to variables with type int (pointers to integers)
//int* index1, int* index2 holds the address of var index1 and index2
void two_pointer(int* arr,int left, int right, int target, int* index1, int* index2){

    while(left<=right){
        if(arr[left] + arr[right] == target){
            *index1 = left; //*index1 refers to the value stored in index var (dereferencing a pointer)
            *index2 = right; //same here, this will modify the values of index1 and index2
            return;
        } else if(arr[left] + arr[right] < target){
            left = left + 1;
        } else if(arr[left] + arr[right] > target){
            right = right - 1;
        }
    }
    *index1 = -1;
    *index2 = -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int target, index1, index2;
    int right = (sizeof(arr)/sizeof(arr[0])) - 1;
    printf("Enter a target:");
    scanf("%d",&target);
    two_pointer(arr,0,right,target,&index1,&index2);

    if(index1 == -1){
        printf("target not available in the array\n");
    } else{
        printf("The indexes are:%d and %d",index1, index2);
    }
}