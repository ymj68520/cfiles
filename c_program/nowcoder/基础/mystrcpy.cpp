//?????
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
void my_strcpy(char * destination,char * source)
{
	int i,len=0,len1;
	for(i=0;destination[i]!=' ';i++)
	{
		len++;
	}
	destination[len+1]=NULL;
	len1=strlen(source);
	//if(len>len1)
	//{
		for(i=len+1;i<len1;i++)
		{
			destination[i]=source[i];
		}
	//}
	puts(destination);
	
}
int main()
{
	char des[80], src[80];
	int i;
	fgets(des,10,stdin);
	fgets(src,10,stdin);
	my_strcpy(des,src);
	return 0;
}
