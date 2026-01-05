/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:45:03 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 15:35:33 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**initalize_words(char const *s, char c)
{
	int	word_c;
	int	is_word;
	int	i;

	word_c = 0;
	is_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			is_word = 1;
		else if (is_word)
		{
			word_c++;
			is_word = 0;
		}
		i++;
	}
	if (is_word)
		word_c++;
	return (malloc((word_c + 1) * sizeof(char *)));
}

static char	*make_word(const char **s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while ((*s)[len] != c && (*s)[len] != '\0')
		len++;
	word = ft_substr(*s, 0, len);
	*s = *s + len;
	return (word);
}

static void	free_everything(int word_i, char **words)
{
	while (word_i >= 0)
	{
		free(words[word_i]);
		word_i--;
	}
	free(words);
}

/// @brief Takes string s and delimiter character c,
/// @brief returns array of substrings of s split by the delimiter.
/// @brief The character defined in c will be removed from the string
/// @brief and does not show up in any of the substrings.
/// @param s Null-terminated string to be split.
/// @param c The character s will be split by.
/// @return Dynamically allocated array of substrings. The last element
/// @return is always a nullpointer. Each substring is null-terminated.
/// @return If any allocation fails a null-pointer is returned and
/// @return any already allocated memory will be freed.
char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_i;

	words = initalize_words(s, c);
	if (!words)
		return (NULL);
	word_i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			words[word_i] = make_word(&s, c);
			if (words[word_i] == NULL)
			{
				free_everything(word_i, words);
				return (NULL);
			}
			word_i++;
		}
		else
			s++;
	}
	words[word_i] = NULL;
	return (words);
}
