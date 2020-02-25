/**
*You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
*
*If so, return the integer. If not, return -1.
*
*If there are multiple solutions, return any one.
*
*Example :
*
*Input : [1 2 3 1 1]
*Output : 1 
*1 occurs 3 times which is more than 5/3 times.
*/



int repeatedNumber(const int* A, int n1) {
    int i;
    int temp1 = -999;
    int temp2 = -999;
    int count1 = 0;
    int count2 = 0;
    int counter = 0;
    for(i = 0 ; i < n1 ; i++) {
        if(temp1 == A[i]) {
            count1++;
        }
        else if(temp2 == A[i]) {
            count2++;
        }
        else if(count1 == 0) {
            count1 = 1;
            temp1 = A[i];
        }
        else if(count2 == 0) {
            count2 = 1;
            temp2 = A[i];
        }
        else if(temp1 == A[i]) {
            count1++;
        }
        else if(temp2 == A[i]) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }
    if(count1 != 0) {
        for(i = 0 ; i < n1 ; i++) {
            if(A[i] == temp1) {
                counter++;
            }
        }
        if(counter > n1/3) {
            return temp1;
        }
    }
    counter = 0;
    if(count2 != 0) {
        for(i = 0 ; i < n1 ; i++) {
            if(A[i] == temp2) {
                counter++;
            }
        }
        if(counter > n1/3) {
            return temp2;
        }
    }
    return -1;
}
