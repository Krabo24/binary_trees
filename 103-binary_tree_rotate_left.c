#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left child of root becomes new root, tree rotated
 * so it retains BST ordering of values
 * @tree: tree to left rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->right;

	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}
