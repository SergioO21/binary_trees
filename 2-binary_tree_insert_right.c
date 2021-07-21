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
	binary_tree_t *new_node, *tmp;

	if (!parent)
		return (NULL);

	tmp = parent;
	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	while (tmp)
	{
		if (value > tmp->n)
		{
			if (tmp->right)
				tmp = tmp->right;

			else
			{
				tmp->right = new_node;
				new_node->parent = tmp;
				break;
			}
		}

		else
		{
			new_node->right = tmp;
			new_node->parent = tmp->parent;
			tmp->parent->right = new_node;
			tmp->parent = new_node;
			break;
		}
	}
	return (new_node);
}
