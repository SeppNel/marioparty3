#include "common.h"
#include "ovl_81.h"

extern s16 D_801029C8_EA798_name_81[128];
extern ObjectName* D_801029C0_EA790_name_81;
extern u16 D_801029C4_EA794_name_81;
extern s16 D_80105624_ED3F4_name_81;

static void func_800D7D70_BFB40_name_81(void) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_801029C8_EA798_name_81); i++) {
        D_801029C8_EA798_name_81[i] = 0;
    }
}

static s16 func_800D7DA0_BFB70_name_81(s16 arg0) {
    D_801029C8_EA798_name_81[arg0]++;
    return arg0;
}

s16 func_800D7DC8_BFB98_name_81(s32 arg0) {
    s16 res = func_8001F1FC_1FDFC(DataRead(arg0), 8);
    D_801029C8_EA798_name_81[res]++;
    return res;
}

void func_800D7E14_BFBE4_name_81(s16 arg0) {
    if (D_801029C8_EA798_name_81[arg0] != 0) {
        D_801029C8_EA798_name_81[arg0]--;
        if (D_801029C8_EA798_name_81[arg0] == 0) {
            func_8002D4B8_2E0B8(arg0);
        }
    }
}

static s16 func_800D7E68_BFC38_name_81(s16 arg0) {
    if (D_801029C8_EA798_name_81[arg0] != 0){
        D_801029C8_EA798_name_81[arg0]++;
        return arg0;
    }
    return -1;
}

void func_800D7EB8_BFC88_name_81(void) {
    D_801029C0_EA790_name_81 = NULL;
    D_801029C4_EA794_name_81 = 0;
    D_80105624_ED3F4_name_81 = 1;
    func_800D7D70_BFB40_name_81();
    func_800D87DC_C05AC_name_81(100.0f);
    func_800D85A8_C0378_name_81(1.0f);
}

void func_800D7F0C_BFCDC_name_81(void) { // MBDModelClose
    while (D_801029C0_EA790_name_81 != NULL) {
        func_800D8F3C_C0D0C_name_81(D_801029C0_EA790_name_81);
    }
}

ObjectName *func_800D7F4C_BFD1C_name_81(void) {
    ObjectName *temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(ObjectName));
    if (temp_v0 != NULL) {
        D_801029C4_EA794_name_81++;
        temp_v0->prev = D_801029C0_EA790_name_81;
        temp_v0->next = NULL;
        if (D_801029C0_EA790_name_81 != NULL) {
            D_801029C0_EA790_name_81->next = temp_v0;
        }
        D_801029C0_EA790_name_81 = temp_v0;
        temp_v0->flags = 8;
        HuVecCopyXYZ(&temp_v0->coords, 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&temp_v0->rot, 0.0f, 0.0f, 1.0f);
        HuVecCopyXYZ(&temp_v0->scale, 1.0f, 1.0f, 1.0f);
        temp_v0->velocity.x = 0.0f;
        temp_v0->velocity.y = 0.0f;
        temp_v0->velocity.z = 0.0f;
        temp_v0->unk46 = -1;
        temp_v0->unk48 = -1;
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8010_BFDE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8314_C00E4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D85A8_C0378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D85B4_C0384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D87DC_C05AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D87E8_C05B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8944_C0714_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D898C_C075C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8B18_C08E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8E34_C0C04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8E88_C0C58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8EB8_C0C88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8F0C_C0CDC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8F3C_C0D0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D9098_C0E68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D90D0_C0EA0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D918C_C0F5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D9234_C1004_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D92A8_C1078_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D92F8_C10C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D9384_C1154_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D94C4_C1294_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D9668_C1438_name_81);

void func_800D96F4_C14C4_name_81(void) {
    ObjectName *obj = *(ObjectName **)HuPrcCurrentGet()->user_data;

    func_8001C814_1D414(obj->omObj1->model[0], 3, 0);
    func_800EFABC_D788C_name_81(obj);
    func_800D8F3C_C0D0C_name_81(obj);
    omDelPrcObj(NULL);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D974C_C151C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C48_E9A18_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C4C_E9A1C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C50_E9A20_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C54_E9A24_name_81);
