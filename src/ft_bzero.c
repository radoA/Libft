/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:08:06 by radandri          #+#    #+#             */
/*   Updated: 2025/07/12 09:48:11 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (s == NULL)
	{
		return ;
	}
	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
