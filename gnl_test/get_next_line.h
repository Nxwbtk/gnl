/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:48:39 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/23 16:50:59 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
size_t	ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif