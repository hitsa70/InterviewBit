int segregate(int arr[], int n)
{	
	int i, j =0;
	int temp;
	for(i =0; i<n; i++)
	{
		if(arr[i]<=0)
		{   
		    temp = arr[i];
		    arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
	}
	return j;			//j is the size of the segregated array
}

 int findMissingPositive(int arr[], int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		if(abs(arr[i])-1<n && arr[abs(arr[i])-1]>0)
		{
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		}
		
	}
	
	for(i =0; i<n; i++)
	{
		if(arr[i]>0)
		return i+1;
	}
	return n+1;    //in case all the positive elements are available to the size of the positive array
}
int firstMissingPositive(int* A, int n1) {

	//segregating the non positive elements from the array
	int k = segregate(A, n1);
	
	//find the missing least positive from remaining array of positive elements
	return findMissingPositive(A+k, n1-k);
}
    
