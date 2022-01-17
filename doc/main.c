#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(void)
{
	char *line;
	int fd;
	int r;
	
	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		write(1, "open fd error", 13);
		return (1);
	}
	while ((r = get_next_line(0, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	//system("leaks a.out");
	return (0);

}




/* BONUS MAIN */

// int main(void)
// {

// 	char *line;
// 	int fd;
// 	int fd2;

// 	line = 0;
// 	fd = open("test", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		write(1, "open fd error", 13);
// 		return (1);
// 	}
// 	fd2 = open("test2", O_RDONLY);
// 	if (fd2 == -1)
// 	{
// 		write(1, "open fd2 error", 14);
// 		return (1);
// 	}
// 	int i = 0;
// 	while (i++ < 25)
// 	{
// 		line = NULL;
// 		printf("[RV:%d] | ", get_next_line(fd, &line));
// 		printf("%-55s", line);
// 		printf(" | [FD1 - L%d]\n", i); 
// 		if (line)
// 			free(line);
// 		line = NULL;
// 		printf("[RV:%d] | ", get_next_line(1029330, &line));
// 		printf("%-55s", line);
// 		printf(" | [FD2 - L%d]\n", i); 
// 		if (line)
// 			free(line);
// 	}
	
// 	//system("leaks a.out");
// 	return (0);
// }