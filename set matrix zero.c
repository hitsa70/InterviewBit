
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.








void setZeroes(int** A, int n11, int n12) {
      int i, j;
    int *r, *c;
    
    r = calloc(n11, sizeof (int));
    c = calloc(n12, sizeof (int));
    
    for (i = 0; i < n11; i++) {
        for (j = 0; j < n12; j++) {
            if (A[i][j] == 0) {
                r[i] = 1;
                break;
            }
        }
    }

    for (j = 0; j < n12; j++) {
        for (i = 0; i < n11; i++) {
            if (A[i][j] == 0) {
                c[j] = 1;
                break;
            }
        }
    }

    for (i = 0; i < n11; i++) {
        for (j = 0; j < n12; j++) {
            if (r[i] == 1 || c[j] == 1) {
                A[i][j] = 0;
            }
        }
    }
    
    free(r);
    free(c);
}

