#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"
int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
//boyutunu önceden bilmeden bir file descriptor’dan yeni satır karakteri
//('\n') ile biten bir satırı okumayı sağlayan bir işlev oluşturmak

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	j = -1;
	while (*(s2 + ++j))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	free(s1);//s2 malloclanmadığından free yok
	return (str);
}