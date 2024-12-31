/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:56:19 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/04 22:59:21 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
		Ice();
		Ice(Ice const &src);
		Ice const &operator=(Ice const &src);
		~Ice();
		
		virtual AMateria	*clone() const;
		virtual void	use(ICharacter &target);
};

#endif
