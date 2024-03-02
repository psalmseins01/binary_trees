#include "binary_trees.h"

/**
 * array_to_bst - Turns an array into a Binary Search Tree (BST).
 * @array: Array to be turned into a BST tree.
 * @size: Size of the array.
 *
 * Return: BST tree created from the array.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t idx = 0;
	bst_t *root;

	root = NULL;
	if (!size)
	{
		return (NULL);
	}
	for (; idx < size; idx++)
	{
		if (idx == 0)
		{
			bst_insert(&root, array[idx]);
		}
		else
		{
			bst_insert(&root, array[idx]);
		}
	}
	return (root);
}
