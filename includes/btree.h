/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:13:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/16 11:14:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include "libft.h"

typedef struct s_btree		t_btree;

struct	s_btree
{
	void			*item;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
};

t_btree	*btree_create_node(void const *item, size_t content_size);

void	btree_insert_data(
		t_btree **root,
		void *item,
		size_t content_size,
		int (*cmpf)(void *, void *));

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *));

int		btree_level_count(t_btree *root);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_print(t_btree *tree, void (*printer)(t_btree *tree));

#endif