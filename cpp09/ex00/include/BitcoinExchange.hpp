/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 16:08:48 by jchartie         ###   ########.fr       */
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
	void parsePair(std::ifstream& inFile, Map type);
	void print();
	void format(const_it& itPrice, const_it& itFX);

private:
	ExchangeMap _fx;
	ExchangeMap _price;

	float product(const_it& itPrice, const_it& itFX) const;
	
};


#endif