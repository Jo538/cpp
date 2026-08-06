/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:01:18 by admin             #+#    #+#             */
/*   Updated: 2026/08/06 18:06:40 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _is_guarded;
public:
	// Constructors
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &other);

	// Destructor
	~ScavTrap();

	// Overloaded Operations
	ScavTrap &operator=(const ScavTrap &other); 

	// Member Functions
	void attack(const std::string &target);
	void guardGate();
};

#endif