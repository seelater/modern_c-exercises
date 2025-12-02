#include <stdio.h>
#include <stddef.h>

void merge(int [],int,int, int);
void merge_sort(int [],int, int);
void print_arr(int* ,size_t size);

int main(void) {
    int unsorted[] = {6,5,1,7,33,21,15};
    int unsorted_size = sizeof(unsorted) / sizeof(unsorted[0]);

    merge_sort(unsorted,0,unsorted_size-1);
    print_arr(unsorted,unsorted_size);
    return 0;
}

void merge_sort(int* a, int left, int right) {  
    int mid;
    
    if (left >= right)
        return;
    mid =  (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    merge(a, left,mid, right);
}

void merge(int* a,int left,int mid,int right) {
    size_t i,j,k;

    size_t n1= mid - left+1;
    size_t n2= right - mid;
    int l[n1];
    int r[n2];
        
    for (i=0; i<n1; ++i) {
        l[i]=a[left+i];
    }
    for (j=0; j<n2; ++j) {
        r[j]=a[mid+1+j];
    }

    i=0,j=0,k=left;
    while (i<n1 && j<n2 ) {
        if (l[i]<r[j]) {
            a[k++] = l[i++];
        }else {
            a[k++]=r[j++];
        }
    }
    while (i < n1) {
        a[k++] = l[i++];
    }
    while (j < n2) {
        a[k++] = r[j++];
    }
}
void print_arr(int* a ,size_t size){
    while( size-- ){
        printf("%d\n",*a++);
    }
}

