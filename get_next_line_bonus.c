#include "get_next_line.h"
char * ft_line(char **line , char *left)
{
    int i;
    char *tmp;

    i = 0;
    while(left && left[i] != '\n' && left[i] != '\0')
        i++;
    if (left && left[i] == '\0')
    {
        if (left[0] == '\0')
            *line = NULL;
        else
            *line = ft_strdup(left);
        free (left);
        left = NULL;
    }
    else
    {
        *line = ft_substr(left,0,i + 1);
        tmp = left;
        left = ft_substr(tmp,i + 1,ft_strlen(tmp) - i);
        free(tmp);
    }
    return (left);
}
char *get_next_line(int fd)
{
    static char *left[1024];
    char *buffer;
    char *tmp;
    char *line;
    int check;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(left[fd]) , left[fd] = NULL ,NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while(1)
    {
        check = read (fd, buffer,BUFFER_SIZE);
        if (check < 0)
            return(free (left[fd]),left[fd] = NULL,NULL);
        if (check == 0)
            break;
        if (!left[fd])
            left[fd] = ft_strdup("");
        buffer[check] = '\0';
        tmp = left[fd];
        left[fd] = ft_strjoin(tmp ,buffer);
        free(tmp);
        if (ft_strchr(left[fd],'\n') != NULL)
            break;
    }
    free (buffer);
    left[fd] = ft_line(&line,left[fd]);
    return (line);
}
