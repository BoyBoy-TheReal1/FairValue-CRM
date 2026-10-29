// FairValueCRM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "costing.h"
#include "money.h"
#include <cstdlib>
#include <iomanip>

//Include stage 2.
#include "customer.h"
#include "job.h"
#include "quotation.h"
#include "serviceEvent.h"
#include "automation.h"
#include "costItem.h"

using namespace std;

int main()
{
    cout << "= = = = = = COSTING ENGINE TEST = = = = = =" << endl;

    //Question 5.2
    //1. Inputs

    double labourHours = 3.0;
    double labourCostPerHour = 150.00;
    double estimatedMaterialsCost = 250.00;
    double otherDirectCosts = 0.0;
    double allocatedOverheadCosts = 100.00;

    double sellingPriceBeforeTax = 0.0;
    double targetMargin = 0.25; //25%

    //2. Calc
    double estimatedLabourCost = 0.0;
    double estimatedTotalCost = 0.0;


    double expectedContribution = 0.0;
    double expectedMContributionMargin = 0.0; //to be divided by 100
    double markupOnEstimatedCosts = 0.0;  //Div by 100

    double estimatedDirectCost = 0.0;

    estimatedLabourCost = calculateLabourCost(labourHours, labourCostPerHour);

    estimatedTotalCost = calculateEstimatedCost(estimatedLabourCost, estimatedMaterialsCost, otherDirectCosts, allocatedOverheadCosts);

    sellingPriceBeforeTax = calculateTargetPrice(estimatedTotalCost, targetMargin);

    //Profit or contribution
    expectedContribution = sellingPriceBeforeTax - estimatedTotalCost;

    expectedMContributionMargin = calculateContributionMargin(sellingPriceBeforeTax, estimatedTotalCost);

    markupOnEstimatedCosts = calculateMarkup(sellingPriceBeforeTax, estimatedTotalCost);


    //ACTUAL COSTS.
    double actualLabourCost = 525.00;
    double actualMaterialsCost = 280.00;
    double actualOtherDirectCosts = 45.00;
    double actualManufacturingOverhead = 100.00;

    double actualTotalCost = 0.0;

    actualTotalCost = calculateEstimatedCost(actualLabourCost, actualMaterialsCost, actualOtherDirectCosts, actualManufacturingOverhead);

    //Variance calculation.
    double costVariance = 0.0;

    costVariance = actualTotalCost - estimatedTotalCost;


    double actualContribution = 0.0;
    double actualContributionMargin = 0.0;

    actualContribution = sellingPriceBeforeTax - actualTotalCost;
    actualContributionMargin = calculateContributionMargin(sellingPriceBeforeTax, actualTotalCost);


    cout << setiosflags(ios::fixed) << setprecision(2);

    cout << "= = = = = = ESTIMATED JOB COSTS = = = = = =\n" << endl;

    cout << "Estimated labour cost    : R" << estimatedLabourCost << endl;
    cout << "Estimated total cost     : R" << estimatedTotalCost << endl;
    cout << "Target Selling Price     : R" << sellingPriceBeforeTax << endl;
    cout << "Expected Contribution    : R" << expectedContribution << endl;
    cout << "Expected Margin          : " << expectedMContributionMargin << "%" << endl;
    cout << "Markup on Costs          : " << markupOnEstimatedCosts << "%" << endl;

    cout << "--------------------------------------------\n" << endl;

    cout << "\n= = = = = = ACTUAL JOB COSTS = = = = = =\n" << endl;

    cout << "Actual Total Cost  :   R" << actualTotalCost << endl;
    cout << "Cost Variance      :   R" << costVariance << endl;
    cout << "Actual Contribution:   R" << actualContribution << endl;
    cout << "Actual Margin      :   " << actualContributionMargin << "%" << endl;

    cout << "===========================================" << endl;

    
    //CRM dashboard.

    cout << setiosflags(ios::fixed) << setprecision(2);

    cout << "\n\n============================================" << endl;

    cout << "\tFAIR VALUE CRM - DECISION DASHBOARD\t" << endl;

    cout << "============================================" << endl;

    //Create customers.
    Customer cust1(1, "Thandi", "Mokoena", "thadi@email.com");
    Customer cust2(2, "Lebo", "Mmonwa", "lebo@email.com");

    //Job(int jobId, long long customerIdentityNumber, std::string descriptionOfJob, std::string scopeOfJob, std::string startDate, std::string endDate, std::string statusOfJob, std::string staffAssigned, double estimatedCostOfJob)
    Job work1(101, cust1.getCustomerId(), "Engine Repair", "Full rebuild", "2026-10-14", "2026-10-21", "Complete", "John", 1200.00);

    Job work2(201, cust2.getCustomerId(), "Gala Setup", "Stage and décor", "2026-08-10", "2026-08-12", "In progress", "Sarah", 4500.00);

    //Simulating the jobs finishing (recording the actual costs).
    work1.setActualJobCost(1950.00);     //Job 1 went over budget!
    work2.setActualJobCost(3900.00);     //Job 2 came in under budget.

    //Cost items created.
    //CostItem(int itemId, long long jobLinkedToItem, std::string typeOfItem, std::string descriptionOfItem, double costOfItem, bool estimatedTestOfItem)
    CostItem costI1(1, work1.getJobNumber(), "Labour", "7 days mechanic work", 3, 150.00, true);
    CostItem costI2(2, work1.getJobNumber(), "Materials", "Brake Pads", 1, 250.00, false);

    //Creating quotations.
    Quotation quote1(1, work1.getJobNumber(), 1066.90, "Pending", "2026-11-15", 0.15);

    //Service Event created.
    ServiceEvent serveE1("SRV-001", work1.getJobNumber(), "Delay", "2026-10-28", "Parts arrived late", "John");

    //Printing the dashboard.
    cout << "= = = = = JOB LEVEL DECISION CARDS = = = = =" << endl;

    cout << "Job ID             :   " << work1.getJobNumber() << endl;
    cout << "Estimated Cost     :   R" << work1.getEstimatedJobCost() << endl;
    cout << "Actual Cost        :   R" << work1.getActualJobCost() << endl;

    double variance1 = 0.0;
    double variance2 = 0.0;

    variance1 = work1.getActualJobCost() - work1.getEstimatedJobCost();

    cout << "Variance           :   R" << variance1 << endl;
    cout << "Quote Status       :   " << quote1.getQuotationStatus() << endl;
    cout << "Service Issue      :   " << serveE1.getEventType() << " (" << serveE1.getEventDescription() << ")" << endl;

    cout << "\n>>>>RUNNING AUTOMATION ENGINE<<<<" << endl;

    detectCostOverrun(work1, 100.50, 15.75);

    //Quote pending for 4 days. Policy is 3 days. No duplicate task.
    processQuotationFollowUp(quote1, 4, 3, false);

    cout << "-----------------------------------------------------" << endl;

    cout << "Job ID             :    " << work2.getJobNumber() << endl;
    cout << "Estimated Cost     :   R" << work2.getEstimatedJobCost() << endl;
    cout << "Actual Cost        :   R" << work2.getActualJobCost() << endl;


    variance2 = work2.getActualJobCost() - work2.getEstimatedJobCost();

    cout << "Variance           : R" << variance2 << endl;
   
    cout << "\n>>>>RUNNING AUTOMATION ENGINE<<<<" << endl;

    detectCostOverrun(work2, 100.00, 75.00);

    cout << "============================================" << endl;

    cout << "\nPress enter to exit...";


    cin.get();      //Proper way for user to press Enter.
    return 0;
}