#include "push_swap.h"

int checkpresence(t_push_swappa *tail, int count, int lentmp)
{
	t_push_swappa *current = tail;
	int x;
	x = 1;
	int g;
	g=0;
	while (current && count > 0)
	{
		if(current->prev->indice == lentmp)
		{
			g = x;
			break;
		}
		x++;
		current = current->prev;
		count--;
	}
	if(count > 0)
		return g;
	else
		return 0;
}

int lastn(t_push_swappa **a, t_push_swappa **tail_a,int m)
{
	if((*a)->indice == m && (*a)->next->indice == m+1 && (*a)->next->next->indice == m+2)
		return(0);
	if((*a)->indice == m+2)
	{
		updownrotate(a, tail_a, "ra");
		if((*a)->indice == m+1)
			swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); 
	}
	else if((*a)->indice == m+1 && (*a)->next->indice == m+2)
		updownrotate(a, tail_a, "rra");
	else if((*a)->indice == m+1 && (*a)->next->indice == m)
		swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); 
	else if((*a)->indice == m && (*a)->next->indice == m+2)
	{
		swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); 
		updownrotate(a, tail_a, "ra");
	}
	return(2);
}


void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len)
{
	int				lentmp;
	int				z;
	int				m;
	int				i;
	int first;
	int count = 0;
	int b_count = 0;
	int wait;
	wait = 0;
	z = 0;
	m = 0;
	i = 2;

	lentmp = len / 2;
	first = lentmp/2;
	while (m < len - 1)
	{
		if(m == len-3)
		{
			while(wait)
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
					wait--;
				}
			z+=lastn(a, tail_a, m+1);
			len-=2;
			break;
		}
		if ((*a)->indice <= lentmp)
		{
			m++;
			if((*a)->indice <= (lentmp/2) && (lentmp/2) == first)
			{
				while(wait)
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
					wait--;
				}
				pushx(a, b, tail_a, tail_b, 'a');
				if((*a)->indice <= (lentmp/6))
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
				}
				else
					wait++;
				// if((*a) && (*a)->indice > lentmp)
				// {
				// 	double_updownrotate(a, tail_a, b, tail_b, "rr");
				// 	z++;
				// }
				// else {
				// 	updownrotate(b, tail_b, "rb");
				// 	z++;
				// }
				z++;
			}
			else if((*a)->indice > (lentmp/2) && (lentmp/2) != first)
			{
				while(wait)
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
					wait--;
				}
				pushx(a, b, tail_a, tail_b, 'a');
				if((*a) && (*a)->indice > lentmp)
				{
					double_updownrotate(a, tail_a, b, tail_b, "rr");
					z++;
				}
				else
				{
					updownrotate(b, tail_b, "rb");
					z++;
				}
				count++;
				z++;
			}
			else
			{
				while(wait)
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
					wait--;
				}
				pushx(a, b, tail_a, tail_b, 'a');
				z++;
			}	
		}
		else
		{
			updownrotate(a, tail_a, "ra");
			z++;
		}
		if (m == lentmp )
		{
			while(wait)
				{
					if((*a) && (*a)->indice > lentmp)
					{
						double_updownrotate(a, tail_a, b, tail_b, "rr");
						z++;
					}
					else 
					{
						updownrotate(b, tail_b, "rb");
						z++;
					}
					wait--;
				}
			int flag_rrr = lentmp+1;
			int presence = checkpresence(*a, count, flag_rrr);
			while(count > 0)
			{
				presence = checkpresence(*a, count, flag_rrr);
				if((*a) && presence >= 1)
				{
					double_updownrotate(a, tail_a, b, tail_b, "rrr");
					presence--;
					// printf("(*a)->indice %d,lentmp: %d\n",(*a)->indice , flag_rrr);
				}
				else
					updownrotate(b, tail_b, "rrb");
			
				z++;
				count--;
				if((*a)->indice == flag_rrr)
						presence = checkpresence(*a, count, ++flag_rrr);
			}
			lentmp = lentmp + ((len - lentmp + i - 1) / i);
		}
	}
	len = len - 1;

	while(len)
	{
		if((*b)->indice == (len-1))
		{
			pushx(b, a, tail_b, tail_a, 'b');
			z++;
			count++;
		}
		if((*b)->indice == len)
		{
			pushx(b, a, tail_b, tail_a, 'b');
			len--;
			z++;
			if(count == 1)
			{
				if(*b && (*b)->next && (*b)->next->indice == len)
					double_swap(&((*a)->valore), &((*a)->next->valore), &((*b)->valore),&((*b)->next->valore),&((*a)->indice) ,&((*a)->next->indice),&((*b)->indice) ,&((*b)->next->indice));
				else
					swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); 
				len--;
				count=0;
				z++;
			}
		}
		else if(addfastpathb(b, len) < 0)
		{
			while (*b && (*b)->indice < len)
			{
				updownrotate(b, tail_b, "rb");
				if((*b)->indice == (len-1))
				{
					pushx(b, a, tail_b, tail_a, 'b');
					z++;
					count++;
				}
				z++;
			}
		}
		else
		{
			while (*b && (*b)->indice < len)
			{
				updownrotate(b, tail_b, "rrb"); 
				if((*b)->indice == (len-1))
				{
					pushx(b, a, tail_b, tail_a, 'b');
					z++;
					count++;
				}
				z++;
			}
		}
	}

	// printf("\nMOVIMENTI: %d\n", z);
	// while (len)
	// {
	// 	len = sortb(a,b,tail_a,tail_b,len);
	// }
	// printf("\n\nMosse: %d \n\n", z);
	// swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); // sa
	// swap(&((*b)->valore), &((*b)->next->valore),&((*b)->indice) ,&((*b)->next->indice), 'b');
	// pushx(a, b, tail_a, tail_b, 'a');
	// double_updownrotate(a, tail_a, b, tail_b, "rr"); // entrambi UP di 1;
	// double_updownrotate(a, tail_a, b, tail_b, "rrr"); // entrambi DOWN di 1;
	// swap(&((*a)->valore), &((*a)->next->valore), 'a');
	// pushx(b, a, tail_b, tail_a, 'b');
	// double_swap(&((*a)->valore), &((*a)->next->valore), &((*b)->valore),&((*b)->next->valore),&((*a)->indice) ,&((*a)->next->indice),&((*b)->indice) ,&((*b)->next->indice));
	// updownrotate(a, tail_a, "ra"); // a UP di 1;
	// updownrotate(b, tail_b, "rb"); // b UP di 1;
	// updownrotate(a, tail_a, "rra"); // a DOWN di 1;
	// updownrotate(b, tail_b, "rrb"); // b DOWN di 1;
	// pushx(a, b, tail_a, tail_b, 'a'); // pusha a in b "pb"
	// pushx(b, a, tail_b, tail_a, 'b'); // pusha b in a "pa"
}
