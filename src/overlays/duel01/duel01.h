#include "common.h"
#include "process.h"
#include "common_structs.h"
#include "malloc.h"
#include "game/board.h"
#include "../ovl_81_name/ovl_81.h"

typedef struct unkStruct {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s16 unk_04;
} unkStruct;
typedef struct unkStruct01 {
/* 0x00 */ f32 unk_00;
/* 0x04 */ char unk_04[4];
/* 0x08 */ f32 unk_08;
} unkStruct01;

typedef struct unkStruct02 {
/* 0x00 */ Vec unk_00;
/* 0x0C */ char unk_0C[4];
} unkStruct02;

typedef struct unkStruct03 {
/* 0x00 */ char unk_00[0x18];
/* 0x18 */ HeapNode* unk_18;
/* 0x1C */ char unk_1C[0x70];
/* 0x8C */ unkStruct02* unk_8C;
} unkStruct03;

typedef struct unkStruct04 {
/* 0x00 */ char unk_00[0x0C];
/* 0x0C */ Vec unk_0C;
} unkStruct04;

typedef struct unkStruct06 {
/* 0x00 */ s32 unk_00;
/* 0x04 */ s32 unk_04;
/* 0x08 */ f32 unk_08;
/* 0x0C */ char unk_0C[4];
} unkStruct06;

extern s16 omovlevtno;
s32 func_800E88FC_D06CC_name_81(void);
extern s32 D_80119470_3EC560_duel01;
extern s32 D_80119474_3EC564_duel01;
extern s32 D_80119478_3EC568_duel01;
extern s32 D_8011947C_3EC56C_duel01;
void func_800E9F4C_D1D1C_name_81(s32, s8*, s8*);
void func_800EA760_D2530_name_81(void);
void func_800ECD0C_D4ADC_name_81(s32, s8, s8);
unkStruct03* func_80047EA0_48AA0(void*, s32, s32, s32);
void func_80105CC0_3D8DB0_duel01(void); //probably takes object as arg
Process* func_800EBF2C_D3CFC_name_81(Vec*, Vec*, Vec*, s32);
void func_80106308_3D93F8_duel01(void);
void func_8001C258_1CE58(s16, s32, s32);
void func_8001C448_1D048(s16);
void func_8001C8E4_1D4E4(s16, u32);
void func_80089A20_8A620(Vec*, s32);
void func_800F38DC_DB6AC_name_81(s32, s32, s32);
void func_80110068_3E3158_duel01(s32);