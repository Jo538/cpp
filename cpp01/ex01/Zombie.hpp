/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:53:18 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 16:12:23 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	int 		_index;
	std::string _name;
public:
	Zombie();
	~Zombie();
	void announce() const;
	void setName(std::string name);
	void setIndex(int index);
};

Zombie* zombieHorde(int N, std::string name);

#endif
