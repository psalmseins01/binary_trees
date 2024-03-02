#include "binary_trees.h"

/**
 * new_node - Creates a new node in a linked list.
 * @node: Type pointer of node to be created.
 *
 * Return: The node created.
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new_node;

	new_node =  malloc(sizeof(link_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}
/**
 * free_q - Frees the nodes in a linked list.
 * @head: Node of the linked list.
 */
void free_q(link_t *head)
{
	link_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * _push - Pushes a node into the stack.
 * @node: Type pointer of node of the tree.
 * @head: Type head node of the stack.
 * @tail: Type tail node of the stack.
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *_new_node;

	_new_node = new_node(node);
	if (_new_node == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = _new_node;
	*tail = _new_node;
}
/**
 * _pop - Pops a node from the stack.
 * @head: Type head node of the stack.
 */
void _pop(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}
/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Type pointer of node of the tree.
 *
 * Return: 1 if the tree is complete, 0 if it is not.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
