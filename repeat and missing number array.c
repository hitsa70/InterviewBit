/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* repeatedNumber(const int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        
        *length_of_array = 2; // length of result array
        int *result = (int *) malloc(*length_of_array * sizeof(int));
        long long int diff = 0;
        long long int sq_sum = 0;
        int i;    
        for(i = 0; i < n1; i++){
            diff += (long long int)A[i] - (long long int)i-1;
            sq_sum += (long long int)A[i]*(long long int)A[i] - ((long long int)i+1)*((long long int)i+1);
        }
        long long int sum = (long long int)(sq_sum/diff);
        result[0] = (int)((sum + diff)/2);
        result[1] = (int)((sum - diff)/2);
        return result;
        
}

