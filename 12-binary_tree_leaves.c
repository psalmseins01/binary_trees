#include "binary_trees.h"

/**
 * binary_tree_leaves - Returns the number of leaves in a tree.
 * @tree: Tree to check.
 * Return: Number of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf, lft, rht;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lft = binary_tree_leaves(tree->left);
		rht = binary_tree_leaves(tree->right);
		leaf = lft + rht;
		return ((!lft && !rht) ? leaf + 1 : leaf + 0);
	}
}
