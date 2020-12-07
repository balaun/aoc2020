/* Advent of Code 2020 - Day 3 (map traversal) */
/* by Matt Balaun (balaun@gmail.com) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define XMAX 100
#define YMAX 1000

int main(int argc, char ** argv) {
	FILE * input;
	char buf[YMAX][XMAX];
	char * line;
	size_t len = 0;
	ssize_t nread = 0;
	int i = 0;
	int xpos = 0;
	int ypos = 0;
	int xstep = 3;
	int ystep = 1;
	int count31 = 0;
	int xp31 = 0;
	int count11 = 0;
	int xp11 = 0;
	int count51 = 0;
	int xp51 = 0;
	int count71 = 0;
	int xp71 = 0;
	int count12 = 0;
	int xp12 = 0;
	int wraplen = 11;
	unsigned long long int counttotal;

	input = fopen("day3input", "r");
	if (NULL == input)
		exit(1);
	
	while ((nread = getline(&line, &len, input)) != -1) {
		printf("buf[%d] set to: %s\n", i, line);
		fflush(stdout);
		strncpy(buf[i], line, XMAX);
		i++;
	}
	for (ypos = 0; ypos <= i;) {
		ypos += ystep;
		xpos += xstep;
		if (xpos >= wraplen)
			xpos -= wraplen;
		if (buf[ypos][xpos] == '#') {
			count31++;
		}

		if (0 == ypos % 2) {
			xp12 += 1;
			if (xp12 >= wraplen)
				xp12 -= wraplen;
			if (buf[ypos][xp12] == '#')
				count12++;
		}
		xp11 += 1;
		xp51 += 5;
		xp71 += 7;
		if (xp11 >= wraplen)
			xp11 -= wraplen;
		if (xp51 >= wraplen)
			xp51 -= wraplen;
		if (xp71 >= wraplen)
			xp71 -= wraplen;
		if (buf[ypos][xp11] == '#')
			count11++;
		if (buf[ypos][xp71] == '#')
			count71++;
		if (buf[ypos][xp51] == '#')
			count51++;

	}
	/*count71 = 0;
	xp71 = 0;
	for (ypos = 0; ypos < i;) {
		ypos += 1;
		xp71 += 7;
		if (xp71 >= wraplen)
			xp71 -= wraplen;
		if (buf[ypos][xp71] == '#') {
			printf("buf[%d][%d] == '#'\n", ypos, xp71);
			count71++;
		}
	}*/
	printf("%d\n", count31);
	printf("11 %d, 31 %d, 51 %d, 71 %d, 12 %d\n", count11, count31, count51, count71, count12);
	counttotal = count11 * count31 * count51 * count71 * count12;
	printf("%llu\n", counttotal);

	fclose(input);
	return 0;
}
