/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/20 18:22:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>

class BitcoinExchange
{
private:
	typedef std::multimap<std::string, float> ExchangeMap;
	
	ExchangeMap fx;
	ExchangeMap price;
	
public:
	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& other) : fx(other.fx), price(other.price) {};
	~BitcoinExchange() {};

	BitcoinExchange& operator=(const BitcoinExchange& other) { fx = other.fx; price = other.price; return *this;};
	 
};

#endif