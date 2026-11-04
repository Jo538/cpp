/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:07:01 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 16:50:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
private:
	std::string name;
	std::string breed;
	int age;
public:	
	Data();
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	// Getters
	const std::string& getName();
	const std::string& getBreed();
	int getAge();
};


#endif