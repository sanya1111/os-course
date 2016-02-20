#ifndef UTILS_H_
#define UTILS_H_

#define BIT(x) (1L<<(x))
#define SPLICE(x, begin, end) (x >> begin) & (BIT(end - begin) - 1)
#define LOW(x, mod) SPLICE(x, 0, mod)

#define STR(name) #name
#define EXPAND(name) STR(name)

#define VOID_FUNC(name) void name()
#define CHECK_FLAG(x, value) ((x & value) > 0)

#endif
