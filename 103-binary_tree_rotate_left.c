#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left rotates a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 * Return: A pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotate_factor, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	rotate_factor = tree->right;
	temp = rotate_factor->left;
	rotate_factor->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = rotate_factor;
	rotate_factor->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = rotate_factor;
		else
			temp->right = rotate_factor;
	}

	return (rotate_factor);
}
