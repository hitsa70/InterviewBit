int ** generateMatrix(int A, int *len1, int *len2) {
	// SAMPLE CODE
        
          *len1= A;
         *len2= A;
          int **result = (int **)malloc(A * sizeof(int *));
          int dir=0,i,n=1,t=0,b=A-1,l=0,r=A-1;
          for (i=0; i<A; i++)
                result[i] = (int *)malloc(A * sizeof(int));
         // DO STUFF HERE
         while(t<=b&&l<=r)
         {
             switch (dir)
             {
                 case 0 :
                  {
                      for(i=l;i<=r;i++)
                      {
                          result[t][i]=n;
                          n++;
                      }
                      t++;
                      dir++;
                      break;
                  }
                  case 1 :
                  {
                      for(i=t;i<=b;i++)
                      {
                          result[i][r]=n;
                          n++;
                      }
                      r--;
                      dir++;
                      break;
                  }
                  case 2 :
                  {
                      for(i=r;i>=l;i--)
                      {
                          result[b][i]=n;
                          n++;
                      }
                      b--;
                      dir++;
                      break;
                  }
                  case 3 :
                  {
                      for(i=b;i>=t;i--)
                      {
                          result[i][l]=n;
                          n++;
                      }
                      l++;
                      dir=0;
                      break;
                  }
             }
         }
         
          return result;
         
}
