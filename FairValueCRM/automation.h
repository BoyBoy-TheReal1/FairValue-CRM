#pragma once
#include <iostream>
#include "job.h"
#include "quotation.h"

//Pricing guardrails. Question 2.3

inline bool checkPricingGuardrails(double proposedPrice, double estimatedCost, double targetMargin)
{
	double actualMargin = 0.0;
	double  targetMarginPercentage = 0.0;

	//Guard clause to prevent numerical division by zero.
	if (proposedPrice <= 0)
	{
		return false;
	}

	//Calculate the actual margin of the proposed price.
	actualMargin = ((proposedPrice - estimatedCost) / proposedPrice) * 100;
	
	targetMarginPercentage = targetMargin * 100;

	//If the actual margin is lower than the target margin, it must be flagged!
	if (actualMargin < targetMarginPercentage)
	{
		std::cout << "[WARNING!] The price is below the target margin!" << std::endl;
		std::cout << "Target margin: " << targetMarginPercentage << "% | Actual margin: " << actualMargin << "%" << std::endl;

		//The proposed price failed the business rule.
		return false;
	}

	//The proposed price passed all the rules and is safe to offer.
	return true;
}

inline void detectCostOverrun(Job& myJob, double absoluteThreshold, double thresholdPercentage)
{
	double estimatedCost = myJob.getEstimatedJobCost();
	double actualCost = myJob.getActualJobCost();

	double variance = 0.0;
	double variancePercentage = 0.0;

	if (estimatedCost <= 0)
	{
		return;		//Safety check.
	}

	variance = actualCost - estimatedCost;
	variancePercentage = (variance / estimatedCost) * 100;

	//Evaluating against the absolute threshold or the percentage threshold.
	if (variance >= absoluteThreshold || variancePercentage >= thresholdPercentage)
	{
		std::cout << "\n[ALERT!] COST OVERRUN DETECTED FOR JOB " << myJob.getJobNumber() << "!" << std::endl;

		std::cout << "Estimated cost: R" << estimatedCost << " | Actual cost: R" << actualCost << std::endl;

		std::cout << "Variance: R" << variance << " (" << variancePercentage << "%)" << std::endl;

		std::cout << "Action: Review task created for management." << std::endl;

	}
}

inline void processQuotationFollowUp(Quotation& myQuote, int daysLapsedSinceSent, int daysAccordingToPolicy, bool hasExistingTask)
{
	//Guard clauses from the algorithm in the brief.
	if (myQuote.getQuotationStatus() != "Pending")
	{
		return;		//Do nothing if the status is already Accepted or Rejected.
	}

	//Why three days? In business, I don't want to seem desparate or spam the client.
	//
	if (daysLapsedSinceSent < daysAccordingToPolicy)		//Three days gives the client enough time without feeling pressured.
	{
		return;		//Do nothing yet.
	}

	if (hasExistingTask)
	{
		//Duplicate action prevented (idemptency).
		std::cout << "[SYSTEM] Lodged follow-up already exists for Quotation " << myQuote.getQuotationNumber() << ". Skipping" << std::endl;

		return;
	}

	//If all checks are passed, create the task!
	std::cout << "\n[AUTOMATION] Follow-up due for Quotation " << myQuote.getQuotationNumber() << " (Job " << myQuote.getJobLinkedToQuotation() << ")" << std::endl;

	std::cout << "Action: Drafting a follow-up message for the customer." << std::endl;
}
