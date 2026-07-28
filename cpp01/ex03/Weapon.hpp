/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:37:05 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 17:36:47 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	//~Weapon();
	const std::string &getType();
	void setType(std::string type);
};