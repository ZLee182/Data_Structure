#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int p;
	p = *b;
	*b = *a;
	*a = p;
}

int main()
{
    int a[]={0,10,2,3,6,5,4,9,8,7,1};
	int n=11;
	int i,j;
	for( i = 0 ; i < n ;i++)
	{
		for( j =  n-1; j > 0 ; j--)
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
	}
	for( i =1; i<n ;i++)
		cout << a[i] << " ";
    return 0;
}
