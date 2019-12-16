#ifndef __BACKPORT_CRYPTO_H
#define __BACKPORT_CRYPTO_H
#include_next <linux/crypto.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,0,0)
/*
 * Mark a cipher as a service implementation only usable by another
 * cipher and never by a normal user of the kernel crypto API
 */
#define CRYPTO_ALG_INTERNAL            0x00002000
#endif /* < 4.0.0 */

#endif /* __BACKPORT_CRYPTO_H */
