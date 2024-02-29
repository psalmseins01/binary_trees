#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node to the left of the parent.
 * If the left child already exists, it moves down one level and adds
 * the new node as the left child.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 * Return: Pointer to the new node if successful, otherwise NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	n_node = binary_tree_node(parent, value);
	if (n_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		n_node->left = parent->left;
		parent->left->parent = n_node;
	}
	parent->left = n_node;
	return (n_node);
}
