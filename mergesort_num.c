#include "basic.h"
#define TEST_DATA_CNT   1000000
int test_data2[TEST_DATA_CNT + 5];
int L[TEST_DATA_CNT], R[TEST_DATA_CNT]; //宣告兩個新陣列分別為左陣列跟右陣列，沒有內容值

void Merge(int arr[], int l, int m, int r)
{
    int L_size, R_size, i, j, k;
    L_size = m - l + 1; //+1 是因為一開始會有0-0的可能性
    R_size = r - m;

    for (i = 0; i < L_size; i++) { //把原陣列的值放進剛定義的L跟R陣列
        L[i] = arr[l + i];
    }
    for (j = 0; j < R_size; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l; //紀錄第一個
    while (i < L_size && j < R_size) { //當其中一個比較完就跳出這個陣列
        if (L[i] <= R[j]) { //比較小的放進arr[]
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < L_size) {
        arr[k++] = L[i++];
    }
    while (j < R_size) {
        arr[k++] = R[j++];
    }
}

void MergeSort(int arr[], int l, int r)
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

    for(i = 0; i < TEST_DATA_CNT ; i++) {
        test_data2[i] = rand();
    }
    struct timeval start;
    struct timeval end;

    unsigned long diff;
    int left=0;
    int right=TEST_DATA_CNT-1;

    gettimeofday(&start, NULL);
    MergeSort(test_data2, left, right);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     // 實際的時間差
    printf("Sorting numbers' performance of merge sort is %f sec\n", diff / 1000000.0);

    return 0;

}