#include <stdio.h>

int main(){
    FILE *fp;

    int a_write[3]={0,1,2};
    int a_read[3];

    char b_write[3]={'A','B','C'};
    char b_read[4];

    float c_write[3]={1.1,1.2,1.3};
    float c_read[3];

    fp=fopen("a.bin","wb+");

    if(fp==NULL){
        printf("File open failed\n");
        return 1;
    }

    fwrite(a_write,sizeof(int),3,fp);
    fwrite(b_write,sizeof(char),3,fp);
    fwrite(c_write,sizeof(float),3,fp);

    rewind(fp);

    fread(a_read,sizeof(int),3,fp);
    fread(b_read,sizeof(char),3,fp);
    fread(c_read,sizeof(float),3,fp);

    for(int i=0;i<3;i++){
        printf("%d ",a_read[i]);
    }
    printf("\n");

    for(int i=0;i<3;i++){
        printf("%c ",b_read[i]);
    }
    printf("\n");

    for(int i=0;i<3;i++){
        printf("%f ",c_read[i]);
    }
    printf("\n");

    fclose(fp);

    return 0;
}
