#pragma once
#include <string>
#include <stdexcept>

class CostItem
{
	private:
		int itemNumber;
		long long jobNumberLinkedToItem;
		std::string itemCategory;
		std::string itemDescription;
		int quantityOfItem;
		double unitCostPerItem;
		double itemAmount;
		bool itemIsEstimated;

	public:
		CostItem();
		CostItem(int, long long, std::string, std::string, int, double, bool);

		//Getters.
		int getItemNumber() const;
		long long getJobNumberLinkedToItem() const;
		std::string getItemCategory() const;
		std::string getItemDescription() const;
		int getQuantityOfItem() const;
		double getUnitCostPerItem() const;
		double getItemAmount() const;
		bool getItemIsEstimated() const;

};

inline CostItem::CostItem()
{
	itemNumber = 0;
	jobNumberLinkedToItem = 0;
	itemCategory = "";
	itemDescription = "";
	quantityOfItem = 0;
	unitCostPerItem = 0.0;
	itemAmount = 0.0;
	itemIsEstimated = true;		//Why true? It's true if it's estimated but false if it's actual.
}

inline CostItem::CostItem(int itemId, long long jobLinkedToItem, std::string typeOfItem, std::string descriptionOfItem, int quantity, double unitCostOfItem, bool estimatedTestOfItem)
{
	//Validation of product information.

	//Exceptions thrown to stop the programme if the values are negative numbers.
	if (itemId <= 0 || jobLinkedToItem <=0)
	{
		throw std::invalid_argument("IDs must not be negative.");
	}

	if (unitCostOfItem <=0 || quantity <= 0)
	{
		throw std::invalid_argument("Cost amount cannot be a negative value.");
	}

	itemNumber = itemId;
	jobNumberLinkedToItem = jobLinkedToItem;
	itemCategory = typeOfItem;
	itemDescription = descriptionOfItem;
	quantityOfItem = quantity;
	unitCostPerItem = unitCostOfItem;

	itemAmount = quantityOfItem * unitCostPerItem;
	itemIsEstimated = estimatedTestOfItem;


}

inline int CostItem::getItemNumber() const
{
	return itemNumber;
}

inline long long CostItem::getJobNumberLinkedToItem() const
{
	return jobNumberLinkedToItem;
}

inline std::string CostItem::getItemCategory() const
{
	return itemCategory;
}

inline std::string CostItem::getItemDescription() const
{
	return itemDescription;
}

inline int CostItem::getQuantityOfItem() const
{
	return quantityOfItem;
}

inline double CostItem::getUnitCostPerItem() const
{
	return unitCostPerItem;
}

inline double CostItem::getItemAmount() const
{
	return itemAmount;
}
//getItemIsEstimated
inline bool CostItem::getItemIsEstimated() const
{
	return itemIsEstimated;
}