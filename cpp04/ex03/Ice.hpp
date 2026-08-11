/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:49:10 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 19:17:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	static const std::string TYPE;
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};