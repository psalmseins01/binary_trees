#include "binary_trees.h"

/**
 * binary_tree_nodes - Returns the number of nodes in a tree with children.
 * @tree: Tree to check.
 * Return: Number of nodes with children.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
		return  (1 + binary_tree_nodes(tree->right) +
			 binary_tree_nodes(tree->left));
	return (0);
}
