/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:44:52 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 17:19:11 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon _weapon;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA();
	void attack() const;
};