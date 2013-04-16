/*
 * DataHandler.cpp
 *
 *  Created on: 15 apr 2013
 *      Author: stekman
 */

#include "DataHandler.h"

DataHandler::DataHandler(): state(INVALID)
{
}

DataHandler::State DataHandler::getState() const
{
	return state;
}

void DataHandler::setState(State state) const
{
	this->state = state;
}

DataHandler::~DataHandler()
{
}

void DataHandler::onChange()
{
	if(getState()!=INVALID)
	{
		setState(INVALID);
		rippleChanges();
	}
}

void DataHandler::makeValid() const
{
	doMakeValid();
	setState(VALID);
	for(auto subscription: subscriptions)
	{
		if(subscription->getState()==INVALID)
			subscription->makeValid();
	}
}

void DataHandler::rippleChanges() const
{
	for(auto subscriber: subscribers)
	{
		subscriber->onChange();
	}
}

void DataHandler::subscribe(DataHandler* object)
{
	subscriptions.push_back(object);
	object->subscribers.push_back(this);
}
