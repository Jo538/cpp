/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:51:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/24 20:29:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>

class BitcoinExchange
{
public:
	/* ---------------------------- Types ----------------------------- */

	typedef std::multimap<std::string, float>	ExchangeMap;
	typedef ExchangeMap::const_iterator			const_it;

	enum Map {PRICE, FX};

	/* ------------------- Orthodox Canonical Form -------------------- */

	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange() {};

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	/* -------------------------- Interface --------------------------- */

	int	parseMap(const std::string& file, Map type);
	void	print();

private:
	/* ----------------------------- Data ----------------------------- */

	ExchangeMap	_fx;
	ExchangeMap	_price;
	static const int PADDING = 12;

	/* --------------------------- Parsing ---------------------------- */

	void	parsePair(const std::string& line, Map type);

	/* -------------------------- Validation -------------------------- */

	bool	isGoodInput(const_it& itPrice);
	bool	isLeapYear(const_it& itPrice);
	bool	hasRightDateFormat(const_it& itPrice);

	/* --------------------------- Output ----------------------------- */

	void	format(const_it& itPrice, const_it& itFX);
	double	product(const_it& itPrice, const_it& itFX) const;
};

#endif
