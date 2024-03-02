#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		int _left = 1, _right = 1;

		if (tree->right)
			_right +=  binary_tree_height(tree->right);
		if (tree->left)
			_left +=  binary_tree_height(tree->left);
		if (_left > _right)
			return (_left);
		else
			return (_right);
	}
	else
		return (0);
}
/**
 * binary_tree_balance - Calculates the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left)
		- binary_tree_height(tree->right));
}
