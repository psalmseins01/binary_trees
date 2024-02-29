#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determines whether a node is a leaf,
 * meaning it has no left or right child.
 * @node: The node to analyze.
 * Return: 1 if it is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
