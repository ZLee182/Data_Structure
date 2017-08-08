#include <iostream>

using namespace std;
typedef int ElemType;

void SelectSort(ElemType a[],int n)
{

     int i,j;
     int min,res;
     for(i=0;i<n;i++)
     {
          min=i;
          for(j=i;j<n;j++)
          {
                if(a[min]>a[j])
                {
                       min=j;
                 }
          }
          res=a[i];
          a[i]=a[min];
          a[min]=res;
     }
}
int main()
{
	int a[]={10,9,6,7,8,4,5,3,2,1};
	SelectSort(a,10);
	int i;
	for(i=0;i<10;i++)
		cout << a[i] << " " ;
    return 0;
}
