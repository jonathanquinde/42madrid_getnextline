#include "get_next_line.h"

int main(void)
{
    int fd;
	char	*line;

    fd = open("hola.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		//printf("Line: ");
		//print_decima(line);
		//printf("\n");
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
}
