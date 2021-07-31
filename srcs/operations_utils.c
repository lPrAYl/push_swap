#include "../push_swap.h"

void	sa(DblLinkedList **stackA)
{
	size_t	size;
	t_data	data;
	
	size = (*stackA)->size;
	if (size == 0 || size == 1)
		return ;
	(*stackA)->head->data.pos_in_stack++;
	data = deleteNth(*stackA, 1);
	data.pos_in_stack--;
	pushFront(*stackA, data);
}

void	sb(DblLinkedList **stackB)
{
	size_t	size;
	t_data	data;
	
	size = (*stackB)->size;
	if (size == 0 || size == 1)
		return ;
	data = deleteNth(*stackB, 1);
	pushFront(*stackB, data);
}

void	ss(DblLinkedList **stackA, DblLinkedList **stackB)
{
	sa(stackA);
	sb(stackB);
}

void	pa(DblLinkedList **stackA, DblLinkedList **stackB)
{
	t_data	data;
	Node	*tmp;

	if (*stackB == NULL)
		return ;
	data = popFront(*stackB);
	data.pos_in_stack = 0;
	tmp = (*stackA)->head;
	while (tmp)
	{
		tmp->data.pos_in_stack++;
		tmp = tmp->next;
	}
	pushFront(*stackA, data);
}

void	pb(DblLinkedList **stackA, DblLinkedList **stackB)
{
	t_data	data;
	Node	*tmp;

	if (*stackA == NULL)
		return ;
	data = popFront(*stackA);
	tmp = (*stackA)->head;
	while (tmp)
	{
		tmp->data.pos_in_stack--;
		tmp = tmp->next;
	}
	pushFront(*stackB, data);
}

void	ra(DblLinkedList **stackA)
{
	size_t	size;
	t_data	data;
	Node	*tmp;

	size = (*stackA)->size;
	if (size == 0 || size == 1)
		return ;
	data = popFront(*stackA);
	data.pos_in_stack = size - 1;
	tmp = (*stackA)->head;
	while (tmp)
	{
		tmp->data.pos_in_stack--;
		tmp = tmp->next;
	}
	pushBack(*stackA, data);
}

void	rb(DblLinkedList **stackB)
{
	size_t	size;
	t_data	data;

	size = (*stackB)->size;
	if (size == 0 || size == 1)
		return ;
	data = popFront(*stackB);
	pushBack(*stackB, data);
}

void	rr(DblLinkedList **stackA, DblLinkedList **stackB)
{
	ra(stackA);
	ra(stackB);
}

void	rra(DblLinkedList **stackA)
{
	size_t	size;
	t_data	data;
	Node	*tmp;

	size = (*stackA)->size;
	if (size == 0 || size == 1)
		return ;
	data = deleteNth(*stackA, size - 1);
	data.pos_in_stack = 0;
	tmp = (*stackA)->head;
	while (tmp)
	{
		tmp->data.pos_in_stack++;
		tmp = tmp->next;
	}
	pushFront(*stackA, data);
}

void	rrb(DblLinkedList **stackB)
{
	size_t	size;
	t_data	data;
	
	size = (*stackB)->size;
	if (size == 0 || size == 1)
		return ;
	data = deleteNth(*stackB, size - 1);
	pushFront(*stackB, data);
}

void	rrr(DblLinkedList **stackA, DblLinkedList **stackB)
{
	rra(stackA);
	rrb(stackB);
}