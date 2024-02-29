#include "binary_trees.h"

/**
 * binary_tree_delete - Recursively frees an entire tree by freeing each node.
 * It frees a node when both its left and right children are NULL.
 *
 * @tree: Pointer to the root of the tree to be freed.
 * Return: return void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
