#ifndef PUBLISHER_DEFINE
#define PUBLISHER_DEFINE
#include "Enums.h"
#include "ListClass.h"
//����������
class IEncoderObserver { //���������
public:
	virtual void HandleCommand(EncoderAction action) = 0;
};

class IPublisher { //��������
public:
	virtual void Attach(IEncoderObserver* observer) = 0;
	virtual void Detach(IEncoderObserver* observer) = 0;
	virtual void Notify(EncoderAction action) = 0;
	virtual ~IPublisher() = 0;
};
//=================================================== �������� � ��������� ��� ������� �������� �������� ===================================

class EncoderActionPublisher : public IPublisher {
private:
	List<IEncoderObserver> _observers;
public:
	void Attach(IEncoderObserver* observer) override;
	void Detach(IEncoderObserver* observer) override;
	void Notify(EncoderAction action) override;
	~EncoderActionPublisher() override;
};
#endif
