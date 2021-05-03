#include "basic.h"
#define TEST_DATA_CNT   1000000
char test_data6[TEST_DATA_CNT + 5][101];
char *temp[53][TEST_DATA_CNT] = {0};
int order[53] = {0};

void radixSort(char data[][101]) {
    
    int n = 99; 
    while(n <= 99 && n>=0) {
        int i;
        for(i = 0; i < TEST_DATA_CNT; i++) {
            int lsd;
            if(isupper(data[i][n])) {
                lsd = data[i][n] - 'A'+1;
                temp[lsd][order[lsd]]=strdup(data[i]);
                order[lsd]++;
            }
            else {
                lsd = data[i][n] - 'a'+27;
                temp[lsd][order[lsd]]=strdup(data[i]);
                order[lsd]++;
            }
        }
        
        int k = 0;
        for(i = 1; i <= 52; i++) { 
            if(order[i] != 0)  {
                int j;
                for(j = 0; j < order[i]; j++, k++) { 
                    strcpy(test_data6[k],temp[i][j]);
                    free(temp[i][j]);
                } 
            }
            order[i] = 0; 
        } 

        n--; 
    }     
}

int main()
{
    int i;

    srand(1);

    for(i = 0; i < TEST_DATA_CNT ; i++){
        for(int j=0; j<100; j++){
            int UorL=rand()%2;
            if(UorL==0) test_data6[i][j]=rand()%26+'a';
            else if(UorL==1) test_data6[i][j]=rand()%26+'A';
        }
        test_data6[i][100]='\0';
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start, NULL);
    radixSort(test_data6);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting strings' performance of radix sort is %f sec\n", diff / 1000000.0);

    return 0;

}