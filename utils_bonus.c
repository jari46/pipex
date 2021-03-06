/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:26:09 by yehan             #+#    #+#             */
/*   Updated: 2022/06/13 07:48:24 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

bool	is_valid_argc(int argc, char **argv)
{
	return ((argc >= 5 && !is_heredoc(argv[1]))
		|| (argc >= 6 && is_heredoc(argv[1])));
}

bool	is_heredoc(const char *argv1)
{
	return (!ft_strncmp(argv1, "here_doc", 9));
}

/* is_limiter():
** line 20: The program pretends that [line] has no new line,
** 			only to check if it is a [limiter].
*/
bool	is_limiter(const char *line, const char *limiter)
{
	if (ft_strlen(line) - 1 == ft_strlen(limiter)
		&& !ft_strncmp(line, limiter, ft_strlen(limiter)))
		return (true);
	else
		return (false);
}

void	free_twoarr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}
