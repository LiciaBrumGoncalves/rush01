/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfilguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:43:09 by jfilguei          #+#    #+#             */
/*   Updated: 2023/03/19 20:26:19 by lbrum-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	validate(char m[4][4], char *n);

int	matrizes(char matriz[4][4], int linha, int coluna, char *entrada);

void	imprimir_matriz(char matriz[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &matriz[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	verifica_num(char matriz[4][4], int linha, int coluna, char numero)
{
	int	j;

	j = 0;
	while (j < coluna)
	{
		if (matriz[linha][j] == numero)
			return (1);
		j++;
	}
	j = 0;
	while (j < linha)
	{
		if (matriz[j][coluna] == numero)
			return (1);
		j++;
	}
	return (0);
}

int	validar_matriz(char matriz[4][4], char *entrada)
{
	if (validate(matriz, entrada) == 0)
	{
		imprimir_matriz(matriz);
		return (0);
	}
	return (1);
}

int	gerar_m2(char matriz[4][4], int linha, int coluna, char *entrada)
{
	char	i;

	i = '0';
	while (i++ <= '4')
	{
		if (verifica_num(matriz, linha, coluna, i) == 0)
		{
			matriz[linha][coluna] = i;
			if (coluna == 3)
			{
				if (matrizes(matriz, linha + 1, 0, entrada) == 0)
					return (0);
			}
			else
			{
				if (matrizes(matriz, linha, coluna + 1, entrada) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int	matrizes(char matriz[4][4], int linha, int coluna, char *entrada)
{
	if (linha == 4)
	{
		return (validar_matriz(matriz, entrada));
	}
	else
	{
		return (gerar_m2(matriz, linha, coluna, entrada));
	}
}
