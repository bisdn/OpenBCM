/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 */

#ifndef __COMMON_LINUX_KRN_LKM_H__
#define __COMMON_LINUX_KRN_LKM_H__

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/init.h>
#include <linux/version.h>
/* The version kconfig.h became available in. */
#include <linux/kconfig.h>
#if defined(INCLUDE_KNET)
#ifdef CONFIG_NF_CONNTRACK_MODULE
#include <linux/netfilter.h>
#endif
#endif
#include <linux/slab.h>
#include <linux/module.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,9,0)
#define HAVE_COMPAT_IOCTL 1
#define HAVE_UNLOCKED_IOCTL 1
#endif

#include <linux/kernel.h>   /* printk() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/pci.h>
#include <linux/interrupt.h>
#include <linux/stat.h>
#include <linux/sched.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,11,0)
#include <linux/sched/signal.h>
#endif
#include <linux/delay.h>

#include <asm/io.h>
#include <asm/hardirq.h>
#include <asm/uaccess.h>

/* Compatibility Macros */

#ifndef list_for_each_safe
#define list_for_each_safe(l,t,i) t = 0; list_for_each((l),(i))
#endif

#ifndef reparent_to_init
#define reparent_to_init()
#endif

#ifndef MODULE_LICENSE
#define MODULE_LICENSE(str)
#endif

#ifndef EXPORT_NO_SYMBOLS
#define EXPORT_NO_SYMBOLS
#endif

#ifndef DEFINE_SPINLOCK
#define DEFINE_SPINLOCK(_lock) spinlock_t _lock = SPIN_LOCK_UNLOCKED
#endif

#ifndef __SPIN_LOCK_UNLOCKED
#define __SPIN_LOCK_UNLOCKED(_lock) SPIN_LOCK_UNLOCKED
#endif

#ifndef lock_kernel
#ifdef preempt_disable
#define lock_kernel() preempt_disable()
#else
#define lock_kernel()
#endif
#endif

#ifndef unlock_kernel
#ifdef preempt_enable
#define unlock_kernel() preempt_enable()
#else
#define unlock_kernel()
#endif
#endif

#ifndef init_MUTEX_LOCKED
#define init_MUTEX_LOCKED(_sem) sema_init(_sem, 0)
#endif

#ifdef CONFIG_BCM98245
#define CONFIG_BMW
#endif

#endif /* __COMMON_LINUX_KRN_LKM_H__ */
