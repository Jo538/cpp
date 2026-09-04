/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:23:02 by admin             #+#    #+#             */
/*   Updated: 2026/09/04 10:22:26 by jchartie         ###   ########.fr       */
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
	
	const std::string &getIdea(int index) const;
	void setIdea(std::string idea, int index);

	void makeSound(void) const;
};

#endif