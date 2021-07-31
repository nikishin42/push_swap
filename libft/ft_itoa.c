/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:24:49 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:24:52 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_to_char(char *string, int n, int length)
{
	while (n > 9)
	{
		length--;
		string[length] = (n % 10) + 48;
		n /= 10;
	}
	string[length - 1] = n + 48;
}

int	ft_sign_for_itoa(char *string, int n)
{
	n = -n;
	string[0] = '-';
	return (n);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		length;
	int		temp_num;

	temp_num = n;
	length = 0;
	if (temp_num <= 0)
		length++;
	while (temp_num && length++ > -1)
		temp_num /= 10;
	string = NULL;
	if (n == -2147483648)
	{
		string = ft_strdup("-2147483648");
		return (string);
	}
	string = (char *)malloc(length + 1);
	if (!string)
		return ((char *) NULL);
	string[length] = '\0';
	if (n < 0)
		n = ft_sign_for_itoa(string, n);
	ft_int_to_char(string, n, length);
	return (string);
}
