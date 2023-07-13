#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdio.h>


char *get_next_line(int fd);
size_t ft_strlen(char *s);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int ft_strchr(char *s, int c);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif
