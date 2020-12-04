/* advent of code 2020 day 2 - password policy */
/* by Matt Balaun */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv) {
	char * line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	int valids = 0;
	int p2valids = 0;
	int i = 0;
	int low = 0;
	char lowfound;
	int high = 0;
	char highfound;
	char match;
	char matchfound = 0;
	int count = 0;

	if (argc != 1) {
		printf("pass input in on stdin, one entry per line\n");
		exit(0);
	}


while ((linelen = getline(&line, &linecap, stdin)) > 0)
{
	char tmpstr[2] = "\n\n"; 
	low = high = count = 0;
	lowfound = 0;
	highfound = 0;
	matchfound = 0;
	i = 0;
	match = 0;

	if (strlen(line) < 8)
		continue;
	
	while (i < strlen(line)) {
		if (!(lowfound)) {
			if (('0' <= line[i]) && ('9' >= line[i])) {
				low *= 10;
				tmpstr[0] = line[i];
				low += atoi(tmpstr);
			} else {
				if ('-' == line[i]) {
					lowfound = 1;
				} else {
					printf("oops!\n");
					exit(1); 
				}
			}
		} else {
			if (!(highfound)) {
				if (('0' <= line[i]) && ('9' >= line[i])) {
					high = high * 10;
					tmpstr[0] = line[i];
					high += atoi(tmpstr);
				} else {
					if (' ' == line[i]) {

						highfound = 1;
					} else {
						printf("oops!\n");
						exit(1);
					}
				}
			} else {
				if (!(matchfound)) {
					if (':' != line[i]) {
						match = line[i];
					} else {
						matchfound = 1;
						i++;
					}
				} else {
					if ((strlen(line) > (i + low)) &&
					(strlen(line) > (i + high))) {
						printf("matching %c to %c, %c\n", match, line[i+low-1], line[i+high-1]);
						if (line[i + low-1] == match)
							if (line[i+high-1] != match)
								p2valids++;
						if (line[i+high-1] == match)
							if (line[i+low-1] != match)
								p2valids++;
					}
					while (i < strlen(line)) {
						if (match == line[i])
							count++;
						i++;
					}
					if ((count >= low) && (count <= high))
						valids++;
				}
			}
		}
	i++;
	}
	
}
	printf("%d\n", valids);
	printf("%d\n", p2valids);
	return 0;
}
