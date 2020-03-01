/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/

int maximumGap(const int* A, int n1) {
    int lmin[n1], 
    rmax[n1], 
    i, j,
    max = -1;
    
    for(i=0; i<n1; i++){ lmin[i] = (i==0 || A[i]<lmin[i-1])? A[i] : lmin[i-1]; }
    for(i=n1-1; i>=0; i--){ rmax[i] = (i==n1-1 || A[i]>rmax[i+1])? A[i] : rmax[i+1];}
    for(i=0, j=0; i<n1 && j<n1; ){
        if(A[i]<=rmax[j]){
            if(j-i > max) max = j - i;
            j++;
        }else{
            i++;
        }
    }
    return max;
}
