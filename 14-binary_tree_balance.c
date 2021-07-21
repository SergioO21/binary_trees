#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: - Balance factor of the tree.
 *         - If tree is NULL, return (0).
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	lh = rh = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lh = binary_tree_height(tree->left) + 1;

	if (tree->right)
		rh = binary_tree_height(tree->right) + 1;

	return (lh - rh);
}


/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: - Binary tree height.
 *         - If tree is NULL, returns (0).
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	if (binary_tree_height(tree->left) > binary_tree_height(tree->right))
		return (binary_tree_height(tree->left) + 1);

	else
		return (binary_tree_height(tree->right) + 1);
}
