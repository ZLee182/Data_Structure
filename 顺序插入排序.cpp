void InsertSort()
{
	int a[11]={0,10,2,4,5,6,9,8,1,3,7};//第一个0位置空出，用作储存
	int i,j,n=11;
	
	for(i=1; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	
	cout << "10个数字按照顺序插入排序所得结果是：" << endl;
	
	for( i =  2; i < n ; i++ )
	{
		a[0] = a[i];
		for(j =i-1; a[0]<a[j]; --j )
			a[j+1] = a[j];
		a[j+1] = a[0];
	}
	
	for(i=1; i<n; i++)
		cout << a[i] << " ";
	cout << endl;

}
