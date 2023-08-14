/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:42:36 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:35:45 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

// #include <stdio.h>

// int main()
// {
// 	t_list *earth;
// 	t_list *starlink;
// 	t_list *polaris;
// 	t_list *aort;
// 	t_list *kuiper;

// 	earth = ft_lstnew("earth");
// 	starlink = ft_lstnew("starlink");
// 	polaris = ft_lstnew("polaris");
// 	aort = ft_lstnew("aort");
// 	kuiper = ft_lstnew("kuiper");

// 	earth->next = starlink;
// 	starlink->next = polaris;
// 	polaris->next =aort;

// 	ft_lstadd_back(&starlink,kuiper);

// 	printf("%s",aort->next->content);
// }
