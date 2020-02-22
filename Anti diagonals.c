//Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.



int min(int a,int b)
 {
     if(a<b)return a;
     return b;
 }
int ** diagonal(int** A, int n11, int n12, int *len1) {
    int i,j,k=0,r=0;
    int m=min(n11,n12);
    *len1=2*min(n11,n12)-1;
    int** result=malloc(sizeof(int*)*(*len1));
  //  int m=min(n11,n12);
    for(i=0;i<m;i++)
    {int a=0,b=i,r=0,n=i+1;
     result[k]=malloc(sizeof(int)*(i+2));
        result[k][r]=n;
        r++;
        while(a<m && b>=0 )
        {
            result[k][r]=A[a][b];
            a++;b--;r++;
        }
        k++;
    }
    for(i=1;i<m;i++)
    {
        int a=i,b=m-1,r=0;
        int n=m-i;
        result[k]=malloc(sizeof(int)*(m-i+1));
        result[k][r]=n;
        r++;
        while(a<m && b>=0 )
        {
            result[k][r]=A[a][b];
            a++;b--;r++;
        }
        k++; 
    }
    *len1=k;
    return result;
}

