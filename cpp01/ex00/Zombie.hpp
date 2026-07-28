/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:35:25 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 12:34:05 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
private:
	std::string name;	

public:	
	Zombie( std::string name );
	~Zombie( void );
	void announce( void );
};

void randomChump( std::string name);
Zombie* newZombie(std::string name);