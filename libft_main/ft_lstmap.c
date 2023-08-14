/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:34:16 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:29:10 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;
	void	*content;

	if (lst == NULL || f == NULL)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			(*del)(content);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}

// #include <stdio.h>

// void    del(void *content)
// {
//     free(content);
// }

// void *f(void *content)
// {
//  	((char *)content)[0] -= 32;
//  	return(content);
// }

// int main()
// {
//  	t_list	*node1;
// 		t_list	*node2;
//  	t_list	*tmp;

//  	node1 = ft_lstnew(ft_strdup("nisa"));
//  	node2 = ft_lstnew(ft_strdup("kocaeli"));

//  	ft_lstadd_back(&node1, node2);
//  	tmp = ft_lstmap(node1, &f, &del);

//  	printf("**%s**", (char *)tmp->content);
//  	printf("%s", (char *)tmp->next->content);
// }
