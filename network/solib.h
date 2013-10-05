#ifndef _VFS_SOLIB_H_
#define _VFS_SOLIB_H_
#include "global.h"
typedef int (*proc_method) (int fd);
typedef int (*proc_init) (void);
typedef void (*proc_fini) (int fd);
typedef void (*proc_timeout) (void);

struct mylib {
	void* handle;
	proc_init		svc_init;    //O
#if VFS_SERVER == 1
	proc_init		svc_pinit;    //O for thread init
#endif
	proc_method		svc_initconn;//O	
	proc_method		svc_recv; //M	
	proc_method		svc_send;  //M
	proc_method		svc_send_once;  //O
	proc_fini		svc_finiconn;//O	
	proc_timeout	svc_timeout; //O
};

#endif