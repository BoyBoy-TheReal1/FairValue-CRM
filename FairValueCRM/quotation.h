#pragma once
#include <string>
#include <cctype>			//For toupper.
#include <stdexcept>

class Quotation
{
	private:
		int quotationNumber;
		int jobLinkedToQuotation;
		double proposedQuotationPrice;
		std::string lineItems;
		std::string quotationValidityDate;
		std::string quotationStatus;
		double itemTaxRate;				//Tax treatment.
		double itemAdjustments;			//Discounts or extra fees.

	public:
		Quotation();
		Quotation(int, int, double, std::string, std::string, double);

		//Getters.
		int getQuotationNumber() const;
		int getJobLinkedToQuotation() const;
		double getProposedQuotationPrice() const;
		std::string getQuotationStatus() const;
		
		double getItemTaxRate() const;
		double getItemAdjustments() const;

		std::string getQuotationValidityDate() const;


		//Controlled update.
		void quotationUpdateStatus(std::string);

};

inline Quotation::Quotation()
{
	quotationNumber = 0;
	jobLinkedToQuotation = 0;
	proposedQuotationPrice = 0.0;
	quotationStatus = "Pending";
	itemTaxRate = 0.0;
	itemAdjustments = 0.0;
}

inline Quotation::Quotation(int quoteId, int jobLinkedToQuote, double quotePrice, std::string currentQuoteStatus, std::string validityDate, double taxTreatment)
{
	//Ensuring the quotation and job ID numbers are valid positive values.
	if (quoteId <=0 || jobLinkedToQuote <=0)
	{
		throw std::invalid_argument("ID numbers must be greater than zero.");
	}

	//Ensuring the proprosed price is not a negative amount.
	if (quotePrice < 0)
	{
		throw std::invalid_argument("The price on the quotation must be positive");
	}

	//Assigning by saving the validated data into the private variables.
	quotationNumber = quoteId;
	jobLinkedToQuotation = jobLinkedToQuote;
	proposedQuotationPrice = quotePrice;
	quotationValidityDate = validityDate;
	itemTaxRate = taxTreatment;
	itemAdjustments = 0.0;		//Since there is no parameter for it, it is set to 0.0.

	if (!currentQuoteStatus.empty())				//Checking the first letter of the case-insensitve status to standardise it.
	{
		switch (toupper(currentQuoteStatus[0]))
		{
		case 'P':
			quotationStatus = "Pending";
			break;

		case 'A':
			quotationStatus = "Accepted";
			break;

		case 'R':
			quotationStatus = "Rejected";
			break;

		//To handle any typos, empty strings, or any invalid input safely.
		default:
			quotationStatus = "Pending";
			break;
		}
	}

	//Should the user completely passes an empty string, the switch statement is skipped entirely and has pending as a default.
	else
	{
		quotationStatus = "Pending";
	}
}


/*int getQuotationNumber() const;
		int getJobLinkedToQuotation() const;
		double getProposedQuotationPrice() const;
		std::string getQuotationStatus() const;*/
inline int Quotation::getQuotationNumber() const
{
	return quotationNumber;
}

inline int Quotation::getJobLinkedToQuotation() const
{
	return jobLinkedToQuotation;
}

inline double Quotation::getProposedQuotationPrice() const
{
	return proposedQuotationPrice;
}

inline std::string Quotation::getQuotationStatus() const
{
	return quotationStatus;
}


inline double Quotation::getItemTaxRate() const
{
	return itemTaxRate;
}

inline double Quotation::getItemAdjustments() const
{
	return itemAdjustments;
}

inline std::string Quotation::getQuotationValidityDate() const
{
	return quotationValidityDate;
}

inline void Quotation::quotationUpdateStatus(std::string newQuotationStatus)
{
	switch (toupper(newQuotationStatus[0]))
	{
	case 'P':
		quotationStatus = "Pending";
		break;

	case'A':
		quotationStatus = "Accepted";
		break;

	case 'R':
		quotationStatus = "Rejected";
		break;

	default:

		//Throw an exception, should the user type 'X'.
		throw std::invalid_argument("Invalid status of quote. Quote must be Pending, Accepted, or Rejected.");
		break;
	}
}