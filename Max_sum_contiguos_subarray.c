/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxSubArray(const int* A, int n1) {
    int s[n1];
    s[0] = A[0];
    
    int i, max = A[0];
    for(i = 1; i < n1; i++){
        if(s[i-1] < 0){
            s[i] = A[i];
        }
        else{
            s[i] = A[i] + s[i-1];
        }
        if(max < s[i]){
            max = s[i];
        }
    }
    return max;
}

