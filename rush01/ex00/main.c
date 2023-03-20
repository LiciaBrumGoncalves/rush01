/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:49:33 by amgoncal          #+#    #+#             */
/*   Updated: 2023/03/19 20:17:53 by lbrum-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	matrizes(char matriz[4][4], int linha, int coluna, char *entrada);

int	main(int argc, char **argv)
{
	int		i;
	char	matriz[4][4];

	i = 0;
	if (argc != 2 || argv[1][31] != '\0')
	{
		write (1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (((argv[1][i] > '4' || argv[1][i] < '1') && i % 2 == 0)
					|| (i % 2 != 0 && argv[1][i] != ' '))
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (matrizes(matriz, 0, 0, argv[1]) == 1)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
