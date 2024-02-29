#include "binary_trees.h"

/**
 * bst_insert - Inserts value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL upon failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_value, *new_node;

	if (tree != NULL)
	{
		current_value = *tree;

		if (current_value == NULL)
		{
			new_node = binary_tree_node(current_value, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}

		if (value < current_value->n) /* insert in left subtree */
		{
			if (current_value->left != NULL)
				return (bst_insert(&current_value->left, value));

			new_node = binary_tree_node(current_value, value);
			if (new_node == NULL)
				return (NULL);
			return (current_value->left = new_node);
		}
		if (value > current_value->n) /* insert in right subtree */
		{
			if (current_value->right != NULL)
				return (bst_insert(&current_value->right, value));

			new_node = binary_tree_node(current_value, value);
			if (new_node == NULL)
				return (NULL);
			return (current_value->right = new_node);
		}
	}
	return (NULL);
}
