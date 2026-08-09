/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:07:18 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:30:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	static const std::string TYPE;
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &other);

	void makeSound(void) const;
};

#endif