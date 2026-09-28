#include "common.h"
#include "ovl_81.h"

typedef struct UnkObj {
    ObjectDuel *unk_00;
    f32 unk_04;
} UnkObj;

extern s16 D_801029C8_EA798_name_81[128];
extern ObjectDuel* D_801029C0_EA790_name_81;
extern u16 D_801029C4_EA794_name_81;
extern s16 D_80105624_ED3F4_name_81;
extern f32 D_80100E10_E8BE0_name_81;
extern f32 D_80100E14_E8BE4_name_81;

static void func_800D85B4_C0384_name_81(omObjData *playerObj);
static void func_800D87E8_C05B8_name_81(omObjData* arg0);

static void func_800D7D70_BFB40_name_81(void) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_801029C8_EA798_name_81); i++) {
        D_801029C8_EA798_name_81[i] = 0;
    }
}

static s16 MBDMotionLock(s16 arg0) {
    D_801029C8_EA798_name_81[arg0]++;
    return arg0;
}

s16 func_800D7DC8_BFB98_name_81(s32 arg0) {
    s16 res = func_8001F1FC_1FDFC(DataRead(arg0), 8);
    D_801029C8_EA798_name_81[res]++;
    return res;
}

void MBDMotionKill(s16 arg0) {
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
        MBDModelKill(D_801029C0_EA790_name_81);
    }
}

ObjectDuel *func_800D7F4C_BFD1C_name_81(void) {
    ObjectDuel *temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(ObjectDuel));
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

ObjectDuel *MBDModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32 *arg4) {
    ObjectDuel *object;
    omObjData *objData;
    UnkObj *work;
    HmfModel *model;
    u32 *dataPtr;
    s16 mdlIdx;
    s16 motionCnt;
    s16 i;
    u8 temp;

    dataPtr = arg4;
    motionCnt = 0;

    object = func_800D7F4C_BFD1C_name_81();
    if (object != NULL) {
        object->unk8 = 0xFF;

        if (dataPtr != NULL) {
            motionCnt = dataPtr[0];
            dataPtr++;
        }

        objData = object->omObj1 = omAddObj(0x4000, 1, motionCnt, -1, func_800D85B4_C0384_name_81);

        mdlIdx = func_8000B108_BD08(arg0, 0x6A9);
        omSetStatBit(objData, 0x80);
        objData->model[0] = mdlIdx;
        omSetRot(objData, 0.0f, 0.0f, 0.0f);
        func_8001C814_1D414(mdlIdx, 2, 2);
        func_8001C8A8_1D4A8(mdlIdx, 1);
        Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);
        if (HmfModelData[mdlIdx].unk02 != 0xFF) {
            object->unk46 = MBDMotionLock(HmfModelData[mdlIdx].unk02);
        }

        work = HuMemMemoryAllocTemp(sizeof(UnkObj));
        objData->data = work;
        work->unk_00 = object;
        work->unk_04 = arg2;

        for (i = 0; i < motionCnt; i++) {
            objData->motion[i] = func_800D7DC8_BFB98_name_81(*dataPtr++);
        }

        if ((arg1 >= 0) && (arg3 > 0.0f)) {
            objData = object->omObj2 = omAddObj(0x4000, 1, 0, -1, func_800D87E8_C05B8_name_81);
            mdlIdx = func_8000B108_BD08(arg1, 0x229);
            omSetStatBit(objData, 0x80);
            objData->model[0] = mdlIdx;
            omSetRot(objData, 0.0f, 0.0f, 0.0f);
            func_8001C8A8_1D4A8(mdlIdx, 1);
            Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);

            work = HuMemMemoryAllocTemp(sizeof(UnkObj));
            objData->data = work;
            work->unk_00 = object;
            work->unk_04 = arg3;
        } else {
            object->omObj2 = NULL;
        }
    }
    return object;
}

