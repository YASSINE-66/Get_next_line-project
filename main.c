#include "get_next_line.h"
int main()
{
    int fd1;
//    int fd;
    int i;
    //fd = open("text", O_RDONLY,0777);
    fd1 = open("te", O_CREAT | O_RDONLY,0777);
    i = 0;
    char *str;
 while((str =get_next_line(fd1)) != NULL)
 {
    printf ("%s",str);
    free(str);
    str = get_next_line(fd1);
    printf ("%s",str);
    free(str);
    i++;
}
}
