/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:54 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 15:33:43 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class Animal
{
private:
	static const std::string DEFAULT_TYPE;
protected:
	std::string _type;
	Animal(std::string type);
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	
	Animal &operator=(const Animal &other);

	const std::string &getType(void) const;
	
	virtual void makeSound(void) const = 0;
};

#endif