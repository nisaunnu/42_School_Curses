/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:42:36 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:36:14 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main()
// {
// 	t_list *pluto;
// 	t_list *saturn;
// 	t_list *moon;

// 	pluto = ft_lstnew("pluto");
// 	saturn = ft_lstnew("saturn");
// 	moon = ft_lstnew("moon");

// 	pluto->next = saturn;
// 	printf("%s\t%s\n", pluto->content, pluto->next->content);
// 	ft_lstadd_front(&pluto, moon);
// 	printf("%s\t%s\t%s\n", pluto->content, pluto->next->content, pluto->next->next->content);
// }
