#include "get_next_line_bonus.h"
#include "stdio.h"
#include "fcntl.h"
int main()
{
	int fd = open("text1.txt", O_RDWR | O_CREAT, 0777);
	write(fd,"mkati",5);
	close(fd);
	int fd2 = open("text1.txt", O_RDONLY);
	printf("%s",get_next_line(fd2));
	int fd3 = open("text2.txt", O_RDONLY);
	printf("%s",get_next_line(fd3));

}
