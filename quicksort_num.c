#include "basic.h"
#define SWAP1(x,y) {int t; t = x; x = y; y = t;}
#define TEST_DATA_CNT   1000000
int test_data1[TEST_DATA_CNT + 5];

int partition(int number[], int left, int right) { 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(number[j] <= number[right]) { 
            i++; 
            SWAP1(number[i], number[j]); 
        } 
    } 

    SWAP1(number[i+1], number[right]); 
    return i+1; 
} 

void quickSort(int number[], int left, int right) { 
    if(left < right) {
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
}

int main()
{
    int i;


    srand(1);

    for(i = 0; i < TEST_DATA_CNT ; i++){
        test_data1[i] = rand();
        //printf("%d\n", test_data[i]);
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start, NULL);
    quickSort(test_data1, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    /*for(i = 0; i < 10; i++){
        printf("%d\n", test_data[i]);
    }
    */
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting numbers' performance of quick sort is %f sec\n", diff / 1000000.0);

    return 0;

}