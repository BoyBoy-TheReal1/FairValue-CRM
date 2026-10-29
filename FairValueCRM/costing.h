#pragma once

inline double calculateLabourCost(double labourHours, double labourCostPerHour)
{
	return labourHours * labourCostPerHour;
}

inline double calculateEstimatedCost(double estimatedLabourCost, double estimatedMaterialsCost, double otherDirectCosts, double manufacturingOverheads)
{
    return estimatedLabourCost + estimatedMaterialsCost + otherDirectCosts + manufacturingOverheads;
}

inline double calculateTargetPrice(double estimatedTotalCost, double targetMargin)
{
    //To prevent/protect against division by zero.
    if (targetMargin > 1.0)
    {
        return 0.0;
    }

    return estimatedTotalCost / (1.0 - targetMargin);
}

inline double calculateContributionMargin(double revenue, double cost)
{
    if (revenue <= 0.0)
    {
        return 0.0;
    }
    
    return ((revenue - cost) / revenue) * 100.0;
}

inline double calculateMarkup(double revenue, double cost)
{
    if (cost <= 0.0)
    {
        return 0.0;
    }

    return ((revenue - cost) / cost) * 100.0;
}

