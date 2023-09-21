#include <stdio.h>

void Quicksort (int a[],int left,int right);

int main()
{
    int a[5]={5,4,3,2,1};

  
    Quicksort(a, 0, 5);
   
    for(int i=0; i<5; i++)
    
    printf("%d\n", a[i]);
    
    return 0;
}

void Quicksort (int a[],int left,int right) {
  int mid,tmp,i,j;
  i = left;
  j = right;
  mid = a[(left + right)/2];
  do { 
    while(a[i] < mid)
      i++;
    while(mid < a[j])
      j--; 
    if (i <= j) { 
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp; 
      i++; 
      j--;
    }
  } while (i <= j);

  if (left < j) 
    Quicksort(a,left,j);
  if (i < right)
    Quicksort(a,i,right);

}