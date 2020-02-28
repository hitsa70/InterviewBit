/**
 A hotel manager has to process N advance bookings of rooms for the next season.
 His hotel has K rooms. Bookings contain an arrival date and a departure date. 
 He wants to find out whether there are enough rooms in the hotel to satisfy the demand. 
 Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room.  
 */
 
 
 
 
 
#define LEFT(i) ((2*i)+1)
#define RIGHT(i) ((2*i)+2)
#define PARENT(i) ((i-1)/2)
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int parent(int i)
{
	double x=(i/2.0);
	return (int)x;
}
void maxHeapify(int *a,int i,int size)
{
	int leftChild=LEFT(i);
	int rightChild=RIGHT(i);
	int largest;
	if(leftChild<=size-1 && a[leftChild]>a[i])
	{
		largest=leftChild;	
	}
	else
	{
		largest=i;
	}
	if(rightChild<=size-1 && a[rightChild]>a[largest])
	{
		largest=rightChild;
	}
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		maxHeapify(a,largest,size);
	}
}
void buildMaxHeap(int *a,int size)
{
	int lastIndex=size-1;
	lastIndex=parent(lastIndex);
	while(lastIndex>=0)
	{
		maxHeapify(a,lastIndex,size);
		lastIndex--;	
	}
}
void heapSort(int *a,int size)
{
	buildMaxHeap(a,size);
	int lastIndex=size-1;
	int heapsize=size;
	while(lastIndex>=1)
	{
		swap(&a[0],&a[lastIndex]);
		heapsize--;
		maxHeapify(a,0,heapsize);
		lastIndex--;
	}
}

int hotel(int* arrive, int n1, int* depart, int n2, int K) 
{
    heapSort(arrive,n1);
    heapSort(depart,n2);
    int maxTime=(arrive[n1-1]>depart[n2-1]?arrive[n1-1]:depart[n2-1]);
    int i,maxRooms=0,j=0,k=0;
    for(i=0;i<=maxTime;i++)
    {
        while(arrive[j]==i)
        {
            maxRooms++;
            j++;
        }
        while(depart[k]==i)
        {
            maxRooms--;
            k++;
        }
        if(maxRooms>K)
        {
            return 0;
        }
    }
    return 1;
}