void func_800D85A8_C0378_name_81(f32 f){
    D_80100E10_E8BE0_name_81 = f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D85B4_C0384_name_81);

void func_800D87DC_C05AC_name_81(f32 f){
    D_80100E14_E8BE4_name_81 = f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D87E8_C05B8_name_81);

void MBDModelTempAllocFree(ObjectDuel* arg0) {
    func_8001C514_1D114(arg0->omObj1->model[0]);
    
    if (arg0->omObj2 != NULL) {
        func_8001C514_1D114(arg0->omObj2->model[0]);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D898C_C075C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D8B18_C08E8_name_81);

void MBDModelAttrSetDispOn(ObjectDuel* arg0) {
    func_8001C258_1CE58(arg0->omObj1->model[0], 4, 0);
    if (arg0->omObj2 != NULL) {
        func_8001C258_1CE58(arg0->omObj2->model[0], 4, 0);
    }
}

void MBDModelDispOn(ObjectDuel* arg0){
    MBDModelAttrSetDispOn(arg0);
    arg0->flags |= 8;
}

void MBDModelAttrSetDispOff(ObjectDuel* arg0) {
    func_8001C258_1CE58(arg0->omObj1->model[0], 4, 4);
    if (arg0->omObj2 != NULL) {
        func_8001C258_1CE58(arg0->omObj2->model[0], 4, 4);
    }
}

void MBDModelDispOff(ObjectDuel* arg0) {
    MBDModelAttrSetDispOff(arg0);
    arg0->flags &= ~8;
}

void MBDModelKill(ObjectDuel* arg0) {
    s32 i;

    if (D_801029C0_EA790_name_81 != NULL) {
        if (arg0->prev != NULL) {
            arg0->prev->next = arg0->next;
        }
        if (arg0->next != NULL) {
            arg0->next->prev = arg0->prev;
        } else {
            D_801029C0_EA790_name_81 = arg0->prev;
        }
        func_8001F304_1FF04(arg0->omObj1->model[0], -1);
        func_8001ACDC_1B8DC(arg0->omObj1->model[0]);
        if (arg0->omObj2 != NULL) {
            func_8001ACDC_1B8DC(arg0->omObj2->model[0]);
        }

        for (i = 0; i < arg0->omObj1->mtncnt; i++) {
            MBDMotionKill(arg0->omObj1->motion[i]);
        }
        
        if (arg0->unk46 != -1) {
            MBDMotionKill(arg0->unk46);
        }
        
        HuMemMemoryFreeTemp(arg0->omObj1->data);
        
        arg0->omObj1->data = NULL;
        omDelObj(arg0->omObj1);
        
        if (arg0->omObj2 != NULL) {
            HuMemMemoryFreeTemp(arg0->omObj2->data);
            arg0->omObj2->data = NULL;
            omDelObj(arg0->omObj2);
        }
        HuMemMemoryFreeTemp(arg0);
        D_801029C4_EA794_name_81 -= 1;
    }
}

s32 func_800D9098_C0E68_name_81(ObjectDuel* arg0) {
    ObjectDuel* var_v0;

    var_v0 = D_801029C0_EA790_name_81;
    
    while (var_v0 != NULL) {
        if (var_v0 == arg0) {
            return 1;
        }
        var_v0 = var_v0->prev;       
    }
    
    return 0;
}

void MBDMotionSet(ObjectDuel *arg0, s16 arg1, u16 arg2) { // MBDMotionSet
    u16 var_v1;
    s16 mtncnt;

    if (arg0->mtncnt == -1) {
        return;
    }

    if (arg1 == -1) {
        var_v1 = arg0->unk46;
        arg0->unk48 = arg1;
    } else {
        mtncnt = arg0->mtncnt;
        if (arg1 > mtncnt - 1) {
            return;
        }
        var_v1 = arg0->omObj1->motion[arg1];
        arg0->unk48 = arg1;
    }
    func_8001F304_1FF04(arg0->omObj1->model[0], var_v1);
    func_8001C814_1D414(arg0->omObj1->model[0], -1, arg2);
}

void MBDMotionShiftSet(ObjectDuel* arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    s16 var;
    
    if (arg0->mtncnt == -1) {
        return;
    }

    if (arg1 == -1) {
        var = arg0->unk46;
        arg0->unk48 = arg1;
    } else {
        if (arg1 > arg0->mtncnt - 1) {
            return;
        }
        var = arg0->omObj1->motion[arg1];
        arg0->unk48 = arg1;
    }
    func_8001C624_1D224(arg0->omObj1->model[0], var, arg2, arg3, arg4);
}

u16 MBDMotionCheck(ObjectDuel* arg0) {
    u16 ret = 0;
    
    if (HmfModelData[arg0->omObj1->model[0]].unk40 == D_800CCF58_CDB58[HmfModelData[arg0->omObj1->model[0]].unk02].unk02) {
        ret = 1;
    }
    return ret;
}

u16 func_800D92A8_C1078_name_81(Object* arg0) {
    u16 ret;

    ret = 0;
    if (HmfModelData[arg0->omObj1->model[0]].unk40 == 0.0f) {
        ret = 1;
    }
    return ret;
}

static void func_800D92F8_C10C8_name_81(omObjData* arg0) {
    ObjectDuel* temp_s1;

    temp_s1 = arg0->data;
    
    if (--arg0->work[1] == 0) {
        temp_s1->rot.x = arg0->rot.x;
        temp_s1->rot.y = arg0->rot.y;
        temp_s1->rot.z = arg0->rot.z;
        arg0->data = NULL;
        omDelObj(arg0);
        return;
    }
    
    arg0->scale.y += arg0->scale.x;
    temp_s1->rot.x = HuMathSin(arg0->scale.y);
    temp_s1->rot.y = 0.0f;
    temp_s1->rot.z = HuMathCos(arg0->scale.y);
}

omObjData* func_800D9384_C1154_name_81(ObjectDuel* arg0, Vec* arg1, s32 arg2) {
    Vec sp18;
    f32 var_f20;
    f32 var_f4;
    omObjData* temp_v0;

    MBDVecDirGet(&arg0->coords, arg1, &sp18);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800D92F8_C10C8_name_81);
    temp_v0->work[1] = arg2;
    temp_v0->rot.x = sp18.x;
    temp_v0->rot.y = sp18.y;
    temp_v0->rot.z = sp18.z;
    var_f20 = MBDVecAngleGet(&arg0->rot);
    var_f4 = MBDVecAngleGet(&sp18);
    if ((var_f4 < var_f20)) {
        if ((var_f20 - var_f4) >= 180.0f) {
            var_f4 += 360.0f;
        }
    } else if ((var_f4 - var_f20 ) >= 180.0f) {
        var_f20 += 360.0f;
    }
    temp_v0->scale.y = var_f20;
    temp_v0->scale.x = (var_f4 - var_f20) / (f32) arg2;
    temp_v0->data = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D94C4_C1294_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BFB40", func_800D9668_C1438_name_81);

void func_800D96F4_C14C4_name_81(void) {
    ObjectDuel *obj = *(ObjectDuel **)HuPrcCurrentGet()->user_data;

    func_8001C814_1D414(obj->omObj1->model[0], 3, 0);
    func_800EFABC_D788C_name_81(obj);
    MBDModelKill(obj);
    omDelPrcObj(NULL);
}

void func_800D974C_C151C_name_81(Object *arg) {
    Process *temp = omAddPrcObj(func_800D96F4_C14C4_name_81, 0, 0, 0x40);
    s32 *data = HuMemMemoryAlloc(temp->heap, 0x10);

    temp->user_data = data;
    *data = (s32)arg;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C48_E9A18_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C4C_E9A1C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C50_E9A20_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BFB40", D_80101C54_E9A24_name_81);
