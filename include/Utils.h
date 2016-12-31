/*
 **
 ** Made by MisterAlex
 **
 */

#ifndef UTILS_H_
# define UTILS_H_

# include <stdint.h>
# include <math.h>
# include <string>
# include <stdlib.h>
# include <psp2/ctrl.h>
# include <psp2/kernel/processmgr.h>
# include <psp2/touch.h>
# include <psp2/sysmodule.h>
# include <ctime>
# include <vector>
# include <map>
# include <string>

# include <vita2d.h>

# define lerp(value, from_max, to_max) ((((value*10) * (to_max*10))/(from_max*10))/10)

# define SCREEN_H	544
# define SCREEN_L	960
# define COLOR_SKY RGBA8(0,175,227,255)
# define WHITE RGBA8(255,255,255,255)
# define VERSION_STAGE "Alpha"
# define VERSION_NUMBER 0.1

#endif /* !UTILS_H_ */
