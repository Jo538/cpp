/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:54 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 12:11:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
private:
	static const std::string DEFAULT_TYPE;
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	virtual ~Animal();
	
	Animal &operator=(const Animal &other);

	const std::string &getType(void) const;
	
	virtual void makeSound(void) const;

	static const int ANIMAL_COUNT = 2;
};

#endif