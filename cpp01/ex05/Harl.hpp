/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:30:12 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/30 09:49:10 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
private:
	static const int WORD_COUNT = 4; 
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	void complain(std::string level);
};

#endif