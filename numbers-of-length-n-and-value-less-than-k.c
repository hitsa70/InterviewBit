int solve(int* A, int n1, int B, int C) {
    int temp = 1,i=1,rem,idx,total = 0,is_first = 1;
    
    
    while(i<B)
    {
        temp *= 10;
        i++;
    }
    if(temp>C)
       return 0;
    while(temp){
        rem = C/temp;
        C = C%temp;
        temp = temp/10;
        idx = findIndex(A,n1-1,0,rem);
        if(idx == -1)
            break;
        if(is_first && A[0]!=0)
            is_first = 0;
        if(A[idx] != rem){
            idx++;        
            total += getTotal(idx,i,is_first,n1);
            break;
        }
        total += getTotal(idx,i,is_first,n1);
       // printf("%d \n",total);
        i--;
        is_first = 0;
    }
    
    return total;
}

int getTotal(int idx, int dec, int is_zero,int total)
{
    int ret,i = 0;
   // printf ("%d, %d, %d, %d\n", idx, dec, is_zero, total);
    if(idx == -1)
        return 0;
    if(is_zero && dec != 1){
        idx--;
    }
    ret = idx;
    while(i<dec-1){
        ret *= total;
        i++;
    }
    return ret;
}

int findIndex(int* A, int len, int start, int num)
{
    int ret = -1;
    int mid = (start + len)/2;
    if(start > len)
        return -1;
    if( (mid == len || A[mid+1] > num) && A[mid] <= num){
        ret =  mid;    
    }else if(A[mid] < num){
        ret = findIndex(A,len,mid+1,num);
    }
    else{
        ret = findIndex(A,mid-1,start,num);
    }
    return ret;
}
