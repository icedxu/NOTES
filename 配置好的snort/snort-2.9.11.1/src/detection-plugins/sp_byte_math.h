#ifndef __SP_BYTE_MATH_H__
#define __SP_BYTE_MATH_H__

#include "sf_engine/sf_snort_plugin_api.h"
#include "decode.h"
#include "plugbase.h"

#define BM_PLUS                 CHECK_ADD
#define BM_MINUS                CHECK_SUB
#define BM_MULTIPLY             CHECK_MUL
#define BM_DIVIDE               CHECK_DIV
#define BM_LEFT_SHIFT           CHECK_LS
#define BM_RIGHT_SHIFT          CHECK_RS
#define BM_CHECK_NONE           CHECK_NONE

#define BIG    0
#define LITTLE 1

#define BYTE_MATH_VAR_INDEX 2

#define MIN_RVAL 1
#define MAX_RVAL 4294967295

extern char *bytemath_variable_name;
extern u_int32_t bytemath_variable;

typedef struct _ByteMathData
{
    u_int32_t bytes_to_extract; /* lvalue : number of bytes to extract */
    u_int32_t rvalue;
    u_int32_t operator;
    int32_t offset;
    uint8_t relative_flag;
    uint8_t data_string_convert_flag;
    int8_t endianess;
    u_int32_t base;
    u_int32_t bitmask_val;
    int8_t rvalue_var;
    int8_t offset_var;
    char *result_var;
    RuleOptByteOrderFunc byte_order_func;
} ByteMathData;

void SetupByteMath(void);
u_int32_t ByteMathHash(void *d);
int8_t GetVarByName_check(char *name);
void ClearByteMathVarNames(OptFpList *fpl);
void AddVarName_Bytemath(ByteMathData *data);
int ByteMathCompare(void *l, void *r);
int ByteMath(void *, Packet *);
void ByteMathFree(void *d);


#endif  /* __SP_BYTE_MATH_H__ */
