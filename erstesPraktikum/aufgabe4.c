#include <stdio.h>
#include <stdlib.h>

int aufgabe1 (){
	FILE *fp = fopen("helloWorld.txt", "w+");
		if (!fp) {
		perror("fopen");
		return EXIT_FAILURE;
	}
	char t[] = "Hello World";
	fwrite(t,(sizeof(t) - sizeof(t[0]))/ sizeof(t[0]), sizeof(t[0]), fp);
	return 0;
}

int aufgabe2 (){
	char t[] = "Hello World";
	FILE *fp = NULL;
	*fp = fopen("helloWorld.txt", "r");
	if(fp == NULL){
		*fp = fopen("helloWorld.txt", "w");
		fwrite(t,(sizeof(t) - sizeof(t[0]))/ sizeof(t[0]), sizeof(t[0]), fp);
	}

	int count = 0;
	char* str;
	sprintf(str,"helloworld%d.txt",count);
	printf("hello\n");
	while (1){
		while(fopen(str,"r") != NULL && count < 99){
			count ++;
			sprintf(str,"helloworld%d.txt",count);
		}
		fp = fopen(str, "w");
		fwrite(t,(sizeof(t) - sizeof(t[0]))/ sizeof(t[0]), sizeof(t[0]), fp);

		if(count >= 99){
			break;
		}
	}
	return 0;
	

}

int main(void)
{/*
	FILE *fp = fopen("/bin/sh", "rb");
	if (!fp) {
		perror("fopen");
		return EXIT_FAILURE;
	}
	
	unsigned char buffer[4];
	
	size_t ret =
	fread(buffer, sizeof(buffer) / sizeof(*buffer), sizeof(*buffer), fp);
	if (ret != sizeof(*buffer)) {
		fprintf(stderr, "fread() failed: %zu\n", ret);
		exit(EXIT_FAILURE);
	}
	
	printf("ELF magic: %#04x%02x%02x%02x\n", buffer[0], buffer[1],
	buffer[2], buffer[3]);
	
	ret = fread(buffer, 1, 1, fp);
	if (ret != 1) {
		fprintf(stderr, "fread() failed: %zu\n", ret);
		exit(EXIT_FAILURE);
	}
	
	printf("Class: %#04x\n", buffer[0]);
	
	fclose(fp);
	
	exit(EXIT_SUCCESS);*/

	
	aufgabe2();
	return 0;

}
	
	
