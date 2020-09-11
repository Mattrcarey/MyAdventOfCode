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
                sum += l*w*h + min( (2*l+2*w), min((2*l+2*h), (2*w+2*h)));
        }
        printf("%d\n", sum);
}

