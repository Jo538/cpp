/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:23:02 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 11:58:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
private:
	static const std::string TYPE;
public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();

	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};

#endif