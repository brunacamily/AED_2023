#include <stdio.h>

void Quicksort (int data[],int left,int right);

int main()
{
    int a[7]={9,1,2, 1,40, 7, 0};

  //  Quicksort(a, 2, 3);
    Quicksort(a, 0, 7);
   // Quicksort(a, 6, 0);
    for(int i=0; i<7; i++)
    
    printf("%d\n", a[i]);
    
    return 0;
}

void Quicksort (int data[],int left,int right) {
  int mid,tmp,i,j;
  i = left;
  j = right;
  mid = data[(left + right)/2];
  do { 
    while(data[i] < mid)
      i++;
    while(mid < data[j])
      j--; 
    if (i <= j) { 
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp; 
      i++; 
      j--;
    }
  } while (i <= j);

  if (left < j) 
    Quicksort(data,left,j);
  if (i < right)
    Quicksort(data,i,right);

}