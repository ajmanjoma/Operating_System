#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

void createfile(){
	char f1[20],data[100];FILE * fp;int i;
	for(i=0;i<2;i++){
		printf("input file name: ");
		gets(f1);
		fp=fopen(f1,"w");
		if (fp==NULL){
			printf("file not created ");
			exit(EXIT_FAILURE);
		}
		printf("enter contents to be added: ");
		fgets(data,100,stdin);
		fputs(data,fp);
		fclose(fp);
		printf("file created successfully \n");
	}
	
}

void copyfile(){
	char s[20],t[20],ch;
	FILE *source,*target;
	printf("\nenter file to be copied: ");
	gets(s);
	source=fopen(s,"r");
	if(source==NULL){
		printf("file doesnt exist");
		exit(0);
	}
	printf("enter target file: ");
	gets(t);
	target=fopen(t,"w");
	if(target==NULL){
		fclose(source);
		printf("file doesn't exist");
		exit(0);
	}
	
	while((ch=fgetc(source))!=EOF){
		fputc(ch,target);
	}
	printf("file copied");
	fclose(source);
	fclose(target);
}

void ls(){
	char dir[20];
	printf("\nenter directory name: ");
	gets(dir);
	DIR *p=opendir(dir);
	struct dirent *d;
	if (p==NULL){
		printf("doesn't exist");
		exit(0);
	}
	while(d=readdir(p)){
		printf("%s \n",d->d_name);
	}	
}

void grep(){
	FILE * fp;int count=0;
	char ch,f1[20];
	printf("input file name: ");
	gets(f1);
	fp=fopen(f1,"r");
	if (fp==NULL){
		printf("file not created ");
		exit(EXIT_FAILURE);
	}
	for(ch=getc(fp);ch!=EOF;ch=getc(fp)){
		if(ch=='\n')count++;
	}
	fclose(fp);
	printf("%s has %d lines",f1,count);
}
void main(){
	createfile();
	copyfile();
	ls();
	grep();
}
