#include <stdio.h>
#include <stdlib.h>


int insertion(int arr[],int n){
    int i,j,key;

    for (i=1;i<n;i++){
        key=arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main() {
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    insertion(arr,n);

    for(i=0;i<n;i++){
        printf("%d", arr[i]);
    }
}