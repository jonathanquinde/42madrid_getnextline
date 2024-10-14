#include "get_next_line.h"

int main(void)
{
    int fd;

    fd = open("hola.txt", O_RDONLY);
	for (size_t i = 0; i < 4; i++)
	{
		printf("%s\n", get_next_line(fd));
		printf("-------------");
	}	
}