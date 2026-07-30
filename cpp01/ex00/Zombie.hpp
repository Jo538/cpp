/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:35:25 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/30 16:59:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string _name;	

public:	
	Zombie( std::string name );
	~Zombie( void );
	void announce( void );
};

void randomChump( std::string name);
Zombie* newZombie(std::string name);

#endif