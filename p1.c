/* find the two numbers that sum to 2020 and multiply them */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv) {
	char * line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	long long int * nums;
	long long int count;
	long long int i, j;

	if (argc != 1) {
		printf("pass input in on stdin, one entry per line\n");
		exit(0);
	}

count = 0;

while ((linelen = getline(&line, &linecap, stdin)) > 0)
{
//	printf("%lu: %d\n", strlen(line), atoi(line));
	if (strlen(line) < 2)
		continue;
	count++;
	nums = realloc(nums, count * sizeof(long long int));
	if (NULL == nums)
		exit(0);
	nums[count-1] = atoi(line);
}
	for (i = 0; i < count; i++) {
		for (j = i+1; j < count; j++) {
			if (2020 == nums[i] + nums[j]) { 
				printf("%lld\n", nums[i] * nums[j]);
				goto done;
			}
		}
	}
done:
	free(nums);
	return 0;
}
