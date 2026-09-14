#include "common.h"
#include "ovl_81.h"

UnkBoard2* func_800D6EC8_BEC98_name_81(UnkEA790Struct*, s16);

static void func_800D6EE0_BECB0_name_81(void) {
    s32 mesg;
    s32 ret;
    UnkEA790Struct *work;
    Vec *scale;
    f32 scaleX;
    f32 scaleZ;
    f32 speed;
    f32 angle;
    s16 timer;
    s16 sel;
    s16 delay;
    s32 i;

    timer = -1;
    work = HuPrcCurrentGet()->user_data;
    sel = work->unk_0C;
    angle = 0.0f;
    delay = 0;

    while (timer != 0) {
        HuPrcVSleep();

        if (timer < 0) {
            if (delay == 0) {
                ret = osRecvMesg(&work->unk10, (OSMesg *)&mesg, 0);
                if (ret == -1) {
                    mesg = ret;
                }
                if (work->unk_00 & 1) {
                    delay = 8;
                }
            } else {
                mesg = -1;
                delay--;
            }

            switch (mesg) {
            case -1:
                break;
            case -2:
                work->unk_0C++;
                if (work->unk_0C >= work->unk_02) {
                    work->unk_0C = 0;
                }
                break;
            case -3:
                work->unk_0C--;
                if (work->unk_0C < 0) {
                    work->unk_0C = work->unk_02 - 1;
                }
                break;
            case -4:
                if (work->unk_0C >= 0) {
                    HuAudFXPlay(3);
                    mbCameraBtnF = 0;
                    D_800D51F8_D5DF8 = 0;
                    timer = 30;
                }
                break;
            case -5:
                HuAudFXPlay(4);
                work->unk_0C = -1;
                timer = 0;
                break;
            case -6:
                work->unk_0C = -1;
                break;
            default:
                if (mesg < work->unk_02) {
                    work->unk_0C = mesg;
                }
                break;
            }

            if (sel != work->unk_0C) {
                HuAudFXPlay(1);
                if (sel >= 0) {
                    HuVecCopyXYZ(&func_800D6EC8_BEC98_name_81(work, sel)->obj->scale, 1.0f, 1.0f, 1.0f);
                    angle = 0.0f;
                }
                sel = work->unk_0C;
            }
        }

        if (sel >= 0) {
            f32 temp;
            if (timer >= 0) {
                speed = 50.0f;
            } else {
                speed = 25.0f;
            }
            angle += speed;
            temp = 360.0f;
            if (angle > temp) {
                angle -= temp;
            }
            scaleZ = (HuMathCos(angle) * 0.3f) + 1.2f;
            scaleX = (HuMathCos(angle) * 0.2f) + 1.2f;
            HuVecCopyXYZ(&func_800D6EC8_BEC98_name_81(work, sel)->obj->scale, scaleX, 1.0f, scaleZ);
        }

        if (timer > 0) {
            timer--;
            scaleZ = timer * (1.0f / 30.0f);
            for (i = 0; i < work->unk_02; i++) {
                if (i != sel) {
                    scale = &func_800D6EC8_BEC98_name_81(work, i)->obj->scale;
                    HuVecMulScalar(scale, scaleZ, scale);
                }
            }
        }
    }
    omDelPrcObj(NULL);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7250_BF020_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7280_BF050_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D742C_BF1FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7518_BF2E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7568_BF338_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D75E8_BF3B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D76A0_BF470_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D76D0_BF4A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7828_BF5F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7898_BF668_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7934_BF704_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D79D0_BF7A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7A6C_BF83C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BECB0", func_800D7CEC_BFABC_name_81);
