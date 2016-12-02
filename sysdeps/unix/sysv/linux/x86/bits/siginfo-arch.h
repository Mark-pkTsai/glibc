/* Architecture-specific adjustments to siginfo_t.  x86 version.  */
#ifndef _BITS_SIGINFO_ARCH_H
#define _BITS_SIGINFO_ARCH_H 1

/* Additional fields for _sifields._sigfault.  */
#define __SI_SIGFAULT_ADDL_2			\
  struct					\
     {						\
       void *_lower;				\
       void *_upper;				\
     } si_addr_bnd;

#define si_lower	_sifields._sigfault.si_addr_bnd._lower
#define si_upper	_sifields._sigfault.si_addr_bnd._upper

#if defined __x86_64__ && __WORDSIZE == 32
/* si_utime and si_stime must be 4 byte aligned for x32 to match the
   kernel.  We align siginfo_t to 8 bytes so that si_utime and si_stime
   are actually aligned to 8 bytes since their offsets are multiple of
   8 bytes.  */
typedef __clock_t __attribute__ ((__aligned__ (4))) __sigchld_clock_t;
# define __SI_ALIGNMENT __attribute__ ((__aligned__ (8)))
# define __SI_CLOCK_T __sigchld_clock_t
#endif

#endif
