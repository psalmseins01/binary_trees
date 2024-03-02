#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value in the tree and returns the node.
 * @tree: Tree to search through.
 * @value: Value to search for.
 *
 * Return: The node with the value or NULL if the value is not in the tree.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found_value;

	if (!tree)
		return (NULL);

	if (value < tree->n)
	{
		found_value = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found_value = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found_value);
}
