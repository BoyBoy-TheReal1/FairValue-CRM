#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "customer.h"

class Job
{
	//Private data members.
	private:
		int jobNumber;
		long long customerId;	//Must match the Customer's ID type.
		std::string jobDescription;
		std::string jobScope;			//What is exaclty being done.
		std::string jobStartDate;		//E.g. 2006-05-19
		std::string jobEndDate;			//E.g. 2006-06-10
		std::string jobStatus;			//"Work-in-progress" and "Complete".
		std::string assignedStaff;		//Who's doing the job linked to the item.
		double estimatedJobCost;
		double actualJobCost;
		
	public:
		Job();
		Job(int, long long, std::string, std::string, std::string, std::string, std::string, std::string, double);

		//Getters.
		int getJobNumber() const;
		long long getCustomerId() const;
		std::string getJobDescription() const;
		std::string getJobScope() const;
		std::string getJobStartDate() const;
		std::string getJobEndDate() const;
		std::string getJobStatus() const;
		std::string getAssignedStaff() const;
		double getEstimatedJobCost() const;
		double getActualJobCost() const;
		
		//Controlled update.
		void setActualJobCost(double);
		void updateOnJobStatus(std::string);

};

inline Job::Job()
{
	//Giving default values to the private data members.
	jobNumber = 0;
	customerId = 0;
	jobDescription = "";
	jobScope = "";
	jobStartDate = "";
	jobEndDate = "";
	jobStatus = "Draft";
	assignedStaff = "";
	estimatedJobCost = 0.0;
	actualJobCost = 0.0;
}

inline Job::Job(int jobId, long long customerIdentityNumber, std::string descriptionOfJob, std::string scopeOfJob, std::string startDate, std::string endDate, std::string statusOfJob, std::string staffAssigned, double estimatedCostOfJob)
{
	//Job validation for the job to have a valid job number to a valid customer.
	if (jobId <= 0)
	{
		throw std::invalid_argument("Job ID must be greater than zero.");
	}

	if (customerIdentityNumber <= 0)
	{
		throw std::invalid_argument("Job must be liked to a valid customer identity number.");
	}

	if (estimatedCostOfJob < 0)
	{
		throw std::invalid_argument("Estimated cost cannot be negative.");
	}

	jobNumber = jobId;
	customerId = customerIdentityNumber;
	jobDescription = descriptionOfJob;
	jobScope = scopeOfJob;
	jobStartDate = startDate;
	jobEndDate = endDate;
	jobStatus = "Draft";
	assignedStaff = staffAssigned;
	estimatedJobCost = estimatedCostOfJob;
	actualJobCost = 0.0;	//Job cost starts at R0 until the work is finished.
}

inline int Job::getJobNumber() const
{
	return jobNumber;
}

inline long long Job::getCustomerId() const
{
	return customerId;
}

inline std::string Job::getJobDescription() const
{
	return jobDescription;
}

inline std::string Job::getJobScope() const
{
	return jobScope;
}

inline std::string Job::getJobStartDate() const
{
	return jobStartDate;
}

inline std::string Job::getJobEndDate() const
{
	return jobEndDate;
}

inline std::string Job::getJobStatus() const
{
	return jobStatus;
}

inline std::string Job::getAssignedStaff() const
{
	return assignedStaff;
}

inline double Job::getEstimatedJobCost() const
{
	return estimatedJobCost;
}

inline double Job::getActualJobCost() const
{
	return actualJobCost;
}

//Controlled update methods.

//Controlled update method for the Actual Job Cost.
inline void Job::setActualJobCost(double determinedCost)
{
	if (determinedCost >= 0)
	{
		actualJobCost = determinedCost;
	}
}
//Controlled update method for the Job Status.
inline void Job::updateOnJobStatus(std::string newJobStatus)
{
	//Validation of status to ensure that the status is not an empty string.
	if (!newJobStatus.empty())
	{
		jobStatus = newJobStatus;
	}
}