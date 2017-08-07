void InsertSort()
{
	int a[11]={0,10,2,4,5,6,9,8,1,3,7};//第一个0位置空出，用作储存
	int i,j,n=11;
	int low,high,mid;
	for(i=1; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	
	cout << "10个数字按照折半插入排序所得结果是：" << endl;
	
	for( i =  2; i < n ; i++ )
	{
		low = 1;
		high = i-1;
		a[0] = a[i];
		while( low <= high )
		{
			mid = (low + high)/2;
			if(a[0]<a[mid])
				high = mid -1;
			else
				low = mid + 1;
		}
		
		for(j =i-1; j >= high+1 ; --j )
			a[ j + 1 ] = a[ j ];
		a[ high + 1 ] = a[ 0 ];
	}
	
	for(i=1; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	
    return 0;
}
