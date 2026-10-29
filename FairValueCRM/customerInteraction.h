#pragma once
#include <string>
#include <stdexcept>

class CustomerInteraction
{
	private:
		int interactionNumber;
		long long customerNumber;
		std::string interactionChannel;		//Via e-mail, telephone, WhatsApp.
		std::string interactionPurpose;		//Is it a complaint or a follow-up?
		std::string interactionOutcome;		//Is the outcome resolved or has a voicemail been left?
		std::string nextInteractionAction;	//Next ideal step: call back tomorrow, or promptly.

	public:
		CustomerInteraction();
		CustomerInteraction(int, long long, std::string, std::string, std::string, std::string);

		//Getters.
		int getInteractionNumber() const;
		long long getCustomerNumber() const;
		std::string getInteractionChannel() const;
		std::string getInteractionPurpose() const;
		std::string getInteractionOutcome() const;
		std::string getInteractionAction() const;

		//Update.
		void updateNextInteractionAction(std::string);

};

inline CustomerInteraction::CustomerInteraction()
{
}

CustomerInteraction::~CustomerInteraction()
{
}