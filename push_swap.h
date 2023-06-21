/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:49:00 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct t_push_swappa
{
	int valore;
	int indice;
	struct t_push_swappa *next;
	struct t_push_swappa *prev;
} t_push_swappa;

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void swap(int *val1, int*val2, int*ind1, int*ind2, char flag);
void double_swap(int *val1, int *val2, int *val3, int *val4, int*ind1, int*ind2, int*ind3, int*ind4);
void push(t_push_swappa **push, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take);
void rotate(t_push_swappa **head, t_push_swappa **tail, int up_down);
void quicks(int *a,int first, int last);
void pushx(t_push_swappa **pushr, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take, char d);
void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len);
void double_updownrotate(t_push_swappa **head, t_push_swappa **tail,t_push_swappa **head1, t_push_swappa **tail1, char *d);
void updownrotate(t_push_swappa **head, t_push_swappa **tail, char *d);
int	nstr(const char *s, char c);
int	checksizesub(const char *s, char c);
char	**ft_split1(char const *s, char c);
int addfastpath(t_push_swappa **a, int lentmp);
int addfastpathb(t_push_swappa **a, int lentmp);
void swapq(int* a, int*b);
int ft_strlen(const char* s);
int lastn(t_push_swappa **a, t_push_swappa **tail_a,int m);

#endif