/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/22 17:19:06 by admin            ###   ########.fr       */
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
	ExchangeMap fx;
	ExchangeMap price;
	
};

// I want to read a pair inside my multimap. 
// How?
// Return a const ref to multimap? Think I can't
// Return an iterator pointing to the pair? Think best

#endif