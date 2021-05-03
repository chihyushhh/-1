#include "basic.h"
#define TEST_DATA_CNT   1000000
char test_data4[TEST_DATA_CNT + 5][101];

void    SWAP2(char *a, char *b) {
    for(int i=0; i<100; i++){
        char tmp=*(a+i);
        *(a+i)=*(b+i);
        *(b+i)=tmp;
    }
}

int partition(char number[][101], int left, int right) { 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(strcmp(number[j],number[right])<=0) { //j<=right
            i++;
            SWAP2(number[i], number[j]);
        } 
    } 

    SWAP2(number[i+1], number[right]); 
    return i+1; 
} 

void quickSort(char number[][101], int left, int right) {
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
        for(int j=0; j<100; j++){
            int UorL=rand()%2;
            if(UorL==0) test_data4[i][j]=rand()%26+'a';
            else if(UorL==1) test_data4[i][j]=rand()%26+'A';
        }
        test_data4[i][100]='\0';
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start, NULL);
    quickSort(test_data4, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting strings' performance of quick sort is %f sec\n", diff / 1000000.0);

    return 0;

}