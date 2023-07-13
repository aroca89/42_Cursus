
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
 int    main(void)
 {
    int fd;
    char *str;
    size_t  i;
    // open the file
    i = 1;
    fd = open("read.txt", O_RDONLY);
		str = get_next_line(fd);
    while (str)
    {
	//	printf("%zu: [%s]", i, str);
		free(str);
        str = get_next_line(fd);
        i++;
    }
    printf("%zu: %s\n", i, str);
    // close after using
    close(fd);
	free(str);
//	system("leaks a.out");
    return (0);

 }
