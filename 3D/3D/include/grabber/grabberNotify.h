#ifndef GRABBER_NOTIFY
#define GRABBER_NOTIFY

class PModel;

class GrabberNotify
{
public:
	GrabberNotify(PModel* pModel) : _pModel(pModel)
	{
	}

	void NotifyNewCloudArrived();

private:
	PModel* _pModel;
};

#endif