/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:23:02 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 15:24:15 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	static const std::string TYPE;
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();

	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};

#endif