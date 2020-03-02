#include <stdio.h>



int main(int argc, const char* argv[]) {
	char* filename = argv[1];
	int floor = 0; 
	char ch;
	FILE *fp;

	fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("File not found: %s\n", filename);
		return 1;
	}

	while((ch = fgetc(fp)) != EOF) {
		if(ch == '(') {
			floor++;
		}
		else if(ch == ')') {
			floor--;
		}
	}
	fclose(fp);
	printf("%d\n", floor);
	return floor;
}
	       	       
