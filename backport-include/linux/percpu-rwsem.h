#ifndef __BACKPORT_PERCPU_RWSEM_H
#define __BACKPORT_PERCPU_RWSEM_H
#include_next <linux/percpu-rwsem.h>

/*
 * Earlier versions of the kernel didn't export the percpu-rwsem functions, so
 * we just use the non-percpu version instead.  There is an associated patch
 * (0097-avoid-percpu-rwsem.cocci) that conditionally transforms declarations
 * from percpu_rw_semaphore -> rw_semaphore on Linux < 4.2.0 and then re-writes
 * all calls to the percpu functions to percpu_backport macros defined below.
 * The macros below are either just a call-through to the percpu-rwsem functions
 * (in the case of newer Linux) or they use the rwsem functions in the case of
 * older Linux.
 */

#if LINUX_VERSION_IS_LESS(4,2,0)
#include <linux/rwsem.h>
#define percpu_backport_init_rwsem(_sem) init_rwsem(_sem)
#define percpu_backport_down_read(_sem) down_read(_sem)
#define percpu_backport_down_read_trylock(_sem) down_read_trylock(_sem)
#define percpu_backport_down_write(_sem) down_write(_sem)
#define percpu_backport_free_rwsem(_sem) ({;})
#define percpu_backport_up_read(_sem) up_read(_sem)
#define percpu_backport_up_write(_sem) up_write(_sem)
#else
#define percpu_backport_init_rwsem(_sem) percpu_init_rwsem(_sem)
#define percpu_backport_down_read(_sem) percpu_down_read(_sem)
#define percpu_backport_down_read_trylock(_sem) percpu_down_read_trylock(_sem)
#define percpu_backport_down_write(_sem) percpu_down_write(_sem)
#define percpu_backport_free_rwsem(_sem) percpu_free_rwsem(_sem)
#define percpu_backport_up_read(_sem) percpu_up_read(_sem)
#define percpu_backport_up_write(_sem) percpu_up_write(_sem)
#endif /* < 4.2.0 */


#endif /* __BACKPORT_PERCPU_RWSEM_H */
