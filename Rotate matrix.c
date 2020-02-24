
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.
*/





void rotate(int** a, int r, int c) {
    int tmp, i, j;
    
    /**
    * Swap ith row with (r-1-i)th row of the matrix in place,
    * i.e., 1st row with last row, 2nd row with 2nd last row and so on.
    */
    for(i=0;i<r/2;i++)
    {
        for(j=0;j<c;j++)
        {
            tmp=a[i][j];
            a[i][j]=a[r-1-i][j];
            a[r-1-i][j]=tmp;
        }
    }
    /**
    * Do in place transpose of the matrix to get the desired rotated matrix
    */
   for(i=0;i<r;i++)
    {
        for(j=0;j<i;j++)
        {
            tmp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=tmp;
        }
    }
}

