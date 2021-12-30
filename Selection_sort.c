#include<stdio.h>
#include<stdlib.h>


int swap(int *a,int *b){
    int c;
    c= *a;
    *a = *b;
    *b = c;
}


int selection_sort(int arr[],int n){
    int i,j,min_index;

    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[min_index],&arr[i]);
    }
}

int main() {

    int n,i;
    printf("Enter the number of entries:\n");
    scanf("%d",&n);

    int arr[n];

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    selection_sort(arr,n);
    
    for(int k=0;k<n;k++){
        printf("%d\t",arr[k]);
    }
}