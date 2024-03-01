#include "binary_trees.h"

/**
 * binary_tree_size - Computes the size of a binary tree.
 * @tree: Pointer to the root node of the tree to calculate the size of.
 * Return: Returns 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size, rht, lft;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lft = binary_tree_size(tree->left);
		rht = binary_tree_size(tree->right);
		size = 1 + rht + lft;
	}
	return (size);
}
