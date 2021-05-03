#include <stdio.h>
#include <stdlib.h>
int test_data1[1000005];
char test_data4[1000000][101];
int main(){
FILE *fp=fopen("dataset1.txt", "w");
    srand(1);
    for(int i = 0; i < 1000000 ; i++){
        test_data1[i] = rand();
        fprintf(fp, "%d\n", test_data1[i]);
    }
    fclose(fp);
    
    fp=fopen("dataset2.txt", "w");
    for(int i = 0; i < 1000000 ; i++){
        for(int j=0; j<100; j++){
            int UorL=rand()%2;
            if(UorL==0) test_data4[i][j]=rand()%26+'a';
            else if(UorL==1) test_data4[i][j]=rand()%26+'A';
        }
        test_data4[i][100]='\0';
        fprintf(fp, "%s\n", test_data4[i]);
    }
    fclose(fp);
}