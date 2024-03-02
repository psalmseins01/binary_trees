#include "binary_trees.h"

/**
 * tree_is_perfect - Determines if a tree is perfect or not.
 * A perfect tree must have the same number of levels on the left and right,
 * and each node must have either two children or none.
 * @tree: The tree to check.
 *
 * Return: 0 if the tree is not perfect, otherwise returns the height level.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int lft, rht;

	if (tree->left && tree->right)
	{
		lft = 1 + tree_is_perfect(tree->left);
		rht = 1 + tree_is_perfect(tree->right);
		if (rht == lft && rht != 0 && lft != 0)
			return (rht);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - Checks if a tree is perfect or not.
 * A perfect tree must have the same number of levels on the left and right,
 * and each node must have either two children or none.
 * @tree: The tree to check.
 *
 * Return: 1 if the tree is perfect, 0 if it is not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int _result;

	if (!tree)
	{
		return (0);
	}
	else
	{
		_result = tree_is_perfect(tree);
		if (_result != 0)
		{
			return (1);
		}
		return (0);
	}
}
