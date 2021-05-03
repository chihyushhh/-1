#include "basic.h"
#define TEST_DATA_CNT   1000000
int test_data3[TEST_DATA_CNT + 5];
int temp[10][TEST_DATA_CNT] = {0};
int order[TEST_DATA_CNT] = {0};

int getMax(int array[], int n) {
int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void radixSort(int data[]) {
    int max = getMax(data, TEST_DATA_CNT);
    int n = 1; 
    while(n <= max) { 
        
        int i;
        for(i = 0; i < TEST_DATA_CNT; i++) { 
            int lsd = ((data[i] / n) % 10); 
            temp[lsd][order[lsd]] = data[i]; 
            order[lsd]++; 
        } 
        
        int k = 0;
        for(i = 0; i < TEST_DATA_CNT; i++) { 
            if(order[i] != 0)  {
                int j;
                for(j = 0; j < order[i]; j++, k++) { 
                    data[k] = temp[i][j]; 
                } 
            }
            order[i] = 0; 
        } 

        n *= 10; 
    }     
}

int main()
{
    int i;

    srand(1);

    for(i = 0; i < TEST_DATA_CNT ; i++) {
        test_data3[i] = rand();
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start, NULL);
    radixSort(test_data3);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting numbers' performance of radix sort is %f sec\n", diff / 1000000.0);

    return 0;

}