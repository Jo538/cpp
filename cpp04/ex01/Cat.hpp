/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:07:18 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 17:56:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	static const std::string TYPE;
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();

	Cat &operator=(const Cat &other);

	const std::string &getIdea(unsigned int index) const;
	void setIdea(std::string idea, unsigned int index);
	
	void makeSound(void) const;
};

#endif