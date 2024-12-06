/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:58:27 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/04 22:59:14 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
		Cure();
		Cure(Cure const &src);
		Cure const &operator=(Cure const &src);
		~Cure();
		
		virtual AMateria	*clone() const;
		virtual void	use(ICharacter &target);
};

#endif
