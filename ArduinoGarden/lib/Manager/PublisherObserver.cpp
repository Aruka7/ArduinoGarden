#include "PublisherObserver.h"

IPublisher::~IPublisher(){};

void EncoderActionPublisher::Attach(IEncoderObserver* observer){
		_observers.Add(observer);
}
void EncoderActionPublisher::Detach(IEncoderObserver* observer){
		_observers.Remove(observer);
}
void EncoderActionPublisher::Notify(EncoderAction action){
	_observers.SetStart();
	IEncoderObserver* tmp = _observers.Next();
	while (tmp != nullptr)
	{
		tmp->HandleCommand(action);
		tmp = _observers.Next();
	}
}

EncoderActionPublisher::~EncoderActionPublisher(){

}
