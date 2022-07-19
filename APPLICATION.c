#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	char temp[512];
	char *p;
	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((p=strstr(temp, str)) != NULL) {
		     for(int i=5;*(p+i)!='\'';i++)
		     {
		         printf("%c",*(p+i));
             }
             printf("\n");
		}
	}
	if(fp) {
		fclose(fp);
	}
   	return(0);
}
int main(int argc, char** argv)
{
    char filename[200]="gcc -ffunction-sections -Wl,--gc-sections,--print-gc-sections ";
    strcat(filename,argv[1]);
    strcat(filename," 2> out.txt");
    const char *command = filename;
    FILE *fptr;
    fptr=fopen("out.txt","w+");
    system(command );
    printf("The Unused functions in the project are:\n");
    Search_in_File("out.txt","text.");
    return 0;
}
