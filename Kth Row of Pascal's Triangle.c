int* getRow(int A, int *len1) 
{
    int * arr = (int *)malloc((A+1)*sizeof(int));
    int i,j;
    *len1 = A+1;
    arr[0]=1;
    arr[1]=1;
    for(i=2;i<=A;i++)
    {
        for(j=i-1;j>0;j--)
        {
            arr[j]=(arr[j]+arr[j-1]);
        }
        arr[i]=1;
    }
    return arr;
}

