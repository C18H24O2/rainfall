/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 03:12:56 by kiroussa          #+#    #+#             */
/*   Updated: 2025/03/25 03:16:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*gets(char *buffer);

void	run(void)
{
	puts("Good... Wait what?");
	(void)!system("/bin/sh");
	return ;
}

int	main(void)
{
	char	buffer[64];

	gets(buffer);
	return (0);
}
