#include <iostream>

using namespace std;
typedef int ElemType;

//ElemType *b = (ElemType *)malloc(sizeof(ElemType)*10);

void Merge(ElemType a[], ElemType b[], int low, int mid, int high)
{
	int i,j,k;
	
	for(i = low;i<=high;i++)
		b[i] = a[i];
	
	for( i = low,j = mid+1, k =i;i<=mid && j<=high ;k++ )
	{
		if(b[i]<b[j])
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while(i<=mid)
		a[k++] = b[i++];
	while(j<=high)
		a[k++] = b[j++];
}

void MergeSort(ElemType a[], ElemType b[] ,int low, int high)
{
	if(low<high)
	{
		int mid = ( low + high )/2;
		MergeSort(a,b,low,mid);
		MergeSort(a,b,mid+1,high);
		Merge(a,b,low,mid,high);
	}
}

int main()
{
	int a[]={0,1,3,2,4,6,5,9,8,7};
	int b[]={0,0,0,0,0,0,0,0,0,0};
	MergeSort(a,b,0,9);
	for(int i =0;i<10;i++)
		cout << a[i] << " ";
    return 0;
}
