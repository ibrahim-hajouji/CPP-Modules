/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:42:13 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/05 22:35:30 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class   AMateria
{
    protected:
        std::string type;
    
    public:
        AMateria(std::string const &type);
        AMateria(AMateria const &src);
        AMateria const &operator=(AMateria const &src);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria    *clone() const = 0;
        virtual void    use(ICharacter &target) = 0;
};



#endif