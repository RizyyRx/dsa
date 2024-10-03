#include <stdio.h>

int recursive_binary_search(int* arr, int low, int high, int target){

    if(low > high){ // recursion stopping checker
        return -1;
    }

    int mid = ((high + low) / 2); // calc mid
    printf("low: %d\n",low);
    printf("high: %d\n",high);
    printf("mid: %d\n",mid);

    if(arr[mid] == target){
        printf("target found\n");
        return mid;
    } else if(arr[mid] > target){
        printf("target is low\n");
        high = mid - 1;
        recursive_binary_search(arr, low, high, target); // do recursion with updated high val
    } else if (arr[mid] < target){
        printf("target is high\n");
        low = mid + 1;
        recursive_binary_search(arr, low, high, target); // do recursion with updated low val
    }
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;

    printf("enter the target:");
    scanf("%d", &target);

    int index = recursive_binary_search(arr, 0, size - 1, target);

    if(index == -1){
        printf("Target not available in array\n");
    } else{
        printf("the target is in index %d\n", index);
    }
}