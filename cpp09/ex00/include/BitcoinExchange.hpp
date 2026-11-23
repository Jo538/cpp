/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 12:24:12 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>

class BitcoinExchange
{	
public:
	typedef std::multimap<std::string, float> ExchangeMap;
	enum Map {PRICE, FX};

	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange() {};

	BitcoinExchange& operator=(const BitcoinExchange& other);

	void parseMap(const std::string& file, Map type);

	ExchangeMap::const_iterator getPair(Map type) const;

private:
	ExchangeMap _fx;
	ExchangeMap _price;
	
};


#endif