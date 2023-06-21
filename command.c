#include "push_swap.h"

void pushx(t_push_swappa **pushr, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take, char d)
{
	push(pushr, take, t_push, t_take);
	if(d == 'a')
		printf("pb\n"); //stampa anche se la lista è vuota.
	else if (d == 'b')
		printf("pa\n");
}

void updownrotate(t_push_swappa **head, t_push_swappa **tail, char *d)
{
	int up_down;
	if(strcmp("rra", d) == 0|| strcmp("rrb", d) == 0)
		up_down = -1;
	else if(strcmp("ra", d) == 0 || strcmp("rb", d) == 0)
		up_down = 1;
	rotate(head, tail, up_down);
	printf("%s\n", d);
}

void double_updownrotate(t_push_swappa **head, t_push_swappa **tail,t_push_swappa **head1, t_push_swappa **tail1, char *d)
{
	int up_down;
	if(strcmp("rrr", d) == 0)
		up_down = -1;
	else if(strcmp("rr", d) == 0)
		up_down = 1;
	rotate(head, tail, up_down);
	rotate(head1, tail1, up_down);
	printf("%s\n", d);
}

void swap(int *val1, int*val2, int*ind1, int*ind2, char flag) //flag = write down;
{
	int tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	tmp = *ind1;
	*ind1 = *ind2;
	*ind2 = tmp;
	if(flag == 'a')
		printf("sa\n");
	else if(flag == 'b')
		printf("sb\n");
}

void double_swap(int *val1, int *val2, int *val3, int *val4, int*ind1, int*ind2, int*ind3, int*ind4) {
        swap(val1, val2, ind1, ind2,1);
        swap(val3, val4, ind3, ind4,1);
        printf("ss\n");
}

