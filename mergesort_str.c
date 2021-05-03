#include "basic.h"
#define TEST_DATA_CNT   1000000
char test_data5[TEST_DATA_CNT + 5][101];
char L[TEST_DATA_CNT][101], R[TEST_DATA_CNT][101]; //宣告兩個新陣列分別為左陣列跟右陣列，沒有內容值

void Merge(char arr[][101], int l, int m, int r)
{
    int L_size, R_size, i, j, k;
    L_size = m - l + 1; //+1 是因為一開始會有0-0的可能性
    R_size = r - m;

    for (i = 0; i < L_size; i++) { //把原陣列的值放進剛定義的L跟R陣列
        //L[i] = arr[l + i];
        strcpy(L[i], arr[l+i]);
    }
    for (j = 0; j < R_size; j++) {
        //R[j] = arr[m + 1 + j];
        strcpy(R[j], arr[m+1+j]);
    }
    i = 0;
    j = 0;
    k = l; //紀錄第一個
    while (i < L_size && j < R_size) { //當其中一個比較完就跳出這個陣列
        if (strcmp(L[i], R[j])<=0) { //比較小的放進arr[],L[i] <= R[j]
            //arr[k] = L[i];
            strcpy(arr[k], L[i]);
            i++;
        } else {
            //arr[k] = R[j];
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < L_size) {
        //arr[k++] = L[i++];
        strcpy(arr[k], L[i]);
        k++; i++;
    }
    while (j < R_size) {
        //arr[k++] = R[j++];
        strcpy(arr[k], R[j]);
        k++; j++;
    }
}

void MergeSort(char arr[][101], int l, int r)
{
    if (l < r) {
        int mid = (l + r - 1) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    int i;


    srand(1);

    for(i = 0; i < TEST_DATA_CNT ; i++){
        for(int j=0; j<100; j++){
            int UorL=rand()%2;
            if(UorL==0) test_data5[i][j]=rand()%26+'a';
            else if(UorL==1) test_data5[i][j]=rand()%26+'A';
        }
        test_data5[i][100]='\0';
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start, NULL);
    MergeSort(test_data5, 0, TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting strings' performance of merge sort is %f sec\n", diff / 1000000.0);

    return 0;

}