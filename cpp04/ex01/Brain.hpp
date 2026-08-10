/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:05:09 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 17:56:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
private:
	static const int IDEAS_COUNT = 100;
	std::string _idea[IDEAS_COUNT];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(std::string &idea, unsigned int index);
	const std::string &getIdea(unsigned int index) const;
};

#endif