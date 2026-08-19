/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:31:34 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 14:40:25 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	printf("5: %d\n", chunk_size(5));
	printf("10: %d\n", chunk_size(10));
	printf("16: %d\n", chunk_size(16));
	printf("20: %d\n", chunk_size(20));
	printf("50: %d\n", chunk_size(50));
	return (0);
}
