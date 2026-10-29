#pragma once
#include <iostream>
#include <string>
#include <stdexcept>	//For throwing exceptions.

class Customer
{
	//Private data members that are only accessible within this class.
	private:
		long long customerId;
		std::string customerName;
		std::string customerSurname;
		std::string customerContactDetails;		//Can be e-mail or phone number.
		std::string customerStatus;				//Is the customer active or inactive, or blacklisted?
		bool optedOutOfMarketing;				//Real CRM systems need to track consent for privacy (POPIA).

	public:

		//Default constructor.
		Customer();	//To create an empty customer--useful for file loading later.
		
		//Default overloaded constructor.
		Customer(long long, std::string, std::string, std::string);	//To create a fully formed customer.

		//Getters.
		//All constant so as not to change the data. Just to return the validated data.
		long long getCustomerId() const;
		std::string getCustomerName() const;
		std::string getCustomerSurname() const;
		std::string getCustomerContactDetails() const;
		std::string getCustomerStatus() const;
		bool hasOptedOut() const;
	
		//Controlled update methods.
		void updateOnCustomerContactDetails(std::string);
		void updateOnCustomerStatus(std::string);
		void optOutOfMarketing();

};

//Defining the default constructor.
inline Customer::Customer()
{
	customerId = 0;
	customerName = "";
	customerSurname = "";
	customerContactDetails = "";
	customerStatus = "Active";
	optedOutOfMarketing = false;
}

//Defining the default overloaded constructor.
inline Customer::Customer(long long identityNumber, std::string nameOfCustomer, std::string surnameOfCustomer, std::string contactInformation)
{
	//Data validation. 
	
	//Exceptions thrown. To stop the programme if someone tries to create a "bad" customer.
	if (identityNumber <= 0)
	{
		throw std::invalid_argument("Customer ID must be greater than zero.");
	}

	if (nameOfCustomer.empty() && surnameOfCustomer.empty())
	{
		throw std::invalid_argument("Customer name and customer surname cannot be empty.");
	}

	customerId = identityNumber;
	customerName = nameOfCustomer;
	customerSurname = surnameOfCustomer;
	customerContactDetails = contactInformation;
	customerStatus = "Active";				//Default set to "Active."
	optedOutOfMarketing = false;			//Default set to false if the customer has opted out.
}

//Returning the customer's ID number.
inline long long Customer::getCustomerId() const
{
	return customerId;
}

//Returning the customer's first name.
inline std::string Customer::getCustomerName() const
{
	return customerName;
}

inline std::string Customer::getCustomerSurname() const
{
	return customerSurname;
}

inline std::string Customer::getCustomerContactDetails() const
{
	return customerContactDetails;
}

inline std::string Customer::getCustomerStatus() const
{
	return customerStatus;
}
//Returning a true value if the customer has opted out of marketing.
inline bool Customer::hasOptedOut() const
{
	return optedOutOfMarketing;
}

//Controlled update methods.
inline void Customer::updateOnCustomerContactDetails(std::string newContactInformation)
{
	if (newContactInformation.size() > 0)
	{
		customerContactDetails = newContactInformation;
	}
}

inline void Customer::updateOnCustomerStatus(std::string newCustomerStatus)
{
	if (newCustomerStatus.length() > 0)
	{
		switch (toupper(newCustomerStatus.at(0)))
		{
		case 'A':
			customerStatus = "Accepted";
			break;

		case 'I':
			customerStatus = "Inactive";
			break;

		case 'B':
			customerStatus = "Blacklisted";
			break;

		default:
			throw std::invalid_argument("Invalid customer status. Status must either be Active, Inactive, or Blacklisted.");
			break;
		}

	}

	else
	{
		throw std::invalid_argument("Customer status cannot be empty.");

	}
	customerStatus = newCustomerStatus;
}

inline void Customer::optOutOfMarketing()
{
	optedOutOfMarketing = true;
}