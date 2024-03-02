#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int lft, rht;

		if (tree->right)
			rht = 1 + binary_tree_height(tree->right);
		if (tree->left)
			lft = 1 + binary_tree_height(tree->left);
		if (lft > rht)
			return (lft);
		else
			return (rht);
	}
	else
		return (0);
}
/**
 * print_at_level - Prints nodes at a specific level.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Level at which to print nodes.
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = 0, i = 1;

	if (tree && func)
	{
		h = binary_tree_height(tree);
		while (i <= h + 1)
		{
			print_at_level(tree, func, i);
			i++;
		}
	}

}
