/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:54 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:27:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal
{
private:
	static const std::string DEFAULT_TYPE;
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();
	
	WrongAnimal &operator=(const WrongAnimal &other);

	const std::string &getType(void) const;
	
	virtual void makeSound(void) const;
};

#endif