/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:18:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/20 17:18:56 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*ft_read_fd(int fd, char *staging)
{
	char	*buff;
	int		read_size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_size = 1;
	while (!ft_strchr(staging, '\n') && read_size != 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_size] = 0;
		staging = ft_strjoin(staging, buff);
	}
	free(buff);
	return (staging);
}

static char	*ft_extract_line(char *staging)
{
	int		idx;
	char	*tmp;

	idx = 0;
	if (!staging[idx])
		return (0);
	while (staging[idx] && staging[idx] != '\n')
		idx++;
	tmp = (char *)malloc(sizeof(char) * (idx + 2));
	if (!tmp)
		return (0);
	idx = 0;
	while (staging[idx] && staging[idx] != '\n')
	{
		tmp[idx] = staging[idx];
		idx++;
	}
	if (staging[idx] == '\n')
	{
		tmp[idx] = staging[idx];
		idx++;
	}
	tmp[idx] = 0;
	return (tmp);
}

static char	*ft_update_staging(char *staging)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (staging[i] && staging[i] != '\n')
		i++;
	if (!staging[i])
	{
		free(staging);
		return (0);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(staging) - i + 1));
	if (!tmp)
		return (0);
	i++;
	j = 0;
	while (staging[i])
		tmp[j++] = staging[i++];
	tmp[j] = 0;
	free(staging);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*staging[4096];

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (0);
	staging[fd] = ft_read_fd(fd, staging[fd]);
	if (!staging[fd])
		return (0);
	line = ft_extract_line(staging[fd]);
	staging[fd] = ft_update_staging(staging[fd]);
	return (line);
}
