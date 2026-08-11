/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:09:35 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 18:48:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	static const std::string TYPE;
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target)
};