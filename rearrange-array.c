void arrange(int* A, int n1) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i;
    for(i=0; i<n1; i++) {
        A[i] += (A[A[i]]%n1)*n1;
    }
    for(i=0; i<n1; i++) {
        A[i]/=n1;
    }
}
