/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_llstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:04:58 by fmontel           #+#    #+#             */
/*   Updated: 2025/12/13 19:07:08 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	str_llstr(char *big, char *little, size_t len, int start)
{
	size_t	i;

	if (!big || !little || len == 0)
		return (0);
	i = 0;
	if (big[start] == little[0])
	{
		while (big[start + i] == little[i] && big[start + i] != 0
			&& i != len)
			i++;
		if (little[i] == 0)
			return (1);
	}
	return (0);
}
