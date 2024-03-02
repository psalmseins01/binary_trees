#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: The first node.
 * @second: The second node.
 *
 * Return: Pointer to the lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t height_f_node = 0, height_s_node = 0;
	const binary_tree_t *aux = NULL;

	height_f_node = binary_tree_depth(first);
	height_s_node = binary_tree_depth(second);
	if (height_f_node && height_s_node)
	{
		if (height_f_node > height_s_node)
		{
			aux = first;
			first = second;
			second = aux;
		}
		while (first)
		{
			aux = second;
			while (aux)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
