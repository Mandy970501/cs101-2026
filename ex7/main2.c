#include <stdio.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

// 計算所有書籍的總價
void total_price(book_t books[], int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++) {
        total += books[i].price;
    }

    printf("所有書籍總價：%d\n", total);
}

// 輸出所有書籍資料
void list_books(book_t books[], int n)
{
    int i;

    printf("\n書籍資料：\n");
    printf("ID\tPrice\tTitle\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n",
               books[i].id,
               books[i].price,
               books[i].title);
    }
}

int main()
{
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    FILE *fp;
    int n = 6;

    // 呼叫函式計算總價
    total_price(books, n);

    // 呼叫函式輸出書籍資料
    list_books(books, n);

    // 建立二進位檔案
    fp = fopen("Book.bin", "wb");

    if (fp == NULL) {
        printf("檔案開啟失敗\n");
        return 1;
    }

    // 將書籍結構寫入檔案
    fwrite(books, sizeof(book_t), n, fp);

    fclose(fp);

    printf("\n書籍資料已儲存至 Book.bin\n");

    return 0;
}
