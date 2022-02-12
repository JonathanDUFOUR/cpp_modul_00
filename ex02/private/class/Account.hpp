// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#ifndef __ACCOUNT_H__
# define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account
{
private:
	// Attributes
	int			_accountIndex;
	int			_amount;
	int			_nbDeposits;
	int			_nbWithdrawals;

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	// Constructors
	Account(void);

	// Member functions
	static void	_displayTimestamp(void);

public:
	typedef Account	t;

	// Constructors
	Account(int initial_deposit);

	// Destructors
	~Account(void);

	// Accessors
	static inline int	getNbAccounts(void);
	static inline int	getTotalAmount(void);
	static inline int	getNbDeposits(void);
	static inline int	getNbWithdrawals(void);

	// Member functions
	void		makeDeposit(int const deposit);
	bool		makeWithdrawal(int const withdrawal);
	int			checkAmount(void) const;
	void		displayStatus(void) const;

	static void	displayAccountsInfos(void);
};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
