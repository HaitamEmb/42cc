#include "libft.h"

static int   ft_wordcount(char const *s, char c)
{
  int   i;
  int count;
  int word;
  
  i = 0;
  word = 0;
  count = 0;

  while(s[i])
  {
    if(s[i] != c && word == 0) 
    {
      count++;
      word = 1;
    }
    else if (s[i] == c) 
    {
      word = 0;
    }
    i++;
  }
  return (count);
}
static char	*ft_cpywrd(const char *str, int start, int end)
{
	char	*rtn;
	int		i;

	rtn = (char *)malloc(sizeof(char) * ((end - start) + 1));
	i = 0;
	while (start < end)
		rtn[i++] = str[start++];
	rtn[i] = 0;
	return (rtn);
}
static int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char  **ft_split(char const *s, char c)
{
  char  **dest;
  int   i;
  int   len;
  int   start;
  int   j;

  if (!s)
    return (NULL);
  len = ft_len(s);
  dest = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
  if (!dest)
    return NULL;
  start = -1;
  i = -1;
  j = 0;
  while(++i <= len)
  {
    if(s[i] != c && start < 0)
      start = i;
    else if (start >= 0 && (s[i] == c || i == len))
    {
      dest[j++] = ft_cpywrd(s, start, i);
      start = -1;
    }
  }
  dest[j] = 0;
  return (dest);
}

/*int	main(void)
{
	char str[] = "  hello world whats up";
	char **str1;
	s1 = ft_split(str,' ');
	while(*str1)
	{
		printf("%s\n",*str1++);
	}
}*/
