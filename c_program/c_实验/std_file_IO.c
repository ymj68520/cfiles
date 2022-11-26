//FILE * fopen(char* fp,"string");
//srting:"r" "w" "a" "r+" "w+" "a+"
//       "rb" "wb" "ab" "rb+" "r+b" "wb+" "w+b" "ab+" "a+b"
//       "wx" "wbx" "w+x" "wb+x" "w+bx"
//char getc(FILE *fp);  //ch = getc(fp);
//void putc(char ch, FILE *fp);  //putc(ch, fpout);
//int fclose(FILE *fp); success=0 fallure=EOF
//fprintf(FILE *fp,"%*",element...);
//int fscanf(FILE *fp,"%*",&*);
//void rewind(FILE *fp);goto begin of the file
//int fseek(FILE *fp,offset,mode);offset(long),+,-,0;mode:SEEK_SET
//                                               SEEK_CUR,SEEK_END
//long ftell(FILE *fp);long is the location of file now

//int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
//调用时，fpos_t类型的值放在pos指向的位置上，该值描述了文件当前位置距文件
//开头的字节数。如果成功返回0，失败返回非0；

//int fsetpos(FILE *stream, const fpos_t *pos);
//使用pos位置上的fpos_t类型值来设置文件指针指向偏移该值后指定的位置。
//如果成功返回0 否则非0 且fpos_t类型的值应通过之前调用fgetpos()获得

//int ungetc(int c, FILE *fp);把一个字符放回输入流
//ungte(ch, stdin);

//int fflush(FILE *fp);调用该函数将引起输出缓冲区中所有未写入数据发送到
//fp指定的输出文件——刷新缓冲区。若fp为空指针，所有输出缓冲区都被刷新。在
//输入流中使用fflush()函数效果是未定义。只要最近一次操作不是输入操作就可
//以使用该函数来刷新缓冲区来更新流(任何读写模式)

//int setvbuf(FILE * restrict fp, char * restrict buf, int mode,
//            size_t size);
//创建一个供标准I/O函数替换使用的缓冲区。在打开文件后且未对流进行其他操作
//之前，调用该函数。指针fp识别待处理的流，buf指向待使用的存储区。若buf的
//值不是NULL,则必修创建一个缓冲区。size告诉函数数组的大小。mode的选择如下
//_IOFBF(完全缓冲) _IOLBF(行缓存) _IONBF(无缓冲) 操作成功返回0否则非0

//size_t fwrite(const void * restrict ptr,size_t size, size_t nmemb,
//              FILE * restrict fp);
//把二进制数据写入文件；size_t 可以选用其他类型；ptr是待写入数据块的地址
//size 表示待写入数据块的大小（字节为单位）；nmemb 表示待写入数据块的数
//数量；fp指定待写入的文件。返回成功读取项的数量，正常情况是nmemb。
// char buffer[256];    fwrite(buffer, 256, 1, fp);  

//size_t fread(void * restrict ptr, size_t size, size_t nmemb,
//             FILE * restrict fp);
//基本同fwrite(), ptr是待读取文件数据在内存中的地址，fp指定待读取的文件。
//该函数用于读取被fwrite（）写入文件的数据。
//示例
//double earnings[10];
//fwrite(earnings, sizeof(double), 10, fp);//将数组分10块写入文件
//fread(earnings, sizeof(double), 10, fp);//将10个double类型拷贝入数组

//int feof(FILE *fp);        int ferror(FILE *fp);
//读取错误亦会返回EOF，到文件结尾feof返回一个非零值，读写错误ferror返回
//非零值，否则都返回0；

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char * s_gets(char *st, int n);

int main (void){
    FILE *fa,*fs;  //fa 指向目标文件 fs 指向源文件
    int files = 0;  //附加的文件数量
    char file_app[SLEN];  //目标文件名
    char file_src[SLEN];    //源文件名
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if((fa = fopen(file_app,"a+")) == NULL){
        fprintf(stderr,"Can`t open %s\n",file_app);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
        fputs("Can`t creat output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    while(s_gets(file_src, SLEN) && file_src[0]!='\0'){
        if (strcmp(file_src, file_app)==0)
            fputs("Can`t append file to itself\n",stderr);
        else if((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr,"Can`t open %s\n",file_src);
        else{
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
                fputs("Can`t creat input buffer\n",stderr);
                continue;
            }
            append(fs, fa);
            if(ferror(fs) != 0)
                fprintf(stderr,"Error in reading file %s.\n",file_src);
            fclose(fs);
            files++;
            printf("File %s appended.\n",file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n",files);
    rewind(fa);
    printf("%s contents:\n",file_app);
    while((ch = getc(fa))!=EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append (FILE *source, FILE *dest){
    size_t bytes;
    static char temp[BUFSIZE];

    while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) >0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char * st, int n ){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}

//随机访问程序示例
/*
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main (){
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    //创建一组double类型的值
    for (i = 0; i< ARSIZE;i++)
        numbers[i] = 100.0 * i + 1.0 / (i+1);
    //尝试打开文件
    if((iofile = fopen(file,"wb"))==NULL){
        fprintf(stderr,"Could not open %s for output.\n",file);
        exit(EXIT_FAILURE);
    }
    //以二进制格式把数组写入文件
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if((iofile = fopen(file,"rb")) == NULL){
        fprintf(stderr,
                "Coule not open %s for random access.\n",file);
        exit(EXIT_FAILURE);
    }
    //从文件中读取选定的内容
    printf("Enter an index in the range 0-%d.\n",ARSIZE-1);
    while(scanf("%d",&i)==1 && i>=0 && i< ARSIZE){
        pos = (long) i*sizeof(double);      //计算偏移量
        fseek(iofile,pos,SEEK_SET);         //定位到此
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n",value);
        printf("Next index (out of range to quit):\n");
    }
    //完成
    fclose(iofile);
    puts("Bye!");

    return 0;
}
*/
