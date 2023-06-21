#include "push_swap.h"

int ft_strlen(const char* s)
{
	int i;
	i=0;
	while(s[i])
		i++;
	return(i);
}

int	nstr(const char *s, char c)
{
	int	ogni;

	ogni = 0;
	if (*s != c)
		ogni++;
	while (*s)
	{
		if ((*(s + 1) == c && *s != c))
			ogni++;
		s++;
	}
	return (ogni);
}

int	checksizesub(const char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		a++;
		i++;
	}
	return (a);
}

char	**ft_split1(char const *s, char c)
{
	int	y;
	int	x;
	int	i;
	char	**result;

	y = 0;
	i = 0;
	x = 0;
	result = (char **)malloc(sizeof(s) * (nstr(s, c) + 2));
	result[x] = NULL;
	x = 1;
	while (y < ft_strlen(s) && x < (nstr(s, c)+1))
	{
		result[x] = (char *)malloc(sizeof(char) * (checksizesub((s + y), c)
					+ 1));
		while (c == s[y] && i == 0)
			y++;
		while (s[y] != c && '\0' != s[y])
			result[x][i++] = s[y++];
		if (s[y] == c || (s[y++] == '\0' && i != 0))
			result[x++][i] = '\0';
		i = 0;
	}
	result[x] = NULL;
	return (result);
}


void swapq(int* a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicks(int *a,int first, int last) //last = size-1;
{
	int i;
	int j;
	int pivot;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot] && i < last) //considero i valori di a[i] e a[pivot] e scorro
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
				swapq(&a[i], &a[j]);
		}
		swapq(&a[pivot],&a[j]);
		quicks(a, first, j-1);
		quicks(a, j+1, last);
	}
}
