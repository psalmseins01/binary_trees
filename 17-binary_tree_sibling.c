#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling node of a given node.
 * @node: The node to check.
 *
 * Return: The sibling node, or NULL if no sibling exists.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
