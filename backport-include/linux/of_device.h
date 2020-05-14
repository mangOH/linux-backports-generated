#ifndef __BP_OF_DEVICE_H
#define __BP_OF_DEVICE_H
#include_next <linux/of_device.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,12,0)
extern ssize_t of_device_modalias(struct device *dev, char *str, ssize_t len);
#endif

#endif /* __BP_OF_DEVICE_H */
