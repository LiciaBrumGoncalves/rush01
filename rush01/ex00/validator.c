/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:27:50 by amgoncal          #+#    #+#             */
/*   Updated: 2023/03/19 18:42:01 by lbrum-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	val_rl(char m[4][4], char *n, int r)
{
	int	j;
	int	i;
	int	c;

	while (r < 4)
	{
		j = 1;
		i = 0;
		c = '1';
		while (j < 4)
		{
			if (m[r][j] > m[r][i])
			{
				i = j;
				c++;
			}
			j++;
		}
		if (c != n[(r * 2) + 16])
			return (1);
		r++;
	}
	return (0);
}

int	val_rr(char m[4][4], char *n, int r)
{
	int	j;
	int	i;
	int	c;

	while (r < 4)
	{
		j = 2;
		i = 3;
		c = '1';
		while (j >= 0)
		{
			if (m[r][j] > m[r][i])
			{
				i = j;
				c++;
			}
			j--;
		}
		if (c != n[(r * 2) + 24])
			return (1);
		r++;
	}
	return (0);
}

int	val_cup(char m[4][4], char *n, int r)
{
	int	j;
	int	i;
	int	c;

	while (r < 4)
	{
		j = 1;
		i = 0;
		c = '1';
		while (j < 4)
		{
			if (m[j][r] > m[i][r])
			{
				i = j;
				c++;
			}
			j++;
		}
		if (c != n[(r * 2)])
			return (1);
		r++;
	}
	return (0);
}

int	val_cdn(char m[4][4], char *n, int r)
{
	int	j;
	int	i;
	int	c;

	while (r < 4)
	{
		j = 2;
		i = 3;
		c = '1';
		while (j >= 0)
		{
			if (m[j][r] > m[i][r])
			{
				i = j;
				c++;
			}
			j--;
		}
		if (c != n[(r * 2) + 8])
			return (1);
		r++;
	}
	return (0);
}

int	validate(char m[4][4], char *n)
{
	if (val_rl(m, n, 0))
		return (1);
	if (val_rr(m, n, 0))
		return (1);
	if (val_cup(m, n, 0))
		return (1);
	if (val_cdn(m, n, 0))
		return (1);
	return (0);
}
