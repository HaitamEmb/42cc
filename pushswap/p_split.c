#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//count words
int count_words(char *str)
{
  int i = 0;
  int count = 0;
  while (str[i])
  {
    while(str[i] == ' ')
      i++;
    if (str[i])
      count++;
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
      i++;
  }
  return count;
}
//get next word
char *get_next_word(char *str, char c)
{
  static int cursor;
  int len;
  int i;
  char *next_word;

  len = 0;
  cursor = 0;
  i = 0;
  while (str[cursor] == c) //check
    ++cursor;
  while(str[cursor + len] != c && str[cursor + len])
    ++len;
  next_word = malloc(sizeof(char) * (size_t) (len + 1));
  if (!next_word)
    return NULL;
  while(str[cursor] != c && str[cursor])
    next_word[i++] = str[cursor++];
  next_word[i] = '\0';
  return (next_word);
}

//split
char **p_split(char *str, char c)
{
  int len;
  int i;
  char **result_array;

  i = 0;
  len = count_words(str);
  result_array = (char **)malloc(sizeof(char *) * (len + 2));
  if (!result_array)
    return (NULL);
  while(len-- >= 0)
  {
    if (i == 0)
    {
      result_array[i] = malloc(sizeof(char));
      if (!result_array[i])
        return NULL;
      result_array[i++][0] = '\0';
      continue;
    }
    result_array[i++] = get_next_word(str, c);
  }
  result_array[i] = NULL;
  return(result_array);
}
// //try
// int main()
// {
//   char *str = "0 1 2 3 4";
//   char **tab;
//   int i = 0;

//   tab = p_split(str, ' ');
//   while(i <= 5)
//   {
//     printf("%s", tab[i]);
//     i++;
//   }
//   return 0;
// }