#include<stdio.h>
#include<stdlib.h>


int swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}


int bubble_sort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j = n-i-1;j++){
            if(arr[i] > arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}


int main(){
    int n;

    printf("Enter the number of entries:\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the entries:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    bubble_sort(n,arr);
    for(int k=0;k<n;k++){
        printf("%d\t",arr[k]);
    }
}