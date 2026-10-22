#include <stdio.h>
int main() {
    FILE *fp = fopen("a.bin", "wb+");
    int a[3] = {0, 1, 2}, ra[3]; char b[4] = "ABC", rb[4]; float c[3] = {1.1, 1.2, 1.3}, rc[3];
    fwrite(a, sizeof(int), 3, fp); fwrite(b, sizeof(char), 3, fp); fwrite(c, sizeof(float), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(ra, sizeof(int), 3, fp); fread(rb, sizeof(char), 3, fp); fread(rc, sizeof(float), 3, fp); rb[3] = '\0';
    fclose(fp);
    for(int i = 0; i < 3; i++) printf("%d ", ra[i]);
    printf("\n%s\n", rb);
    for(int i = 0; i < 3; i++) printf("%f ", rc[i]);
    return 0;
}
