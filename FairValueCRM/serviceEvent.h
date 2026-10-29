#pragma once
#include <string>
#include <stdexcept>

//Why is service event ID a string but the job ID is an integer?
//Because a job ID is an internal database key (1, 2, 3), but a service event ID is a business reference code.
class ServiceEvent
{
	private:
		std::string eventIdNumber;
		int jobIdNumberLinkedToEvent;
		std::string eventType;
		std::string eventTimeStamp;
		std::string eventDescription;
		std::string personResponsibleForEvent;

	public:
		ServiceEvent();
		ServiceEvent(std::string, int, std::string, std::string, std::string, std::string);
	
		//Getters.
		std::string getEventIdNumber() const;
		int getJobIdNumberLinkedToEvent() const;
		std::string getEventType() const;
		std::string getEventTimeStamp() const;
		std::string getEventDescription() const;
		std::string getPersonResponsibleForEvent() const;

};

inline ServiceEvent::ServiceEvent()
{
	eventIdNumber = "";
	jobIdNumberLinkedToEvent = 0;
	eventType = "";
	eventTimeStamp = "";
	eventDescription = "";
	personResponsibleForEvent = "";

}

inline ServiceEvent::ServiceEvent(std::string eventId, int jobNumber, std::string typeOfEvent, std::string timeStampOfEvent, std::string descriptionOfEvent, std::string responsiblePerson)
{
	if (eventId.empty() || jobNumber <= 0)
	{
		throw std::invalid_argument("Invalid Event ID number or Event Job ID number.");
	}

	eventIdNumber = eventId;
	jobIdNumberLinkedToEvent = jobNumber;
	eventType = typeOfEvent;
	eventTimeStamp = timeStampOfEvent;
	eventDescription = descriptionOfEvent;
	personResponsibleForEvent = responsiblePerson;
}

/*int getEventIdNumber() const;
		int getJobIdNumberLinkedToEvent() const;
		std::string getEventType() const;
		std::string getEventTimeStamp() const;
		std::string getEventDescription() const;
		std::string getPersonResponsibleForEvent()*/
inline std::string ServiceEvent::getEventIdNumber() const
{
	return eventIdNumber;
}

inline int ServiceEvent::getJobIdNumberLinkedToEvent() const
{
	return jobIdNumberLinkedToEvent;
}

inline std::string ServiceEvent::getEventType() const
{
	return eventType;
}

inline std::string ServiceEvent::getEventTimeStamp() const
{
	return eventTimeStamp;
}

inline std::string ServiceEvent::getEventDescription() const
{
	return eventDescription;
}

inline std::string ServiceEvent::getPersonResponsibleForEvent() const
{
	return personResponsibleForEvent;
}