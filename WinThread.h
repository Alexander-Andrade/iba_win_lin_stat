#ifndef WIN_THREAD
#define WIN_THREAD

#include "Headers.h"

class Thread
{
private:
	DWORD _id;
	HANDLE _handle;

	static DWORD WINAPI start_routine(LPVOID lpParam){
		((Thread*)lpParam)->run();
		return 0;
	}

public:
	Thread() {};

	virtual ~Thread() {};

	void start(){
		_handle = CreateThread(NULL,			// default security attributes
			0,									// use default stack size  
			start_routine,						// thread function name
			(void*)this,						// argument to thread function 
			0,									// use default creation flags
			&_id								// returns the thread identifier 
			);
		if (_handle == NULL)
			cout << GetLastError() << endl;
	}
	
	void join(){
		WaitForSingleObject(_handle, INFINITE);
	}
	int get_id() { return _id; }
protected:
	//наследоваться и перегружать
	virtual void run()=0;
};


#endif	//WIN_THREAD
