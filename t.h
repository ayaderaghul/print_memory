/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 09:22:32 by lnguyen           #+#    #+#             */
/*   Updated: 2018/09/06 10:02:50 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef T_H
# define T_H
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c);
int digits(int n);
void init(char *array,int size);
void convert_to_hex(int n, char *array);
void print_array(char *array, int size);
void print_memory(const void *addr, size_t size);


#endif
