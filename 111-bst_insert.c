#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Always 0 (Success).
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	if (value < tmp->n)
	{
		if (!(tmp->left))
		{
			tmp->left = binary_tree_node(tmp, value);
			return (tmp->left);
		}
		return (bst_insert(&(tmp->left), value));
	}
	if (value > tmp->n)
	{
		if (tmp->right == NULL)
		{
			tmp->right = binary_tree_node(tmp, value);
			return (tmp->right);
		}
		return (bst_insert(&(tmp->right), value));
	}
	return (NULL);
}
