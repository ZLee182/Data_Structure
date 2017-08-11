#include <iostream>

using namespace std;
typedef int ElemType;

void swap(int *a,int *b)//交换两个数的位置，首先将堆顶元素输出，然后再把最后一个位置的元素放到堆顶，再进行调整
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void AdjustDown(ElemType a[],int k,int len)//进行大根堆调整，发现这个数值小于子节点，就进行下调
{
	int i;
	a[0] = a[k];
	for(i = 2*k; i<=len; i*=2)
	{
		if(i<len && a[i]<a[i+1])
			i++;
		if(a[0]>=a[i])
			break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
}

void BuildMaxHeap(ElemType a[],int len)//建立大根堆
{
	int i;
	for(i = len/2; i > 0;i--)
		AdjustDown(a,i,len);
}

void HeapSort(ElemType a[],int len)//堆排序
{
	BuildMaxHeap(a,len);
	for(int i=len;i>0;i--)//输出元素，并不断进行调整堆排序
	{
		swap(a[1],a[i]);
		AdjustDown(a,1,i-1);
	}
}

int main()
{
	int a[]={0,1,3,2,4,6,5,9,8,7,10,21};
    HeapSort(a,12);
	for(int i =1;i<=12;i++)
		cout << a[i] << " ";
    return 0;
}
