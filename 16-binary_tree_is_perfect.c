#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: - If binary tree is perfect, returns (1), else (0).
 *         - If tree is NULL, your function must return (0).
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lh, rh, is_full;

	lh = rh = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lh = binary_tree_height(tree->left) + 1;

	if (tree->right)
		rh = binary_tree_height(tree->right) + 1;

	is_full = binary_tree_is_full(tree);

	if ((lh - rh) == 0 && is_full == 1)
		return (1);

	else
		return (0);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: - If binary tree is full, returns (1), else (0).
 *         - If tree is NULL, returns (0).
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
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
