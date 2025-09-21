 ft_printf

Because ft_putnbr() and ft_putstr() aren’t enough


int	main()
{
	int	*ptr;
	printf("%d\n",ft_printf("mine  %d\n", 5));
	printf("%d\n",printf("orgnl %d\n", 5));
	printf("%d\n",ft_printf("mine  %i\n", 5));
	printf("%d\n",printf("orgnl %i\n", 5));
	printf("%d\n",ft_printf("mine  %c\n", 'c'));
	printf("%d\n",printf("orgnl %c\n", 'c'));
	printf("%d\n",ft_printf("mine  %s\n", "mamoun zaid"));
	printf("%d\n",printf("orgnl %s\n", "mamoun zaid"));
	printf("%d\n",ft_printf("mine  %u\n", 5));
	printf("%d\n",printf("orgnl %u\n", 5));
	printf("%d\n",ft_printf("mine  %%\n", "mamoun zadi"));
	printf("%d\n",printf("orgnl %%\n", "mamoun zaid"));
	printf("%d\n",ft_printf("mine  %x\n", 14259));
	printf("%d\n",printf("orgnl %x\n", 14259));
	printf("%d\n",ft_printf("mine  %X\n", 14259));
	printf("%d\n",printf("orgnl %X\n", 14259));
	printf("%d\n",ft_printf("mine  %p\n", &ptr));
	printf("%d\n",printf("orgnl %p\n", &ptr));
	
	return (0);
}
