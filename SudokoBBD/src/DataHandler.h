/*
 * DataHandler.h
 *
 *  Created on: 15 apr 2013
 *      Author: stekman
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include <list>

class DataHandler
{
public:
	enum State {VALID,INVALID};
private:
	mutable State state;
	std::list<DataHandler*> subscribers;
	std::list<DataHandler*> subscriptions;
public:
	DataHandler();
	virtual ~DataHandler();
	virtual void onChange();
	virtual void makeValid() const;
	virtual void doMakeValid() const = 0;
	virtual State getState() const;
	virtual void setState(State state) const;
	virtual void rippleChanges() const;
	virtual void subscribe(DataHandler* object);
};

#endif /* DATAHANDLER_H_ */
