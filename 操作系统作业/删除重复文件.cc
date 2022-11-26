#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <set>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
using namespace std;
set<char *> md5sun_set;

void listDir(char *path){
    DIR              *pDir ;
    struct dirent    *ent  ;
    int               i=0  ;
    char              childpath[512];
    
    pDir=opendir(path);
    memset(childpath,0,sizeof(childpath));
    while((ent=readdir(pDir))!=NULL){
        if(ent->d_type & DT_DIR){
            if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)
                continue;
            sprintf(childpath,"%s/%s",path,ent->d_name);
            printf("path:%s/",childpath);
            listDir(childpath);
        }else{
            string cmd = "md5sum ";
            cmd = cmd + path + "/" + ent->d_name + " >> /tttempttt";
            char tcmd[512];
            for(int i=0;i<cmd.length();i++) tcmd[i] = cmd[i];
            if(0==system(tcmd)){ 
                cout << "system exec fail!";
                // exit(EXIT_FAILURE);
            }
            int md5sum_file;
            FILE *logfile = fopen("./logfile","w+");
            if((md5sum_file = open("/tttempttt", O_CREAT))==-1)   cout << "open error";
            char md5sum_q[33];
            if(read(md5sum_file,md5sum_q,32))   cout << "read faild";
            if(md5sun_set.count(md5sum_q)){
                // 重复删除
                char delpath[128];
                delpath[0]='r';delpath[1]='m';delpath[2]=' ';
                int j=3;
                int k=0;
                for(;path[k]!='\0'&&j<128;k++) delpath[j++] = path[k];
                int l=0;
                for(;ent->d_name[l]!='\0'&&j<128;l++)  delpath[j++] = ent->d_name[l];
                if(!system(delpath)){ cout << "del fail!"; exit(EXIT_FAILURE);}
            }else{
                md5sun_set.insert(md5sum_q);
                fprintf(logfile,"%s/%s: %s\n",path,ent->d_name,md5sum_q);
            }
            close(md5sum_file);
            system("rm /tttempttt");
            fclose(logfile);
        }
        
    }
}

int main(int argc, char** argv){
    if(argc == 1)   return -1;
    listDir(argv[1]);
    return 0;
}