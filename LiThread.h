#ifndef LI_THREAD_H
#define LI_THREAD_H

#include "Headers.h" 

class Thread{
private:
	pthread_t _id;
	
	static void* thread_routine(void* param){((Thread*)param)->run();return NULL;}

public:
	virtual ~Thread(){}

	void start(){pthread_create(&_id,NULL,Thread::thread_routine,(void*)this);}
	void join(){pthread_join(_id,NULL);	}
	int get_id(){return _id;}
protected:
	virtual void run()=0;
};

#endif	//LI_THREAD_H
