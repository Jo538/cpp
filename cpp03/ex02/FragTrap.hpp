/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:46:54 by admin             #+#    #+#             */
/*   Updated: 2026/08/06 20:06:04 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
	// Constructor
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &other);

	// Destructor
	~FragTrap();

	// Overload Operator
	FragTrap &operator=(const FragTrap &other);

	// Member Functions
	void highFiveGuys(void);
};

#endif