/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:23:02 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 15:16:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
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
	
	const std::string &getIdea(unsigned int index) const;
	void setIdea(std::string idea, unsigned int index);

	void makeSound(void) const;
};

#endif