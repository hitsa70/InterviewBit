/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in length_of_array
 */
int* maxset(int* a, int n1, int *length_of_array) {
    long long sum=0,i=-1,startindex=0,count,max_count=0,max_sum=0;
     
       *length_of_array = n1;
      int * ret = (int *) malloc(sizeof(int) * *length_of_array);
       while(i<n1)
       {
           i++;
           startindex=i;
           count=0;
           sum=0;
           while(i<n1&&a[i]>=0)
           {
               sum+=(long long)a[i++];
               count++;
           }
           if(sum>max_sum||((sum==max_sum)&&(count>max_count)))
           {
               max_sum=sum;
               max_count=count;
               memcpy(ret,a+startindex,max_count*sizeof(int));
           }
                                                                               
       }
          *length_of_array=max_count;            
       return ret;
     }
