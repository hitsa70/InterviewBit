#include <stdio.h>
/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row.
 * For each row i, A[i][0] should indicate the number of columns in row i. 
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
int ** generate(int A, int *number_of_rows) {
	// SAMPLE CODE
	
	  *number_of_rows = A;
	  int **result = (int **)malloc(A * sizeof(int *));
	  int i,j;
	  result[0] = (int *)malloc(2 * sizeof(int));
	  result [0][0]=1;
	  result [0][1]=1;
	  for(i=1;i<A;i++)
	  {
	      result[i] = (int *)malloc((i+2) * sizeof(int));
	     
	      for(j=1;j<=i;j++)
	      {
	         result[i][j]=result[i-1][j]+result[i-1][j-1]; 
	      }
	       result[i][0]=i+1;
	       result[i][1]=1;
	      result[i][j]=1;
	      
	  }
	
	  return result;
	 

}
