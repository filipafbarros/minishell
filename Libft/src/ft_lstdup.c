/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:58:10 by fibarros          #+#    #+#             */
/*   Updated: 2024/07/01 11:02:51 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_list	*new_list;
	t_list	*temp;

	new_list = 0;
	while (list)
	{
		temp = ft_lstnew(list->content);
		if (!temp)
			return (0);
		ft_lstadd_back(&new_list, temp);
		list = list->next;
	}
	return (new_list);
}
