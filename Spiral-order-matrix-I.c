int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(*length_of_array * sizeof(int));
	 int T =0;
	 int L=0;
	 int dir=0;
	 int B=n11-1;
	 int R=n12-1;
	 int index =0;
	 int i=0;
	 while(T<=B && L<=R)
	 {
	     if(dir==0)
	     {
	         for(i=L;i<=R;i++)
	         {
	             result[index]= A[T][i];
	             index++;
	         }
	         T++;
	         dir=1;
	     }
	     else
	     {
	         if(dir==1)
	         {
	              for(i =T;i<=B;i++)
	              {
	                  result[index]=A[i][R];
	                  index++;
	              }
	              dir=2;
	              R--;
	         }
	         else
	         {
	             if(dir==2)
	             {
	                 for(i=R;i>=L;i--)
	                 {
	                     result[index]=A[B][i];
	                     index++;
	                 }
	                 dir=3;
	                 B--;
	                 
	             }
	             else
	             {
	                 if(dir==3)
	                 {
	                    
	                    for(i=B;i>=T;i--)
	                    {
	                        result[index]=A[i][L];
	                        index++;
	                    }
	                    L++;
	                    dir=0;
	                 }
	             }
	             
	         }
	         
	     }
	 }
	 return result;
}
