#include "binary_trees.h"

/**
 * check_sub_tree_Left - Checks if all nodes are smaller than or equal to
 * the specified root value.
 * @node: The node in the tree to verify the condition.
 * @max: The value to compare.
 *
 * Return: 1 if all nodes are smaller or equal, 0 if not.
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int lft, rht;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lft = check_sub_tree_Left(node->left, max);
		rht = check_sub_tree_Left(node->right, max);
		if (lft == rht && lft == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - Checks if all nodes in the subtree are greater
 * than or equal to
 * the specified root value.
 * @node: The node in the subtree to verify the condition.
 * @min: The value to compare.
 *
 * Return: 1 if all nodes are greater or equal, 0 if not.
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int lft, rht;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		lft = check_sub_tree_Right(node->left, min);
		rht = check_sub_tree_Right(node->right, min);
		if (lft == rht && lft == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - Determines if a tree is a binary
 * search tree (BST) or not.
 * The process involves first verifying that the left node
 * is smaller than the root,
 * then verifying if the right node is bigger than the root.
 * After that, it checks if the left subtree has nodes smaller than the root
 * and if the right subtree has nodes bigger than the root.
 * @tree: Node that points to the tree to check.
 *
 * Return: 1 if it is a BST, 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
