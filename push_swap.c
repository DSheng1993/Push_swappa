/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:48:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:48:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int *index, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (index[i] == val)
			return (i + 1);
		i++;
	}
	return(i+1);
}

int	circular_struct_build(char **argv, t_push_swappa **a,
		t_push_swappa ***tail_a)
{
	int				i;
	int				*index;
	int				len;
	t_push_swappa	*element_i;
	t_push_swappa	*tmp;

	i = 1;
	element_i = malloc(sizeof(t_push_swappa));
	while (argv[i])
		i++;
	index = malloc(sizeof(int) * i - 1);
	i = 1;
	while (argv[i])
	{
		index[i - 1] = atoi(argv[i]);
		i++;
	}
	len = i - 1;
	quicks(index, 0, len - 1);
	i=0;
	while(i<len)
	{
		i++;
		if(index[i] == index[i-1])
			return(-1);
	}
	i = 1;
	element_i->valore = atoi(argv[i]);
	element_i->indice = check(index, len, element_i->valore);
	element_i->next = NULL;
	i++;
	*a = element_i;
	while (argv[i])
	{
		tmp = element_i;
		element_i = malloc(sizeof(t_push_swappa));
		element_i->valore = atoi(argv[i]);
		element_i->indice = check(index, len, element_i->valore);
		element_i->next = NULL;
		element_i->prev = tmp;
		tmp->next = element_i;
		i++;
	}
	(*a)->prev = element_i;
	**tail_a = element_i;
	(**tail_a)->next = *a;
	free(index);
	return(len);
}

int addfastpath(t_push_swappa **a, int lentmp)
{
	t_push_swappa *next = (*a)->next;
	t_push_swappa *prev = (*a)->prev;
	int i = 0;
	int x = 0;
	while(prev)
	{
		if(prev->indice <= lentmp)
			break;
		prev = prev->prev;
		x++;
	}
	while(next)
	{
		if(next->indice <= lentmp)
			break;
		next = next->next;
		i++;
	}
	return(i-x);
}

int addfastpathb(t_push_swappa **a, int lentmp)
{
	t_push_swappa *next = (*a)->next;
	t_push_swappa *prev = (*a)->prev;
	int i = 0;
	int x = 0;
	while(prev && prev->prev->indice != (*a)->indice)
	{
		if(prev->indice == lentmp)
			break;
		prev = prev->prev;
		x++;
		if(x>lentmp)
			break;
	}
	while(next && next->next->indice != (*a)->indice)
	{
		if(next->indice == lentmp)
			break;
		next = next->next;
		i++;
		if(i>lentmp)
			break;
	}
	return(i-x);
}

void free_list(t_push_swappa *list) {
    t_push_swappa *current = list;
    t_push_swappa *next = NULL;
	if(list == NULL)
		return;
    while (current->next != list) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);  // Free the last node (list)
}

// void close_to_len(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b)
// {

// }

// int sortb(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b, int len)
// {
// 	if(*b == NULL)
// 		break;
//     if (b && (*b)->indice == len)
//     {
//         pushx(b, a, tail_b, tail_a, 'b');
//         len--;
//     }

// 	return(len);
// } 

int	main(int argc, char **argv)
{
	t_push_swappa	*a;
	t_push_swappa	*b;
	t_push_swappa	**tail_a;
	t_push_swappa	**tail_b;
	int len;
	t_push_swappa	*curr_a;
	t_push_swappa	*curr_b;

	b = NULL;
	a = NULL;
	tail_a = malloc(sizeof(t_push_swappa *));
	tail_b = malloc(sizeof(t_push_swappa *));
	*tail_b = malloc(sizeof(t_push_swappa));
	if (argc > 1)
	{
		if (argc == 2)
			argv = ft_split1(argv[1], ' '); //split addattato con +1 per argv settato a NULL;
		len = circular_struct_build(argv, &a, &tail_a);
		if(len == -1)
		{
			printf("Ci sono doppioni");
			return(0);
		}
		main_sort(&a, &b, tail_a, tail_b, len);
		// if (a != NULL)
		// {
		// 	printf("List A: \n");
		// 	curr_a = a; // Start from the first element
		// 	do
		// 	{
		// 		printf("A: %d -> %d \n", curr_a->indice, curr_a->valore);
		// 		curr_a = curr_a->next; // Move to the next element
		// 	} while (curr_a != a); // Stop when we have circled back to the start
		// 	printf("\n");
		// }
		// if (b != NULL)
		// {
		// 	printf("List B:\n");
		// 	curr_b = b; // Start from the first element
		// 	do
		// 	{
		// 		printf("B: %d -> %d\n", curr_b->indice, curr_b->valore);
		// 		curr_b = curr_b->next; // Move to the next element
		// 	} while (curr_b != b); // Stop when we have circled back to the start
		// 	printf("\n");
		// }
		// free_list(a);
		// free_list(b);
		return (0);
	}
}
//gcc -g push_swap.c implement.c command.c functions.c -o push_swap -Werror -Wextra -Wall

//./push_swap $(seq 1 100 | shuf | tr '\n' ' ')