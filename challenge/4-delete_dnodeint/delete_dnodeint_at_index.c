#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	/* go to index */
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	if (tmp == NULL)
		return (-1);

	/* if deleting head */
	if (tmp->prev == NULL)
		*head = tmp->next;
	else
		tmp->prev->next = tmp->next;

	/* fix next node */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
