//Given an integer array, find if an integer p exists in the array such that the 
//number of integers greater than p in the array equals to p
//If such an integer is found return 1 else return -1.



void swap(int *A,int i,int j)
{
    int temp;
    temp = A[i];A[i] = A[j];A[j] = temp;
    return;
}
/* partition function of quicksort */
int partition(int *A,int start,int end)
{
    int pivot = A[end];//choose pivot as last element
    int i,j;
    i = start-1;j = start;
    //i stores the index upto which elements are smaller than pivot element
    for(j=start;j<end;j++)
    {
        if(A[j]<pivot)
        {
            i++;swap(A,i,j);
        }
    }
    // increase i by 1 swap A[i] with A[end] and i becomes the partition index
    i++;swap(A,i,end);
    return i;
}
// recursive sorting technique
void Quicksort(int *A,int start,int end)
{
    if(start>=end) return;
    int p;
    // partition the given array such that elements below partition are smaller than 
    // element at partition and elements above partition are greater than element at 
    // partition
    p = partition(A,start,end);
    //recursively sort A[start.....partition-1]and A[partition+1.....end]
    Quicksort(A,start,p-1);
    Quicksort(A,p+1,end);
}
int solve(int* A, int n1) {
    int i,j,cur;
    i = 0;
    if(n1==0) return -1;//base cases
    if(n1==1){
        if(A[0]==0) return 1;
        else return -1;
    }
    Quicksort(A,0,n1-1);//sort the array
    while(A[i]<0)i++;//ignore negative elements
    while(i<n1)
    {
        cur = A[i];// store current element
        while((i<n1)&&(A[i]==cur))i++;//ignore copies of current element
        j = n1 - i;//no of elements greater than cur
        if(cur==j) return 1;
    }
    return -1;
}
