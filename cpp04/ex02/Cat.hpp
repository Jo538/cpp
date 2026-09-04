/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:07:18 by admin             #+#    #+#             */
/*   Updated: 2026/09/04 11:24:59 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
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

	const std::string &getIdea(int index) const;
	void setIdea(std::string idea, int index);
	
	void makeSound(void) const;
};

#endif