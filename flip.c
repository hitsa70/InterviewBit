/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* flip(char* A, int *len1) {
   // int* flip(char* A, int *len1) {
    int i,j;
    int len = strlen(A);
    int finalsum = 0;
    int sum = 0;
    int *res = (int*)malloc(sizeof(int)*2);
    int start, end;
    *len1 = 0;
    res[0] = res[1] = -1;
    start = end = 0;
    
    for (i = 0; i < len; i++) {
        if (A[i] == '0')
            sum += 1;
        else 
            sum -= 1;
        
        if (sum < 0) {
            sum = 0;
            start = i+1;
        }
        
        if (sum > finalsum) {
            finalsum = sum;
            res[0] = start;
            res[1] = end = i;
        }
    }
    
    if (res[0] != -1 && res[1] != -1) {
    	res[0] = res[0] + 1;
    	res[1] = res[1] + 1;
        *len1 = 2;
    } 
    
    return res;
}
