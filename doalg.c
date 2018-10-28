#include "COMPARE.c"
#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
  
void minHeapify(int minArray[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    if(l<size && COMPARE(minArray[l],minArray[smallest])==2)
        smallest = l;
    if(r<size && COMPARE(minArray[r],minArray[smallest])==2)
        smallest = r;
    if(smallest!=i)
    {
        swap(&minArray[i],&minArray[smallest]);
        minHeapify(minArray,size,smallest);
    }
     
}
  
  
void buildMinHeap(int a[], int size) {
    for(int i=size/2;i>=0;i--)
        minHeapify(a,size,i);
         
}

int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (COMPARE(item , a[low])==1)?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(COMPARE(item , a[mid])==1) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
void insertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        loc = binarySearch(a, selected, 0, j); 
  
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 

  
int doalg(int n, int k, int Best[]){
    int i,j;
    int minArray[40];
    for(i=1,j=0;i<=k;i++,j++){
        minArray[j] = i;
    }
     buildMinHeap(minArray,k);
     for(i=k+1;i<=n;i++)
    {
        if(COMPARE(i,minArray[0])==1)
        {
            minArray[0]=i;
            minHeapify(minArray,k,0);
        }
    }
    insertionSort(minArray,k);
    j=k-1;
    for(i=0;i<40;i++){
        Best[i]=minArray[j];
        j--;
    }
    return 1;
}
 
