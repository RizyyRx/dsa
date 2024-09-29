#include <stdio.h>

/*func for binary search,
 *takes a target integer and pointer to an array as arg
 */
int binary_search(int* arr,int target,int size){

    int low=0; //init low as 1st index of array
    int high=size-1; //init high as last index of array

    while(low<=high){ //if element not present, low val will become greater than high. do the loop until that happens..
        printf("in loop\n");
        int mid = (low + high) / 2; //calc mid
        printf("low: %d\n",low);
        printf("high: %d\n",high);
        printf("mid: %d\n",mid);

        if(arr[mid] == target){ //check if mid element is target
            printf("Target found....\n");
            return mid; //return index of target in the array
        } else if(arr[mid] > target){ //check if mid element is greater that target (means, target is on left half)
            printf("mid gr than target, updating high...\n");
            printf("target must be on left half...\n");
            high = mid - 1; //update high to mid - 1, since we dont need to check right half
        } else if(arr[mid] < target){ //check if mid element is lesser that target(means, target is on right half)
            printf("mid less than target, updating low....");
            printf("target must be on right half...\n");
            low = mid + 1; // update low to mid + 1, since we dont need left half
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int target;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The array is ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Enter a num to search from the array: ");

    scanf("%d",&target);

    int target_index=binary_search(arr,target,size);
    
    if(target_index == -1){
        printf("target not available on array\n");
    } else{
        printf("target index is %d",target_index);
    }
}