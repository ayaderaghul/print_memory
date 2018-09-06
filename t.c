#include "t.h"

void ft(const void *addr)
{
	size_t s = sizeof(typeof(*(addr+0)));
	ft_putchar(s+'0');
}

int main()
{

/*
	char str[10] = {'0','1'};
	int tab[10] = {1,2};
	int s = 0;
	s = sizeof(typeof(*(str+0)));
	int s2 = 0;
	s2 = sizeof(typeof(*(tab+0)));
	printf("str: %d, tab: %d\n",s,s2);

	ft(tab);
	ft_putchar('\n');
	ft(str);
	ft_putchar('\n');

*/


// init test
/*	char array[10];
	print_array(array,10);
	write(1,"\n",1);
	init(array,10);
	print_array(array,10);
	write(1,"\n",1);
*/
// convert to hex
/*
	char array[10];
	init(array,10);
	write(1,"23: ",4);
	convert_to_hex(23, array);
	print_array(array,10);
	write(1,"\n",1);

	write(1,"99: ",4);
	convert_to_hex(99, array);
	print_array(array,10);
	write(1,"\n",1);

	write(1,"999: ",5);
	convert_to_hex(999, array);
	print_array(array,10);
	write(1,"\n",1);

	write(1,"9999: ",6);
	convert_to_hex(9999, array);
	print_array(array,10);
	write(1,"\n",1);

	write(1,"99999: ",7);
	convert_to_hex(99999, array);
	print_array(array,10);
	write(1,"\n",1);
*/
// print_memory
	
	int tab[10] = {0,23,150,255,12,16,42,103};
    print_memory(tab, sizeof(tab));

	return 0;
}
