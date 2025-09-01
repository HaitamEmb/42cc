#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		slen;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	slen = (int)ft_strlen(s);
	if ((int)start >= slen)
		return (ft_strdup(""));
	if ((int)len > slen)
		len = slen;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = 0;
	return (substr);
}