/*************************************************************************************************
*                                                                                                *
*                                            [ Finc ]                                            *
*                                                                                                *
**************************************************************************************************
*                                                                                                *
*                              A free, open-source utility program.                              *
*                            (c) 2020 Taxerap, some rights reserved.                             *
*                                                                                                *
*              Finc is a free software. You can freely do whatever you want with it              *
*     under the JUST DON'T BOTHER ME PUBLIC LICENSE (hereinafter referred to as the license)     *
*                                   published by mhtvsSFrpHdE.                                   *
*                                                                                                *
*  By the time this line is written, the version of the license document is 1, but you may use   *
* any later version of the document released by mhtvsSFrpHdE <https://github.com/mhtvsSFrpHdE>.  *
*                                                                                                *
*               Finc is created, intended to be useful, but without any warranty.                *
*                      For more information, please forward to the license.                      *
*                                                                                                *
*       You should have received a copy of the license along with the source code of this        *
*  program. If not, please see https://github.com/mhtvsSFrpHdE/ipcui/blob/master/LICENSE_JDBM.   *
*                                                                                                *
*          For more information about the project, please visit my Github repository at          *
*                                https://github.com/Taxerap/Finc.                                *
*                                                                                                *
*                             I don't know why I did this but yeah.                              *
*                                                                                                *
**************************************************************************************************/

#ifndef FINC_PCH_H
#define FINC_PCH_H

#if defined _WIN32 || (!defined _WIN32 && defined __CYGWIN__)
    #define FINC_TARGET_WINDOWS
#elif defined __MACH__ && defined __APPLE__
    #define FINC_TARGET_MACOS
    #define FINC_TARGET_POSIX
#else
    #define FINC_TARGET_POSIX
#endif

#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>

#ifndef thread_local
    #define thread_local _Thread_local
#endif

#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

#endif // !FINC_PCH_H
