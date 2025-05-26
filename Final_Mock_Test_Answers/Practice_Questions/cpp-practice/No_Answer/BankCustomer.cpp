#include "BankCustomer.h"

//Instantiate new customer with default accounts
BankCustomer::BankCustomer(string first_name, string last_name){

}

//Instantiate new customer with defined accounts
BankCustomer::BankCustomer(string first_name, string last_name, double init_savings_balance, double monthly_savings_interest_rate){

}

//Define parameters of current savings account (does not create new checking account)
void BankCustomer::define_savings(double init_savings_balance, double monthly_savings_interest_rate){

}

//Returns string containing first and last name separated by a space
string BankCustomer::get_customer_name(void){

}

//Returns total balance savings account
double BankCustomer::query_savings_balance(void){

}

//Deposits amount into savings (assume amount is positive)
void BankCustomer::operator + (const double& amount){

}

/* Withdraw amount from savings.  Return true if successful.
   If insuffient funds, completely deny charge and return false;
*/
bool BankCustomer::operator - (const double& amount){

}

//Adds interest to savings account = savings*interest_rate
void BankCustomer::add_interest(void){

}