/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 08:50:44 by lnguyen           #+#    #+#             */
/*   Updated: 2018/09/06 11:08:03 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

int digits(int n)
{
	int i;
	i = 1;
	while (n > 15)
	{
		n = n/16;
		++i;
	}
	return (i);
}

const char *hexa = "0123456789abcdef";

void init(char *array, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		if (i == 4 || i == 9)
			array[i] = ' ';
		else
			array[i] = '0';
		++i;
	}
}

void init2(char *array2, int size)
{
  int i = 0;
  while (i < size)
    array2[i++] = '0';
}

int convert_to_hex(int n, char *array, char *array2, int j)
{
	int r = 0;
	int d = 0;
	d = digits(n);
	int i = d - 1;
	while (n > 15)
	{
		if (i == 4)
		{
			i++;
			r = n%16;
			array[i] = hexa[r];
			n = n / 16;
			i = i - 2;
		}
		else
		{
			r = n%16;
			array[i] = hexa[r];
			n = n / 16;
			i--;
		}

	}
	array[i] = hexa[n];
	i = 0;
	while (i < 9)
	  {
	    if (i == 4)
	      ++i;
	    else
	      {
		array2[j] = array[i];
		++i;
		++j;
	      }
	  }
	return j;
}

void print_array(char *array, int size)
{
	int i = 0;
	while (i < size)
	{
		ft_putchar(array[i]);
		++i;
	}
}

void print_space()
{
	int i;
	i = 0;
	while (i < 10)
	{
		ft_putchar(' ');
		++i;
	}
}

void print_ascii(int n)
{
  if (32 <= n && n <=126)
    ft_putchar(n);
  else
    ft_putchar('.');
}

void print_hex(int n, char *array, char *array2, int j)
{
  convert_to_hex(n,array,array2,j);
  print_array(array,10);
  init(array,10);
}

int hex_dec(char c)
{
  int i = 0;
  while (i < 16)
    {
      if (c == hexa[i])
	return i;
      ++i;
    }
  return -1;
}
	  
#include <stdio.h>
void print_memory(const void *addr, size_t size)
{
	char array[10];
	init(array,10);
	int n = 0;
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	size_t l = 0;
	size_t length = size/4;
	char array2[length * 8];
	init2(array2, length * 8);
	int *str;
	str = (int*)addr;
	int m = 0;
	while (i < length)
	{
		i = j;
		j = i + 4;
		while (i < j)
		{
			if (i < length)
			{
				n = *(str+i);
				print_hex(n, array, array2, i * 8);
			}
			else
				print_space();
			++i;
		}
		k = l;
		l = k + 32;
		while (k < l && k < length * 8)
		{
		  m = hex_dec(array2[k]) * 10 + hex_dec(array2[k + 1]);
		  printf("m: %d\n",m);
		  print_ascii(m);
		  k = k + 2;
		}
		ft_putchar('\n');
	}
}

/*
int main()
{
	int tab[10] = {0,23,150,255,12,16,42,103};
	print_memory(tab, sizeof(tab));
	return 0;
}
*/
