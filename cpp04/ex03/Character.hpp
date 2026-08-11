/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:56:32 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 19:21:02 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	static const unsigned int SIZE_INVENTORY = 4;
	AMateria *_inventory[SIZE_INVENTORY];
public:
	Character();
	Character(const std::string _name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};