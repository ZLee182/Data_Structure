#include <iostream>

using namespace std;
typedef int ElemType;

int Partition(ElemType a[],int low, int high)
{
	int i;
	ElemType mid = a[low];
	while(low < high)
	{
		while( low < high && a[high] <= mid )
			--high;
		a[low] = a[high];
		
		while( low < high && a[low] >= mid )
			++low;
		a[high] = a[low];
	}
	a[low] = mid;
	
	return low;
}

void QuickSort(ElemType a[],int low,int high)
{
	if(low < high)
	{
		int mid = Partition( a, low , high);
		QuickSort( a, low, mid - 1);
		QuickSort( a, mid + 1 , high);
	}
}

int main()
{
    int a[]={10,2,3,4,5,6,9,8,7,1};
	int i;
	QuickSort(a,0,10);
	for(i = 0; i < 10 ; i++ )
		cout << a[i] <<" ";
	return 0;
}
