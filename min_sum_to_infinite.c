/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
int coverPoints(int* X, int n1, int* Y, int n2) {
    int stepsx = 0, stepsy = 0, diffx = 0, diffy = 0, steps = 0;
    int i = 0;
    
    for(i = 0; i< (n1-1) ; i++)
    {
        diffx = X[i+1] - X[i];
        if(diffx < 0)
            diffx = diffx*(-1);
        //stepsx = stepsx + diffx;
        
        diffy = Y[i+1] - Y[i];
        if(diffy < 0)
            diffy = diffy*(-1);
        //stepsy = stepsy + diffy;
        
        if(diffx > diffy)
            steps = steps+diffx;
        else
            steps =  steps+diffy;
    }
    
    return steps;
}

