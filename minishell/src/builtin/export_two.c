/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"
#include <stdlib.h>

static int	compare(const void *a, const void *b)
{
	const char	**str1;
	const char	**str2;

	str1 = (const char **)a;
	str2 = (const char **)b;
	return (ft_strcmp(*str1, *str2));
}

static void	total_memcpy(void *tmp, void *s1, void *s2, size_t size)
{
	ft_memcpy(tmp, s1, size);
	ft_memcpy(s1, s2, size);
	ft_memcpy(s2, tmp, size);
}

static void	conditional(char **temp, char **left, char **right, size_t *size)
{
	total_memcpy(*temp, *left, *right, *size);
	*left += *size;
	*right -= *size;
}

static void	*my_sort(void *b, size_t m, size_t s,
			int (*c)(const void *, const void *))
{
	char	*pivot;
	char	*l;
	char	*r;
	char	*t;

	pivot = (char *)b;
	l = (char *)b + s;
	r = (char *)b + (m - 1) * s;
	t = (char *)malloc(sizeof(char) * s);
	if (!t)
		return (NULL);
	if (m <= 1)
		return (free(t), NULL);
	while (l <= r && !(m <= 1 || t == NULL))
	{
		while (l <= r && c(l, pivot) <= 0)
			l += s;
		while (l <= r && c(r, pivot) > 0)
			r -= s;
		if (l < r)
			conditional(&t, &l, &r, &s);
	}
	total_memcpy(t, pivot, r, s);
	my_sort(b, (r - (char *)b) / s, s, c);
	return (my_sort(r + s, m - ((r - (char *)b) / s) - 1, s, c), free(t), NULL);
}

char	**copy_and_sort_envp(t_minishell *shell)
{
	int		i;
	int		size;
	char	**copied_envp;

	i = -1;
	size = 0;
	while (shell->envp[size] != NULL)
		size++;
	copied_envp = (char **)check_malloc((size + 1) * sizeof(char *));
	if (copied_envp == NULL)
		exit(EXIT_FAILURE);
	while (++i < size)
	{
		if (ft_strnstr(shell->envp[i], "OLDPWD", ft_strlen(shell->envp[i]))
			&& shell->flag_oldpwd == 0)
			copied_envp[i] = my_strdup("OLDPWD");
		else
			copied_envp[i] = my_strdup(shell->envp[i]);
		if (copied_envp[i] == NULL)
			exit(EXIT_FAILURE);
	}
	copied_envp[size] = NULL;
	my_sort(copied_envp, size, sizeof(char *), compare);
	return (copied_envp);
}
