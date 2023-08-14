/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:42:36 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:37:03 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

// void del(void *data)
// {
// 	free(data);
// }

// #include <stdio.h>

// int main()
// {
// 	t_list *list;
// 	int *data = (int*)malloc(sizeof(int));

// 	*data = 42;
// 	list = ft_lstnew(data);

// 	printf("%d\n", *((int*)list->content));

// 	ft_lstdelone(list, del);

// 	printf("%d", *((int*)list->content));

// 	return (0);
// }
