#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in @array
 * Return: NULL upon failure or pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *bin_tree = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&bin_tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (bin_tree);
}
