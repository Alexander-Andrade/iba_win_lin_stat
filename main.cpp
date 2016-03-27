#include "Thread.h"

class SysInfo : public Thread{
private:
	ostream& outLinuxSysInfo(ostream& s){
#if defined(__linux__)		
		rusage res_usage;
		memset(&res_usage,0,sizeof(rusage));
		getrusage(RUSAGE_SELF,&res_usage);
		s.fill('.');
		int col_size = 40;
		s << setw(col_size) << left <<"maximum resident set size(KB): "<< res_usage.ru_maxrss << endl<<
		setw(col_size) << left << "user CPU time used (s:mks): " << res_usage.ru_utime.tv_sec <<" : "<< res_usage.ru_utime.tv_usec <<endl<<
		setw(col_size) << left << "system CPU time used (s:mks): " << res_usage.ru_stime.tv_sec <<" : "<< res_usage.ru_stime.tv_usec <<endl<<
		setw(col_size) << left <<"involuntary context switches: " <<res_usage.ru_nivcsw<<endl<<
		setw(col_size) << left <<"voluntary context switches: " <<res_usage.ru_nvcsw<<endl;
#endif
		return s; 
}
	ostream& outWinSysInfo(ostream& s){
#if defined(_WIN64) || defined(_WIN632)
	MEMORYSTATUSEX memInfo;
	memset(&memInfo, 0, sizeof(MEMORYSTATUSEX));
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);	
	s.fill('.');
	int col_size = 40;
	s << setw(col_size) << left << "Memory in use(%): " << info.memInfo.dwMemoryLoad << endl <<
			setw(col_size) << left << "phisical memory (KB): " << info.memInfo.ullTotalPhys / kB << endl <<
			setw(col_size) << left << "phisical free memory (KB): " << info.memInfo.ullAvailPhys / kB << endl <<
			setw(col_size) << left << "paging file total memory (KB): " << info.memInfo.ullTotalPageFile / kB << endl <<
			setw(col_size) << left << "paging file free memory (KB): " << info.memInfo.ullAvailPageFile / kB << endl <<
			setw(col_size) << left << "virtual memory (KB): " << info._memInfo.ullTotalVirtual / kB << endl <<
			setw(col_size) << left << "virtual memory free (KB): " << info.memInfo.ullAvailVirtual / kB;
#endif
	return s; 
}
public:
	void run() override{
	outSysInfo(cout);
}
	ostream& outSysInfo(ostream& s){
	#if defined(__linux__)
	return outLinuxSysInfo(s);
	#elif defined(_WIN64) || defined(_WIN632)
	return outWinSysInfo(s);
	#endif
	}
};


int main(int argc,char* argv[]){
	SysInfo sysInfo;
	sysInfo.start();
	sysInfo.join();
	return 0;
}
