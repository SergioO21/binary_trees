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
	int lh, rh, is_full, n_leaves;

	lh = rh = is_full = n_leaves = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lh = binary_tree_height(tree->left) + 1;

	if (tree->right)
		rh = binary_tree_height(tree->right) + 1;

	is_full = binary_tree_is_full(tree);
	n_leaves = binary_tree_leaves(tree);

	if ((lh - rh) == 0 && is_full == 1 && n_leaves == _pow(2, lh))
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


/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 *
 * @tree: pointer to the root node of the tree to count the number of leaves.
 *
 * Return: - Binary tree leaves.
 *         - If tree is NULL, returns (0).
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * _pow - returns the power of 2 size_t numbers.
 *
 * @x: First value.
 * @y: Second value.
 *
 * Return: Operation result.
 */

int _pow(int x, int y)
{
    if (y == 0)
        return (1);

    return (_pow(x, y - 1) * x);
}
