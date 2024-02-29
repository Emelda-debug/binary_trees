#include "binary_trees.h"

/**
 * binary_tree_uncle - Find node uncle in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: NULL if node is NULL or has no uncle
 *         Otherwise return a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
