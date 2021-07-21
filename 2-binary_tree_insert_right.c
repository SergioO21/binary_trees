#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the
 *                            right-child of another node.
 *
 * @parent: Pointer to the parent node of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: A pointer to the created node,
 *         or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->right)
	{
		new_node->parent = parent;
		new_node->right = parent->right;
		parent->right = new_node;
	}
	else
	{
		parent->right = new_node;
		new_node->right = NULL;
	}
	return (new_node);
}
