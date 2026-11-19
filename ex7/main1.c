#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k, temp;
    int num[7];
    FILE *fp;

    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");

    do {
        printf("請問您要買幾組樂透彩：");
        scanf("%d", &n);
    } while (n < 1 || n > 5);

    fp = fopen("lotto.txt", "w");

    if (fp == NULL) {
        printf("檔案開啟失敗\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s", asctime(t));

    for (i = 0; i < 5; i++) {
        fprintf(fp, "[%d]: ", i + 1);

        if (i < n) {

            // 產生7個不重複的數字
            for (j = 0; j < 7; j++) {
                int repeat;

                do {
                    repeat = 0;
                    num[j] = rand() % 69 + 1;

                    for (k = 0; k < j; k++) {
                        if (num[j] == num[k]) {
                            repeat = 1;
                            break;
                        }
                    }
                } while (repeat == 1);
            }

            // 將前6個數字由小到大排序
            for (j = 0; j < 5; j++) {
                for (k = j + 1; k < 6; k++) {
                    if (num[j] > num[k]) {
                        temp = num[j];
                        num[j] = num[k];
                        num[k] = temp;
                    }
                }
            }

            // 輸出7個號碼
            for (j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", num[j]);
            }

        } else {
            for (j = 0; j < 7; j++) {
                fprintf(fp, "-- ");
            }
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");

    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
