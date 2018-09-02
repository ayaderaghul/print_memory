#include <stdio.h>
#include <unistd.h>
void ft_putchar(char c)
{
	write(1,&c,1);
}

const char *hexa = "0123456789abcdef";

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

void convert_to_hex_s(int n)
{
	if (n > 15)
		convert_to_hex_s(n/16);
	ft_putchar(hexa[n%16]);
}

void convert_to_hex(int n, int i)
{
    if (n > 15)
    {
        i++;
        convert_to_hex(n/16, i);
    }
    if (i == 1)
        ft_putchar(' ');
    ft_putchar(hexa[n%16]);
    ++i;
}

void print_hex(int n)
{
    int i = 0;
	i = digits(n);
	if (i < 5)
		convert_to_hex_s(n);
	else
		convert_to_hex(n,0);
	if (i < 5)
    {
        while (i < 10)
        {
            if (i == 4 || i == 9)
                ft_putchar(' ');
            else
                ft_putchar('0');
            ++i;
        }
    }
    else
    {
        ++i;
        while (i < 10)
        {
            if (i == 9)
                ft_putchar(' ');
            else
                ft_putchar('0');
            ++i;
        }
    }
}

void print_hex_space()
{
	int i;
	i = 0;
	while (i < 10)
	{
		ft_putchar(' ');
		++i;
	}
}

void ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n/10);
		ft_putnbr(n%10);
	}
	else
		ft_putchar(n+'0');
}

void print_ascii(int n)
{

//	ft_putnbr(n);
	if (32 <= n && n <= 126)
		ft_putchar(n);
	else
		ft_putchar('.');

}

void print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t l;
	size_t m = size/4;
	i = 0;
	j = 0;
	k = 0;
	l = 0;

	while (i < m && k < size)
	{
		i = j;
		j = i + 4;
		while (i < j)
		{
			if (i < m)
				print_hex(*((int*)addr + i));
			else
				print_hex_space();
			++i;
		}
		k = l;
		l = k + 16;
		while (k < l && k < size)
		{
			print_ascii(*((int*)addr + i));
			++k;
		}
		ft_putchar('\n');
	}
}

int main()
{
	int  tab[10] = {0,23,150,255,12,16,42,103};
	print_memory(tab, sizeof(tab));
//	printf("%lu\n",sizeof(tab));
	return 0;
}
