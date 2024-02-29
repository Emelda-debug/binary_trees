#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: NULL if no common ancestors, else return common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor_1, *ancestor_2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	ancestor_1 = first->parent, ancestor_2 = second->parent;
	if (first == ancestor_2 || !ancestor_1 || (!ancestor_1->parent && ancestor_2))
		return (binary_trees_ancestor(first, ancestor_2));
	else if (ancestor_1 == second || !ancestor_2 ||
			(!ancestor_2->parent && ancestor_1))
		return (binary_trees_ancestor(ancestor_1, second));
	return (binary_trees_ancestor(ancestor_1, ancestor_2));
}
