#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}


int opti_bubble(int arr[],int n){
    bool swap1;
    for(int i=0;i<n-1;i++){
        swap1 = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j+1],&arr[j]);
                swap1 = true;
            }
        }

        if(swap1 == false){
            break;
        }
    }
}


int main(){
    int n;
    printf("Enter the number of entries:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    opti_bubble(arr,n);
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}