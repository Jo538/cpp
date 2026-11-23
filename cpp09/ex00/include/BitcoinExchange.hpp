/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 11:57:50 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>

class BitcoinExchange
{	
public:
	typedef std::multimap<std::string, float> ExchangeMap;
	
	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange() {};

	BitcoinExchange& operator=(const BitcoinExchange& other);

	void parsePrices(const std::string& priceFile);
	void parseFx();

	ExchangeMap::const_iterator getExchangePair() const;

private:
	ExchangeMap _fx;
	ExchangeMap _price;
	
};


#endif