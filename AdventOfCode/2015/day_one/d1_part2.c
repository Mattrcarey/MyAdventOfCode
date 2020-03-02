#include <stdio.h>



int main(int argc, const char* argv[]) {
	char* filename = argv[1];
	int floor = 0;
	int counter = 1;
	char ch;
	FILE *fp;

	fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("File not found: %s\n",filename);
		return 1;
	}

	while((ch = fgetc(fp))!= EOF) {
		if(ch == '(') {
			floor++;
			counter++;
		}
		else if(ch == ')') {
			floor--;
			if(floor == -1){
				printf("%d\n", counter);
				return counter;
			}
			counter++;
		}
	}
	fclose(fp);
	printf("%d\n", floor);
	return floor;
}
