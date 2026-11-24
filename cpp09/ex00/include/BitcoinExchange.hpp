/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/24 19:28:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>

class BitcoinExchange
{	
public:
	typedef std::multimap<std::string, float> ExchangeMap;
	typedef ExchangeMap::const_iterator const_it;
	
	enum Map {PRICE, FX};

	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange() {};

	BitcoinExchange& operator=(const BitcoinExchange& other);

	void parseMap(const std::string& file, Map type);
	void parsePair(std::string& line, Map type);
	void print();

private:
	ExchangeMap _fx;
	ExchangeMap _price;

	bool isGoodInput(const_it& itPrice);
	bool isLeapYear(const_it& itPrice);
	bool hasRightDateFormat(const_it& itPrice);
	void format(const_it& itPrice, const_it& itFX);
	float product(const_it& itPrice, const_it& itFX) const;
	
};


#endif