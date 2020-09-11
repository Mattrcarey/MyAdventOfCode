//read file line by line
//split lines by 'x' (l,w,h)
//convert to int
//surface area = 2*l*w + 2*w*h + 2*h*l
//Extra area = min(l,w,h)

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
	return (x < y) ? x : y;
}

int main(void) {
	FILE *fp = fopen("input.txt", "r");
	if(fp == NULL) {
		perror("File not found");
       		exit(1);
	}	

	int l;
	int w;
	int h;
	int sum = 0;
	while(EOF != fscanf(fp, "%dx%dx%d\n", &l, &w, &h)) {
		sum += 2*l*w + 2*w*h + 2*h*l + min((l*w), min((w*h),(h*l)));
	}
	printf("%d\n", sum);
}
