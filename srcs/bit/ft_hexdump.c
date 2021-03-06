/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 04:16:42 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/05 04:16:44 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_byte(unsigned char byte)
{
	static char	hexa[16] = "0123456789abcdef";

	write(1, "\033[34;1m", ft_strlen("\033[34;1m"));
	write(1, &hexa[byte >> 4], 1);
	write(1, &hexa[byte & 15], 1);
	write(1, "\033[0m", ft_strlen("\033[0m"));
}

static void		ft_print_str(unsigned char *str, int len)
{
	int	i;

	i = 0;
	write(1, "\033[32;1m", ft_strlen("\033[33;1m"));
	while (i < len)
	{
		if (str[i] >= 32 && str[i] < 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "\033[0m", ft_strlen("\033[0m"));
}

static void		ft_print_line(unsigned char *ptr, int len)
{
	int		i;
	int		col;

	i = 0;
	col = 40;
	while (i < len)
	{
		ft_print_byte(ptr[i]);
		write(1, " ", 1);
		col -= 2;
		if (i + 1 < len)
		{
			ft_print_byte(ptr[i + 1]);
			write(1, " ", 1);
			col -= 3;
		}
		i += 2;
	}
	while (col--)
		write(1, " ", 1);
	ft_print_str(ptr, len);
}

void			ft_hex_dump(const void *addr, size_t size)
{
	unsigned char	*ptr;
	int				nb_line;
	int				nb_byte;
	int				i;

	ptr = (unsigned char*)addr;
	nb_line = size / 16;
	nb_byte = size % 16;
	i = 0;
	while (i < nb_line)
	{
		ft_print_line(ptr, 16);
		ptr += 16;
		i++;
	}
	if (nb_byte)
		ft_print_line(ptr, nb_byte);
}
