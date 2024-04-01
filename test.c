#include <stdio.h>
#include <stdlib.h>

int	is_repeating(int arr[], int size)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	dup = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] == arr[j])
				dup = 1;
		}
		if (dup == 1)
			break ;
	}
	return (dup);
}

int	main(void)
{
	int	arr[] = {8, 12, 4, 5, 2, 3, 1, 11, 2147483647};
	int	arr_size;

	printf("is dup %d", is_repeating(arr, 9));
	return (0);
}
