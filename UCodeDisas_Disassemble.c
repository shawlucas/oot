void UCodeDisas_Disassemble(UCodeDisas *disassembler, Gfx *gfxP) {
    u32 sp384;
    u16 sp382;
    u8 sp381;
    s32 sp378;
    u8 sp370;
    ? sp368;
    s32 sp358;
    s32 sp350;
    s32 sp348;
    s32 sp340;
    s32 sp338;
    ? sp330;
    s32 sp328;
    s32 sp2F8;
    s32 sp2EC;
    ? sp2D4;
    f32 sp290;
    ? sp27C;
    ?32 sp278;
    ? sp270;
    ? sp250;
    s32 sp238;
    ? sp230;
    ? sp21C;
    s32 sp218;
    u8 sp217;
    u32 sp214;
    ? sp20C;
    ? sp200;
    ? sp1F8;
    ? sp1F0;
    ? sp1E8;
    ? sp1E0;
    ? sp1D8;
    ? sp1D0;
    ? sp1C8;
    ? sp1C0;
    ? sp1B8;
    ? sp1B0;
    ? sp198;
    ? sp18C;
    s32 sp178;
    s32 sp174;
    s32 sp16C;
    s32 sp164;
    s32 sp160;
    s32 sp15C;
    s32 sp158;
    s32 sp154;
    s32 sp150;
    s32 sp14C;
    Gfx *temp_v0;
    MatrixInternal *temp_s4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 temp_s1_6;
    s32 temp_s1_7;
    s32 temp_s2;
    s32 temp_s4_2;
    s32 temp_s5;
    s32 temp_t0;
    s32 temp_t0_10;
    s32 temp_t0_11;
    s32 temp_t0_12;
    s32 temp_t0_13;
    s32 temp_t0_14;
    s32 temp_t0_15;
    s32 temp_t0_16;
    s32 temp_t0_17;
    s32 temp_t0_18;
    s32 temp_t0_19;
    s32 temp_t0_20;
    s32 temp_t0_21;
    s32 temp_t0_22;
    s32 temp_t0_23;
    s32 temp_t0_24;
    s32 temp_t0_25;
    s32 temp_t0_26;
    s32 temp_t0_27;
    s32 temp_t0_28;
    s32 temp_t0_29;
    s32 temp_t0_2;
    s32 temp_t0_30;
    s32 temp_t0_31;
    s32 temp_t0_32;
    s32 temp_t0_33;
    s32 temp_t0_34;
    s32 temp_t0_35;
    s32 temp_t0_36;
    s32 temp_t0_37;
    s32 temp_t0_38;
    s32 temp_t0_39;
    s32 temp_t0_3;
    s32 temp_t0_40;
    s32 temp_t0_4;
    s32 temp_t0_5;
    s32 temp_t0_6;
    s32 temp_t0_7;
    s32 temp_t0_8;
    s32 temp_t0_9;
    s32 temp_t1;
    s32 temp_t2_2;
    s32 temp_t4;
    s32 temp_t9_2;
    s32 temp_t9_3;
    s32 temp_v0_11;
    s32 temp_v0_13;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    u16 temp_v0_12;
    u16 temp_v0_4;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u32 temp_a1_4;
    u32 temp_a1_5;
    u32 temp_s0_5;
    u32 temp_t2;
    u32 temp_t6;
    u32 temp_t6_2;
    u32 temp_t7;
    u32 temp_t7_2;
    u32 temp_t7_3;
    u32 temp_t7_4;
    u32 temp_t9;
    u32 temp_v0_3;
    u32 temp_v0_7;
    u32 temp_v0_8;
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_a3;
    void *temp_v0_10;
    s32 phi_s0;
    s32 phi_v0;
    s32 phi_v0_2;
    void *phi_a3;
    void *phi_v1;
    s32 phi_v0_3;
    u32 phi_a1;
    void *phi_a3_2;
    void *phi_v1_2;
    s32 phi_v0_4;
    u32 phi_a1_2;
    s8 *phi_a1_3;
    s8 *phi_s5;
    s8 *phi_s1;
    s8 *phi_s5_2;
    s8 *phi_s1_2;
    s32 phi_t0;
    s32 phi_s0_2;
    s32 phi_s1_3;
    s32 phi_t0_2;
    s32 phi_t0_3;
    s8 *phi_s1_4;
    s8 *phi_s1_5;
    s32 phi_s1_6;
    s32 phi_t0_4;
    s8 *phi_s1_7;
    s32 phi_t0_5;
    s8 *phi_s1_8;
    s8 *phi_t0_6;
    s8 *phi_s0_3;
    s8 *phi_t0_7;
    s8 *phi_s0_4;
    s8 *phi_s0_5;
    s8 *phi_s0_6;
    s8 *phi_v1_3;
    s8 *phi_s1_9;
    s8 *phi_v1_4;
    s8 *phi_s1_10;
    s8 *phi_s1_11;
    s8 *phi_s2;
    s8 *phi_s2_2;
    s8 *phi_s5_3;

    sp378 = 0;
loop_1:
    disassembler->dlCnt = disassembler->dlCnt + 1;
    temp_v0 = UCodeDisas_TranslateAddr(disassembler, gfxP);
    gfxP = temp_v0;
    if (disassembler->enableLog != 0) {
        osSyncPrintf(&D_80147E58, temp_v0);
    }
    sp370.unk0 = (u32) gfxP->words.w0;
    sp370.unk4 = (u32) gfxP->words.w1;
    temp_s4 = UCodeDisas_TranslateAddr(disassembler, sp374);
    if (disassembler->enableLog != 0) {
        osSyncPrintf(&D_80147E60, sp370.unk0, sp374);
    }
    temp_v0_2 = disassembler->dlDepth;
    phi_s0 = 0;
    phi_v0 = temp_v0_2;
    phi_v0_2 = temp_v0_2;
    if (temp_v0_2 > 0) {
loop_6:
        if (disassembler->enableLog != 0) {
            osSyncPrintf(&D_80147E6C);
            phi_v0 = disassembler->dlDepth;
        }
        temp_s0 = phi_s0 + 1;
        phi_s0 = temp_s0;
        phi_v0_2 = phi_v0;
        if (temp_s0 < phi_v0) {
            goto loop_6;
        }
    }
    if ((s32) sp370 > 0) {
        temp_t6 = sp370 - 0xDD;
        if (temp_t6 < 0x23U) {
            goto **(&jtbl_8014927C + (temp_t6 * 4)); // switch 1
block_12:
            if (sp370 != 0) {
                goto block_260;
            case 3: // switch 1
                temp_t0 = disassembler->enableLog;
                phi_t0_5 = temp_t0;
                if (temp_t0 != 0) {
                    osSyncPrintf(&D_80147E70);
                    goto block_472;
                case 1: // switch 1
                    sp368.unk0 = (u32) gfxP->words.w0;
                    sp368.unk4 = (u32) gfxP->words.w1;
                    if (sp369 != 0) {
                        if (sp369 != 1) {
block_472:
                            phi_t0_5 = disassembler->enableLog;
                        } else {
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf(&D_80147E98, sp36C);
                            }
                            gfxP = temp_s4 - 8;
                            goto block_473;
                        case 4: // switch 1
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf(&D_80147EB0, sp374);
                            }
                            sp384 = sp374;
                            goto block_473;
                        case 7: // switch 1
                            sp358.unk0 = (u32) gfxP->words.w0;
                            sp358.unk4 = (u32) gfxP->words.w1;
                            sp358.unk8 = (s32) gfxP->unk8;
                            sp358.unkC = (s32) gfxP->unkC;
                            if (disassembler->enableLog != 0) {
                                temp_v0_3 = gfxP->unkC;
                                temp_v1 = gfxP->unk14;
                                osSyncPrintf(&D_80147EC4, (u32) (sp358 << 8) >> 0x14, sp358 & 0xFFF, (u32) (sp35C << 8) >> 0x14, sp35C & 0xFFF, (u8) sp35C & 7, temp_v0_3 >> 0x10, temp_v0_3 & 0xFFFF, temp_v1 >> 0x10, temp_v1 & 0xFFFF);
                            }
                            gfxP = gfxP + 0x10;
                            disassembler->pipeSyncRequired = 1;
                            goto block_472;
                        case 0: // switch 1
                            temp_v0_4 = sp370.unk2;
                            temp_t0_2 = disassembler->enableLog;
                            if (temp_v0_4 == 0x7FF) {
                                if (temp_t0_2 != 0) {
                                    osSyncPrintf(&D_80147EF8, sp374, sp384);
                                }
                            } else if (temp_t0_2 != 0) {
                                osSyncPrintf(&D_80147F18, sp374, sp384, temp_v0_4 + 1);
                            }
                            UCodeDisas_SetCurUCodeImpl(disassembler, UCodeDisas_TranslateAddr(disassembler, sp374));
                            disassembler->loaducodeCnt = disassembler->loaducodeCnt + 1;
                            phi_t0_5 = disassembler->enableLog;
                            goto block_473;
                        case 2: // switch 1
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf(&D_80147F44);
                                phi_v0_2 = disassembler->dlDepth;
                            }
                            if (phi_v0_2 <= 0) {
                                sp378 = 1;
                            } else {
                                temp_s1 = phi_v0_2 - 1;
                                disassembler->dlDepth = temp_s1;
                                gfxP = (&disassembler->segments[temp_s1])[0x10] - 8;
                                goto block_472;
                            case 24: // switch 1
                                sp350.unk0 = (u32) gfxP->words.w0;
                                sp350.unk4 = (u32) gfxP->words.w1;
                                if (disassembler->enableLog != 0) {
                                    temp_t9_2 = (s32) sp354;
                                    osSyncPrintf(&D_80147F5C, (u32) sp351 >> 5, (u32) (sp350 << 0xB) >> 0x1E, (u32) (sp350 << 0xE) >> 0x17, sp350 & 0x1FF, sp354 & 7, (u32) sp355 >> 4, (((u32) (temp_t9_2 << 0xC) >> 0x1F) * 2) + ((u32) (temp_t9_2 << 0xD) >> 0x1F), (u32) (temp_t9_2 << 0xE) >> 0x1C, (u32) (temp_t9_2 << 0x12) >> 0x1C, (((u32) (temp_t9_2 << 0x16) >> 0x1F) * 2) + (sp356 & 1), (u32) sp357 >> 4, temp_t9_2 & 0xF);
                                }
                                phi_t0_5 = disassembler->enableLog;
                                if (disassembler->tileSyncRequired != 0) {
                                    if (disassembler->enableLog != 0) {
                                        osSyncPrintf(&D_80147F90);
                                    }
                                    disassembler->syncErr = disassembler->syncErr + 1;
                                    phi_t0_5 = disassembler->enableLog;
                                    goto block_473;
                                case 23: // switch 1
                                    sp348.unk0 = (u32) gfxP->words.w0;
                                    sp348.unk4 = (u32) gfxP->words.w1;
                                    temp_t0_3 = disassembler->enableLog;
                                    phi_t0_5 = temp_t0_3;
                                    if (temp_t0_3 != 0) {
                                        osSyncPrintf(&D_80147FAC, (u8) sp34C & 7, (u32) (sp348 << 8) >> 0x14, sp348 & 0xFFF, (u32) (sp34C << 8) >> 0x14, sp34C & 0xFFF);
                                        phi_t0_5 = disassembler->enableLog;
                                        goto block_473;
                                    case 22: // switch 1
                                        sp340.unk0 = (u32) gfxP->words.w0;
                                        sp340.unk4 = (u32) gfxP->words.w1;
                                        if (disassembler->enableLog != 0) {
                                            osSyncPrintf(&D_80147FCC, (u8) sp344 & 7, (u32) (sp340 << 8) >> 0x14, sp340 & 0xFFF, (u32) (sp344 << 8) >> 0x14, sp344 & 0xFFF);
                                        }
                                        if (disassembler->loadSyncRequired != 0) {
                                            if (disassembler->enableLog != 0) {
                                                osSyncPrintf(&D_80147FEC);
                                            }
                                            disassembler->syncErr = disassembler->syncErr + 1;
                                        }
                                        disassembler->pipeSyncRequired = 1;
                                        goto block_472;
                                    case 21: // switch 1
                                        sp338.unk0 = (u32) gfxP->words.w0;
                                        sp338.unk4 = (u32) gfxP->words.w1;
                                        temp_t0_4 = disassembler->enableLog;
                                        phi_t0_5 = temp_t0_4;
                                        if (temp_t0_4 != 0) {
                                            osSyncPrintf(&D_80148008, (u8) sp33C & 7, (u32) (sp338 << 8) >> 0x14, sp338 & 0xFFF, (u32) (sp33C << 8) >> 0x14, sp33C & 0xFFF);
                                            phi_t0_5 = disassembler->enableLog;
                                            goto block_473;
                                        case 19: // switch 1
                                            sp330.unk0 = (u32) gfxP->words.w0;
                                            sp330.unk4 = (u32) gfxP->words.w1;
                                            temp_t0_5 = disassembler->enableLog;
                                            phi_t0_5 = temp_t0_5;
                                            if (temp_t0_5 != 0) {
                                                osSyncPrintf(&D_8014802C, (u8) sp334 & 7, (u32) ((u32) (sp334 << 8) >> 0x14) >> 2);
                                                phi_t0_5 = disassembler->enableLog;
                                                goto block_473;
                                            case 31: // switch 1
                                                sp328.unk0 = (u32) gfxP->words.w0;
                                                sp328.unk4 = (u32) gfxP->words.w1;
                                                if (disassembler->enableLog != 0) {
                                                    sp14C = UCodeDisas_ParseCombineColor((u32) sp329 >> 4, 1);
                                                    sp150 = UCodeDisas_ParseCombineColor(sp32C >> 0x1C, 2);
                                                    sp154 = UCodeDisas_ParseCombineColor((u32) (sp328 << 0xC) >> 0x1B, 3);
                                                    sp158 = UCodeDisas_ParseCombineColor((u32) (sp32C << 0xE) >> 0x1D, 4);
                                                    sp15C = UCodeDisas_ParseCombineAlpha((u32) (sp328 << 0x11) >> 0x1D, 1);
                                                    sp160 = UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x11) >> 0x1D, 2);
                                                    sp164 = UCodeDisas_ParseCombineAlpha((u32) (sp328 << 0x14) >> 0x1D, 3);
                                                    temp_s4_2 = UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x14) >> 0x1D, 4);
                                                    sp16C = UCodeDisas_ParseCombineColor((u32) (sp328 << 0x17) >> 0x1C, 1);
                                                    temp_s2 = UCodeDisas_ParseCombineColor((u8) sp32C & 0xF, 2);
                                                    sp174 = UCodeDisas_ParseCombineColor(sp328 & 0x1F, 3);
                                                    sp178 = UCodeDisas_ParseCombineColor((u32) (sp32C << 0x17) >> 0x1D, 4);
                                                    temp_s5 = UCodeDisas_ParseCombineAlpha((u32) sp32D >> 5, 1);
                                                    temp_s1_2 = UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x1A) >> 0x1D, 2);
                                                    temp_s0_2 = UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0xB) >> 0x1D, 3);
                                                    osSyncPrintf(&D_80148044, sp14C, sp150, sp154, sp158, sp15C, sp160, sp164, temp_s4_2, sp16C, temp_s2, sp174, sp178, temp_s5, temp_s1_2, temp_s0_2, UCodeDisas_ParseCombineAlpha(sp32C & 7, 4));
                                                }
                                                phi_t0_5 = disassembler->enableLog;
                                                if (disassembler->pipeSyncRequired != 0) {
                                                    if (disassembler->enableLog != 0) {
                                                        osSyncPrintf(&D_8014808C);
                                                    }
                                                    disassembler->syncErr = disassembler->syncErr + 1;
                                                    phi_t0_5 = disassembler->enableLog;
                                                    goto block_473;
                                                case 6: // switch 1
                                                    temp_s1_3 = (&sp370)[3] + 1;
                                                    temp_s0_3 = (-(s32) (&sp370)[2] - temp_s1_3) + 0x20;
                                                    temp_t0_6 = disassembler->enableLog;
                                                    phi_a3 = &sUCodeDisasModeHMacros;
                                                    phi_a1 = 0U;
loop_68:
                                                    if (temp_s0_3 == phi_a3->unk4) {
                                                        phi_v1 = (((((phi_a1 * 4) - phi_a1) * 4) - phi_a1) * 4) + &sUCodeDisasModeHMacros;
                                                        phi_v0_3 = 0;
loop_70:
                                                        if (sp374 == phi_v1->unk10) {
                                                            if (temp_t0_6 != 0) {
                                                                osSyncPrintf(&D_80148374, phi_a3->unk0, (phi_a3 + phi_v0_3)->unkC, phi_a3);
                                                            }
                                                        } else {
                                                            temp_v0_5 = phi_v0_3 + 8;
                                                            phi_v1 = phi_v1 + 8;
                                                            phi_v0_3 = temp_v0_5;
                                                            if (temp_v0_5 != 0x20) {
                                                                goto loop_70;
                                                            }
block_74:
                                                            temp_a1_2 = phi_a1 + 1;
                                                            phi_a3 = phi_a3 + 0x2C;
                                                            phi_a1 = temp_a1_2;
                                                            if (temp_a1_2 < 0xCU) {
                                                                goto loop_68;
                                                            }
                                                            if (temp_t0_6 != 0) {
                                                                osSyncPrintf(&D_80148380, temp_s0_3, temp_s1_3, sp374);
                                                            }
                                                        }
                                                    } else {
                                                        goto block_74;
                                                    }
                                                    temp_t7_3 = disassembler->modeH & (((1 - (1 << temp_s1_3)) << temp_s0_3) - 1);
                                                    disassembler->modeH = temp_t7_3;
                                                    disassembler->modeH = temp_t7_3 | sp374;
                                                    if (disassembler->pipeSyncRequired != 0) {
                                                        if (disassembler->enableLog != 0) {
                                                            osSyncPrintf(&D_801483A4);
                                                        }
                                                        disassembler->syncErr = disassembler->syncErr + 1;
                                                    }
                                                    goto block_472;
                                                case 5: // switch 1
                                                    temp_s1_4 = (&sp370)[3] + 1;
                                                    temp_s0_4 = (-(s32) (&sp370)[2] - temp_s1_4) + 0x20;
                                                    temp_t0_7 = disassembler->enableLog;
                                                    if (temp_s0_4 == 3) {
                                                        if (temp_t0_7 != 0) {
                                                            osSyncPrintf((const char *) "\ngsDPSetRenderBlender(");
                                                        }
                                                        UCodeDisas_ParseRenderMode(disassembler, sp374);
                                                        if (disassembler->enableLog != 0) {
                                                            osSyncPrintf((const char *) "\n),");
                                                        }
                                                    } else {
                                                        phi_a3_2 = &sUCodeDisasModeLMacros;
                                                        phi_a1_2 = 0U;
loop_88:
                                                        if (temp_s0_4 == phi_a3_2->unk4) {
                                                            phi_v1_2 = (((((phi_a1_2 * 4) - phi_a1_2) * 4) - phi_a1_2) * 4) + &sUCodeDisasModeLMacros;
                                                            phi_v0_4 = 0;
loop_90:
                                                            if (sp374 == phi_v1_2->unk10) {
                                                                if (temp_t0_7 != 0) {
                                                                    osSyncPrintf((const char *) "gsDP%s(%s),", phi_a3_2->unk0, (phi_a3_2 + phi_v0_4)->unkC, phi_a3_2);
                                                                }
                                                            } else {
                                                                temp_v0_6 = phi_v0_4 + 8;
                                                                phi_v1_2 = phi_v1_2 + 8;
                                                                phi_v0_4 = temp_v0_6;
                                                                if (temp_v0_6 != 0x20) {
                                                                    goto loop_90;
                                                                }
block_94:
                                                                temp_a1_3 = phi_a1_2 + 1;
                                                                phi_a3_2 = phi_a3_2 + 0x2C;
                                                                phi_a1_2 = temp_a1_3;
                                                                if (temp_a1_3 < 2U) {
                                                                    goto loop_88;
                                                                }
                                                                if (temp_t0_7 != 0) {
                                                                    osSyncPrintf((const char *) "gsSPSetOtherModeL(%d, %d, 0x%08x),", temp_s0_4, temp_s1_4, sp374);
                                                                }
                                                            }
                                                        } else {
                                                            goto block_94;
                                                        }
                                                    }
                                                    temp_t6_2 = disassembler->modeL & (((1 - (1 << temp_s1_4)) << temp_s0_4) - 1);
                                                    disassembler->modeL = temp_t6_2;
                                                    disassembler->modeL = temp_t6_2 | sp374;
                                                    if (disassembler->pipeSyncRequired != 0) {
                                                        if (disassembler->enableLog != 0) {
                                                            osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                        }
                                                        disassembler->syncErr = disassembler->syncErr + 1;
                                                    }
                                                    goto block_472;
                                                case 18: // switch 1
                                                    if (disassembler->enableLog != 0) {
                                                        osSyncPrintf((const char *) "gsDPSetOtherMode(0x%08x, 0x%08x),", sp370.unk0 & 0xFFFFFF, sp374);
                                                    }
                                                    disassembler->modeH = sp370.unk0 & 0xFFF;
                                                    disassembler->modeL = sp374;
                                                    if (disassembler->pipeSyncRequired != 0) {
                                                        if (disassembler->enableLog != 0) {
                                                            osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                        }
                                                        disassembler->syncErr = disassembler->syncErr + 1;
                                                    }
                                                    goto block_472;
                                                case 16: // switch 1
                                                    sp2F8.unk0 = (u32) gfxP->words.w0;
                                                    sp2F8.unk4 = (u32) gfxP->words.w1;
                                                    if (sp2FC == 0) {
                                                        phi_a1_3 = "G_SC_NON_INTERLACE";
                                                    } else {
                                                        if (sp2FC == 3) {
                                                            phi_s1_8 = "G_SC_ODD_INTERLACE";
                                                        } else {
                                                            if (sp2FC == 2) {
                                                                phi_s0_6 = "G_SC_EVEN_INTERLACE";
                                                            } else {
                                                                phi_s0_6 = "???";
                                                            }
                                                            phi_s1_8 = phi_s0_6;
                                                        }
                                                        phi_a1_3 = phi_s1_8;
                                                    }
                                                    temp_t9_3 = (s32) sp2FC;
                                                    temp_t1 = (s32) (sp2F8 << 0x1E) >> 0x1E;
                                                    temp_v1_2 = (s32) (sp2F8 << 0x12) >> 0x1E;
                                                    if ((temp_v1_2 | temp_t1 | ((s32) (temp_t9_3 << 0x12) >> 0x1E) | ((s32) (temp_t9_3 << 0x1E) >> 0x1E)) != 0) {
                                                        temp_t0_8 = disassembler->enableLog;
                                                        phi_t0_5 = temp_t0_8;
                                                        if (temp_t0_8 != 0) {
                                                            temp_t2_2 = (s32) sp2FC;
                                                            osSyncPrintf((const char *) "gsDPSetScissorFrac(%s, %d, %d, %d, %d),", phi_a1_3, (((s32) (sp2F8 << 8) >> 0x16) * 4) + temp_v1_2, (((s32) (sp2F8 << 0x14) >> 0x16) * 4) + temp_t1, (((s32) (temp_t2_2 << 8) >> 0x16) * 4) + ((s32) (temp_t2_2 << 0x12) >> 0x1E), (((s32) (temp_t2_2 << 0x14) >> 0x16) * 4) + ((s32) (temp_t2_2 << 0x1E) >> 0x1E));
                                                            goto block_472;
                                                        }
                                                    } else {
                                                        temp_t0_9 = disassembler->enableLog;
                                                        phi_t0_5 = temp_t0_9;
                                                        if (temp_t0_9 != 0) {
                                                            temp_t4 = (s32) sp2FC;
                                                            osSyncPrintf((const char *) "gsDPSetScissor(%s, %d, %d, %d, %d),", phi_a1_3, (s32) (sp2F8 << 8) >> 0x16, (s32) (sp2F8 << 0x14) >> 0x16, (s32) (temp_t4 << 8) >> 0x16, (s32) (temp_t4 << 0x14) >> 0x16);
                                                            phi_t0_5 = disassembler->enableLog;
                                                            goto block_473;
                                                        case 25: // switch 1
                                                            sp2EC.unk0 = (u32) gfxP->words.w0;
                                                            sp2EC.unk4 = (u32) gfxP->words.w1;
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "gsDPFillRectangle(%d, %d, %d, %d),", (s32) (sp2F0 << 8) >> 0x16, (s32) (sp2F0 << 0x14) >> 0x16, (s32) (sp2EC << 8) >> 0x16, (s32) (sp2EC << 0x14) >> 0x16);
                                                            }
                                                            disassembler->pipeSyncRequired = 1;
                                                            goto block_472;
                                                        case 34: // switch 1
                                                            temp_v0_7 = sp370.unk0;
                                                            temp_v1_3 = ((u32) (temp_v0_7 & 0xE00000) >> 0x15) & 0xFF;
                                                            temp_a0 = ((u32) (temp_v0_7 & 0x180000) >> 0x13) & 0xFF;
                                                            if (disassembler->enableLog != 0) {
                                                                if (temp_v1_3 == 0) {
                                                                    phi_s5 = "RGBA";
                                                                } else {
                                                                    if (temp_v1_3 == 1) {
                                                                        phi_t0_6 = "YUV";
                                                                    } else {
                                                                        if (temp_v1_3 == 2) {
                                                                            phi_v1_3 = "CI";
                                                                        } else {
                                                                            if (temp_v1_3 == 3) {
                                                                                phi_s2 = "IA";
                                                                            } else {
                                                                                phi_s2 = "I";
                                                                            }
                                                                            phi_v1_3 = phi_s2;
                                                                        }
                                                                        phi_t0_6 = phi_v1_3;
                                                                    }
                                                                    phi_s5 = phi_t0_6;
                                                                }
                                                                if (temp_a0 == 0) {
                                                                    phi_s1 = "4b";
                                                                } else {
                                                                    if (temp_a0 == 1) {
                                                                        phi_s0_3 = "8b";
                                                                    } else {
                                                                        if (temp_a0 == 2) {
                                                                            phi_s1_9 = "16b";
                                                                        } else {
                                                                            phi_s1_9 = "32b";
                                                                        }
                                                                        phi_s0_3 = phi_s1_9;
                                                                    }
                                                                    phi_s1 = phi_s0_3;
                                                                }
                                                                osSyncPrintf((const char *) "gsDPSetColorImage(G_IM_FMT_%s, G_IM_SIZ_%s, %d, 0x%08x(0x%08x) ),", phi_s5, phi_s1, (sp370.unk2 & 0xFFF) + 1, sp374, temp_s4);
                                                            }
                                                            phi_t0_5 = disassembler->enableLog;
                                                            if (disassembler->pipeSyncRequired != 0) {
                                                                if (disassembler->enableLog != 0) {
                                                                    osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                }
                                                                disassembler->syncErr = disassembler->syncErr + 1;
                                                                phi_t0_5 = disassembler->enableLog;
                                                                goto block_473;
                                                            case 33: // switch 1
                                                                if (disassembler->enableLog != 0) {
                                                                    osSyncPrintf((const char *) "gsDPSetDepthImage(0x%08x(0x%08x)),", sp374, temp_s4);
                                                                }
                                                                phi_t0_5 = disassembler->enableLog;
                                                                if (disassembler->pipeSyncRequired != 0) {
                                                                    if (disassembler->enableLog != 0) {
                                                                        osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                    }
                                                                    disassembler->syncErr = disassembler->syncErr + 1;
                                                                    phi_t0_5 = disassembler->enableLog;
                                                                    goto block_473;
                                                                case 32: // switch 1
                                                                    temp_v0_8 = sp370.unk0;
                                                                    temp_t0_10 = disassembler->enableLog;
                                                                    temp_v1_4 = ((u32) (temp_v0_8 & 0xE00000) >> 0x15) & 0xFF;
                                                                    temp_a0_2 = ((u32) (temp_v0_8 & 0x180000) >> 0x13) & 0xFF;
                                                                    phi_t0_5 = temp_t0_10;
                                                                    if (temp_t0_10 != 0) {
                                                                        if (temp_v1_4 == 0) {
                                                                            phi_s5_2 = "RGBA";
                                                                        } else {
                                                                            if (temp_v1_4 == 1) {
                                                                                phi_t0_7 = "YUV";
                                                                            } else {
                                                                                if (temp_v1_4 == 2) {
                                                                                    phi_v1_4 = "CI";
                                                                                } else {
                                                                                    if (temp_v1_4 == 3) {
                                                                                        phi_s2_2 = "IA";
                                                                                    } else {
                                                                                        phi_s2_2 = "I";
                                                                                    }
                                                                                    phi_v1_4 = phi_s2_2;
                                                                                }
                                                                                phi_t0_7 = phi_v1_4;
                                                                            }
                                                                            phi_s5_2 = phi_t0_7;
                                                                        }
                                                                        if (temp_a0_2 == 0) {
                                                                            phi_s1_2 = "4b";
                                                                        } else {
                                                                            if (temp_a0_2 == 1) {
                                                                                phi_s0_4 = "8b";
                                                                            } else {
                                                                                if (temp_a0_2 == 2) {
                                                                                    phi_s1_10 = "16b";
                                                                                } else {
                                                                                    phi_s1_10 = "32b";
                                                                                }
                                                                                phi_s0_4 = phi_s1_10;
                                                                            }
                                                                            phi_s1_2 = phi_s0_4;
                                                                        }
                                                                        osSyncPrintf((const char *) "gsDPSetTextureImage(G_IM_FMT_%s, G_IM_SIZ_%s, %d, 0x%08x(0x%08x)),", phi_s5_2, phi_s1_2, (sp370.unk2 & 0xFFF) + 1, sp374, temp_s4);
                                                                        phi_t0_5 = disassembler->enableLog;
                                                                        goto block_473;
                                                                    case 30: // switch 1
                                                                        if (disassembler->enableLog != 0) {
                                                                            osSyncPrintf((const char *) "gsDPSetEnvColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                                        }
                                                                        phi_t0_5 = disassembler->enableLog;
                                                                        if (disassembler->pipeSyncRequired != 0) {
                                                                            if (disassembler->enableLog != 0) {
                                                                                osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                            }
                                                                            disassembler->syncErr = disassembler->syncErr + 1;
                                                                            phi_t0_5 = disassembler->enableLog;
                                                                            goto block_473;
                                                                        case 28: // switch 1
                                                                            if (disassembler->enableLog != 0) {
                                                                                osSyncPrintf((const char *) "gsDPSetBlendColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                                            }
                                                                            phi_t0_5 = disassembler->enableLog;
                                                                            if (disassembler->pipeSyncRequired != 0) {
                                                                                if (disassembler->enableLog != 0) {
                                                                                    osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                                }
                                                                                disassembler->syncErr = disassembler->syncErr + 1;
                                                                                phi_t0_5 = disassembler->enableLog;
                                                                                goto block_473;
                                                                            case 27: // switch 1
                                                                                if (disassembler->enableLog != 0) {
                                                                                    osSyncPrintf((const char *) "gsDPSetFogColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                                                }
                                                                                phi_t0_5 = disassembler->enableLog;
                                                                                if (disassembler->pipeSyncRequired != 0) {
                                                                                    if (disassembler->enableLog != 0) {
                                                                                        osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                                    }
                                                                                    disassembler->syncErr = disassembler->syncErr + 1;
                                                                                    phi_t0_5 = disassembler->enableLog;
                                                                                    goto block_473;
                                                                                case 26: // switch 1
                                                                                    if (disassembler->enableLog != 0) {
                                                                                        osSyncPrintf((const char *) "gsDPSetFillColor(0x%08x),", sp370.unk4);
                                                                                    }
                                                                                    phi_t0_5 = disassembler->enableLog;
                                                                                    if (disassembler->pipeSyncRequired != 0) {
                                                                                        if (disassembler->enableLog != 0) {
                                                                                            osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                                        }
                                                                                        disassembler->syncErr = disassembler->syncErr + 1;
                                                                                        phi_t0_5 = disassembler->enableLog;
                                                                                        goto block_473;
                                                                                    case 17: // switch 1
                                                                                        if (disassembler->enableLog != 0) {
                                                                                            osSyncPrintf((const char *) "gsDPSetPrimDepth(%d, %d),", (u16) sp370.unk4, sp370.unk6);
                                                                                        }
                                                                                        phi_t0_5 = disassembler->enableLog;
                                                                                        if (disassembler->pipeSyncRequired != 0) {
                                                                                            if (disassembler->enableLog != 0) {
                                                                                                osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                                            }
                                                                                            disassembler->syncErr = disassembler->syncErr + 1;
                                                                                            phi_t0_5 = disassembler->enableLog;
                                                                                            goto block_473;
                                                                                        case 29: // switch 1
                                                                                            temp_t0_11 = disassembler->enableLog;
                                                                                            phi_t0_5 = temp_t0_11;
                                                                                            if (temp_t0_11 != 0) {
                                                                                                osSyncPrintf((const char *) "gsDPSetPrimColor(%d, %d, %d, %d, %d, %d),", (&sp370)[2], (&sp370)[3], (&sp370)[4], (?32) (&sp370)[5], (?32) (&sp370)[6], (?32) (&sp370)[7]);
                                                                                                goto block_472;
                                                                                            case 12: // switch 1
                                                                                                if (disassembler->enableLog != 0) {
                                                                                                    osSyncPrintf((const char *) "gsDPFullSync(),");
                                                                                                }
                                                                                                phi_t0_5 = disassembler->enableLog;
                                                                                                if (disassembler->pipeSyncRequired != 0) {
                                                                                                    if (disassembler->enableLog != 0) {
                                                                                                        osSyncPrintf((const char *) "### PipeSyncが必要です。\n");
                                                                                                    }
                                                                                                    disassembler->syncErr = disassembler->syncErr + 1;
                                                                                                    phi_t0_5 = disassembler->enableLog;
                                                                                                    goto block_473;
                                                                                                case 11: // switch 1
                                                                                                    if (disassembler->enableLog != 0) {
                                                                                                        osSyncPrintf((const char *) "gsDPTileSync(),");
                                                                                                    }
                                                                                                    disassembler->tileSyncRequired = 0;
                                                                                                    goto block_472;
                                                                                                case 10: // switch 1
                                                                                                    if (disassembler->enableLog != 0) {
                                                                                                        osSyncPrintf((const char *) "gsDPPipeSync(),");
                                                                                                    }
                                                                                                    disassembler->pipeSyncRequired = 0;
                                                                                                    goto block_472;
                                                                                                case 9: // switch 1
                                                                                                    if (disassembler->enableLog != 0) {
                                                                                                        osSyncPrintf((const char *) "gsDPLoadSync(),");
                                                                                                    }
                                                                                                    disassembler->loadSyncRequired = 0;
                                                                                                    goto block_472;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
block_473:
                                if (phi_t0_5 != 0) {
                                    osSyncPrintf((const char *) "\n");
                                }
                                gfxP = gfxP + 8;
                                if (sp378 == 0) {
                                    goto loop_1;
                                }
                                return;
                            }
                            goto block_472;
                        }
                    } else {
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf(&D_80147E7C, sp36C);
                        }
                        (&disassembler->segments[disassembler->dlDepth])[0x10] = (u32) (gfxP + 8);
                        disassembler->dlDepth = disassembler->dlDepth + 1;
                        gfxP = temp_s4 - 8;
                        goto block_472;
                    }
                }
            } else {
                temp_a1 = (&sp370)[1];
                temp_t0_12 = disassembler->enableLog;
                if ((u32) temp_a1 < 9U) {
                    goto **(&jtbl_80149308 + (temp_a1 * 4)); // switch 2
                case 0: // switch 2
                    temp_a1_4 = sp370.unk4;
                    if (temp_a1_4 == 0) {
                        phi_t0_5 = temp_t0_12;
                        if (temp_t0_12 != 0) {
                            osSyncPrintf((const char *) "gsDPNoOp(),", temp_a1_4);
                            goto block_472;
                        }
                    } else {
                        phi_t0_5 = temp_t0_12;
                        if (temp_t0_12 != 0) {
                            osSyncPrintf((const char *) "gsDPNoOpTag(%08x),", temp_a1_4);
                            goto block_472;
                        case 1: // switch 2
                            phi_t0_5 = temp_t0_12;
                            if (temp_t0_12 != 0) {
                                osSyncPrintf((const char *) "count_gsDPNoOpHere([%s:%d]),", sp370.unk4, sp370.unk2);
                                goto block_472;
                            case 7: // switch 2
                                phi_t0_5 = temp_t0_12;
                                if (temp_t0_12 != 0) {
                                    osSyncPrintf((const char *) "count_gsDPNoOpOpenDisp([%s:%d]),", sp370.unk4, sp370.unk2);
                                    goto block_472;
                                case 8: // switch 2
                                    phi_t0_5 = temp_t0_12;
                                    if (temp_t0_12 != 0) {
                                        osSyncPrintf((const char *) "count_gsDPNoOpCloseDisp([%s:%d]),", sp370.unk4, sp370.unk2);
                                        goto block_472;
                                    case 2: // switch 2
                                        phi_t0_5 = temp_t0_12;
                                        if (temp_t0_12 != 0) {
                                            osSyncPrintf((const char *) "count_gsDPNoOpString(%c%s%c, %d),", 0x22, sp370.unk4, 0x22, (?32) sp370.unk2);
                                            goto block_472;
                                        case 3: // switch 2
                                            phi_t0_5 = temp_t0_12;
                                            if (temp_t0_12 != 0) {
                                                osSyncPrintf((const char *) "count_gsDPNoOpWord(0x%08x, %d),", sp370.unk4, sp370.unk2);
                                                goto block_472;
                                            case 4: // switch 2
                                                phi_t0_5 = temp_t0_12;
                                                if (temp_t0_12 != 0) {
                                                    osSyncPrintf((const char *) "count_gsDPNoOpFloat(%8.3f, %d),", temp_a1, second half of f64, (f64) (bitwise f32) sp370.unk4, (?32) sp370.unk2);
                                                    goto block_472;
                                                case 5: // switch 2
                                                    if (sp370.unk2 == 0) {
                                                        if (temp_t0_12 != 0) {
                                                            osSyncPrintf((const char *) "count_gsDPNoOpQuiet(),", temp_a1);
block_253:
                                                        }
                                                    } else if (temp_t0_12 != 0) {
                                                        osSyncPrintf((const char *) "count_gsDPNoOpVerbose(),", temp_a1);
                                                        goto block_253;
                                                    }
                                                    disassembler->enableLog = (s32) sp370.unk2;
                                                    phi_t0_5 = (s32) sp370.unk2;
                                                    goto block_473;
                                                case 6: // switch 2
                                                    if (temp_t0_12 != 0) {
                                                        osSyncPrintf((const char *) "count_gsDPNoOpCallBack(%08x,%d),", temp_a1);
                                                    }
                                                    (void *) sp370.unk4(disassembler, sp370.unk2);
                                                    goto block_472;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    phi_t0_5 = temp_t0_12;
                    if (temp_t0_12 != 0) {
                        osSyncPrintf((const char *) "gsDPNoOpTag3(%02x, %08x, %04x),", temp_a1, sp370.unk4, sp370.unk2);
                        goto block_472;
                    }
                }
            }
        } else {
        default: // switch 1
block_260:
            temp_s1_5 = disassembler->ucodeType;
            if ((temp_s1_5 != 1) && (temp_s1_5 != 2)) {
                if (temp_s1_5 != 3) {
                    goto block_472;
                } else if ((s32) sp370 >= 0xDC) {
                    if (sp370 != 0xDC) {
                        if (sp370 != 0xE4) {
                        case 2: // switch 6
block_470:
                            temp_t0_24 = disassembler->enableLog;
                            phi_t0_5 = temp_t0_24;
                            if (temp_t0_24 != 0) {
                                osSyncPrintf((const char *) "AnyDisplayList(),");
                                goto block_472;
                            }
                        } else {
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf((const char *) "RDPHALF_0(0x%02x, 0x%08x, 0x%04x),", (&sp370)[1], sp370.unk4, sp370.unk2);
                            }
                            sp381 = (&sp370)[1];
                            sp384 = sp370.unk4;
                            sp382 = sp370.unk2;
                        }
                    } else {
                        sp1D8.unk0 = (u32) gfxP->words.w0;
                        sp1D8.unk4 = (u32) gfxP->words.w1;
                        if (sp1D9 == 0x17) {
                            temp_t0_13 = disassembler->enableLog;
                            phi_t0_5 = temp_t0_13;
                            if (temp_t0_13 != 0) {
                                osSyncPrintf((const char *) "gsSPObjMatrix(0x%08x(0x%08x)),", sp1DC, temp_s4);
                                goto block_472;
                            }
                        } else {
                            temp_t0_14 = disassembler->enableLog;
                            phi_t0_5 = temp_t0_14;
                            if (temp_t0_14 != 0) {
                                osSyncPrintf((const char *) "gsSPObjSubMatrix(0x%08x(0x%08x)),", sp1DC, temp_s4);
                                phi_t0_5 = disassembler->enableLog;
                                goto block_473;
                            case 4: // switch 6
                                sp1D0.unk0 = (u32) gfxP->words.w0;
                                sp1D0.unk4 = (u32) gfxP->words.w1;
                                temp_t0_17 = disassembler->enableLog;
                                phi_t0_5 = temp_t0_17;
                                if (temp_t0_17 != 0) {
                                    osSyncPrintf((const char *) "gsSPObjLoadTxtr(0x%08x(0x%08x)),", sp1D4, temp_s4);
                                    phi_t0_5 = disassembler->enableLog;
                                    goto block_473;
                                case 5: // switch 6
                                    sp1C8.unk0 = (u32) gfxP->words.w0;
                                    sp1C8.unk4 = (u32) gfxP->words.w1;
                                    temp_t0_18 = disassembler->enableLog;
                                    phi_t0_5 = temp_t0_18;
                                    if (temp_t0_18 != 0) {
                                        osSyncPrintf((const char *) "gsSPObjLoadTxSprite(0x%08x(0x%08x)),", sp1CC, temp_s4);
                                        phi_t0_5 = disassembler->enableLog;
                                        goto block_473;
                                    case 6: // switch 6
                                        sp1C0.unk0 = (u32) gfxP->words.w0;
                                        sp1C0.unk4 = (u32) gfxP->words.w1;
                                        temp_t0_19 = disassembler->enableLog;
                                        phi_t0_5 = temp_t0_19;
                                        if (temp_t0_19 != 0) {
                                            osSyncPrintf((const char *) "gsSPObjLoadTxRect(0x%08x(0x%08x)),", sp1C4, temp_s4);
                                            phi_t0_5 = disassembler->enableLog;
                                            goto block_473;
                                        case 7: // switch 6
                                            sp1B8.unk0 = (u32) gfxP->words.w0;
                                            sp1B8.unk4 = (u32) gfxP->words.w1;
                                            temp_t0_20 = disassembler->enableLog;
                                            phi_t0_5 = temp_t0_20;
                                            if (temp_t0_20 != 0) {
                                                osSyncPrintf((const char *) "gsSPObjLoadTxRectR(0x%08x(0x%08x)),", sp1BC, temp_s4);
                                                phi_t0_5 = disassembler->enableLog;
                                                goto block_473;
                                            case 3: // switch 6
                                                sp1B0.unk0 = (u32) gfxP->words.w0;
                                                sp1B0.unk4 = (u32) gfxP->words.w1;
                                                temp_v0_9 = UCodeDisas_TranslateAddr(disassembler, (sp1B2 << 0x10) | sp382);
                                                if (sp1B1 == 0) {
                                                    temp_t0_21 = disassembler->enableLog;
                                                    phi_t0_5 = temp_t0_21;
                                                    if (temp_t0_21 != 0) {
                                                        osSyncPrintf((const char *) "gsSPSelectDL(0x%08x, %d, 0x%08x, 0x%08x),", temp_v0_9, sp381, sp384, sp1B4);
                                                        goto block_472;
                                                    }
                                                } else {
                                                    temp_t0_22 = disassembler->enableLog;
                                                    phi_t0_5 = temp_t0_22;
                                                    if (temp_t0_22 != 0) {
                                                        osSyncPrintf((const char *) "gsSPSelectBranchDL(0x%08x, %d, 0x%08x, 0x%08x),", temp_v0_9, sp381, sp384, sp1B4);
                                                        phi_t0_5 = disassembler->enableLog;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((s32) sp370 >= 0xDB) {
                    if (sp370 != 0xDB) {
                        goto block_470;
                    } else {
                        sp198.unk0 = (u32) gfxP->words.w0;
                        sp198.unk4 = (u32) gfxP->words.w1;
                        if (sp19B != 6) {
                            if (sp19B != 8) {
                                temp_t0_15 = disassembler->enableLog;
                                phi_t0_5 = temp_t0_15;
                                if (temp_t0_15 != 0) {
                                    osSyncPrintf((const char *) "gsMoveWd(%d, %d, %d), ", sp19B, (u32) (unaligned s32) sp199 >> 0x10, sp19C);
                                    phi_t0_5 = disassembler->enableLog;
                                    goto block_473;
                                case 10: // switch 6
                                    sp18C.unk0 = (u32) gfxP->words.w0;
                                    sp18C.unk4 = (u32) gfxP->words.w1;
                                    temp_t0_23 = disassembler->enableLog;
                                    phi_t0_5 = temp_t0_23;
                                    if (temp_t0_23 != 0) {
                                        osSyncPrintf((const char *) "gsSPObjRenderMode(0x%08x),", sp190);
                                        phi_t0_5 = disassembler->enableLog;
                                    }
                                }
                            } else {
                                temp_t0_16 = disassembler->enableLog;
                                phi_t0_5 = temp_t0_16;
                                if (temp_t0_16 != 0) {
                                    osSyncPrintf((const char *) "gsSPSetStatus(0x%08x, 0x%08x),", (u32) (unaligned s32) sp199 >> 0x10, sp19C);
                                    goto block_472;
                                }
                            }
                        } else {
                            temp_s0_5 = (u32) ((u32) (unaligned s32) sp199 >> 0x10) >> 2;
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf((const char *) "gsSPSegment(%d, 0x%08x),", temp_s0_5, sp19C);
                            }
                            disassembler->segments[temp_s0_5] = (u32) (sp19C & 0xFFFFFF);
                            goto block_472;
                        }
                    }
                } else if ((s32) sp370 >= 0xC) {
                    if (sp370 != 0xDA) {
                        goto block_470;
                    } else {
                        sp1E0.unk0 = (u32) gfxP->words.w0;
                        sp1E0.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjRectangleR(0x%08x(0x%08x)),", sp1E4, temp_s4);
                        }
                        disassembler->pipeSyncRequired = 1;
                        goto block_472;
                    }
                } else {
                    temp_t7 = sp370 - 1;
                    if (temp_t7 < 0xBU) {
                        goto **(&jtbl_80149398 + (temp_t7 * 4)); // switch 6
                    case 9: // switch 6
                        sp200.unk0 = (u32) gfxP->words.w0;
                        sp200.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPBgRectCopy(0x%08x(0x%08x)),", sp204, temp_s4);
                        }
                        disassembler->pipeSyncRequired = 1;
                        goto block_472;
                    case 8: // switch 6
                        sp1F8.unk0 = (u32) gfxP->words.w0;
                        sp1F8.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPBgRect1Cyc(0x%08x(0x%08x)),", sp1FC, temp_s4);
                        }
                        disassembler->pipeSyncRequired = 1;
                        goto block_472;
                    case 1: // switch 6
                        sp1F0.unk0 = (u32) gfxP->words.w0;
                        sp1F0.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjSprite(0x%08x(0x%08x)),", sp1F4, temp_s4);
                        }
                        disassembler->pipeSyncRequired = 1;
                        goto block_472;
                    case 0: // switch 6
                        sp1E8.unk0 = (u32) gfxP->words.w0;
                        sp1E8.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjRectangle(0x%08x(0x%08x)),", sp1EC, temp_s4);
                        }
                        disassembler->pipeSyncRequired = 1;
                        goto block_472;
                    } else {
                        goto block_470;
                    }
                }
            } else if ((s32) sp370 >= 9) {
                temp_t2 = sp370 - 0xD7;
                if (temp_t2 < 6U) {
                    goto **(&jtbl_8014932C + (temp_t2 * 4)); // switch 3
block_267:
                    temp_t7_2 = sp370 - 1;
                    if (temp_t7_2 < 8U) {
                        goto **(&jtbl_80149344 + (temp_t7_2 * 4)); // switch 4
                    case 3: // switch 3
                        sp2D4.unk0 = (u32) gfxP->words.w0;
                        sp2D4.unk4 = (u32) gfxP->words.w1;
                        if (disassembler->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPMatrix(0x%08x(%08x), 0", sp2D8, temp_s4);
                        }
                        phi_s0_2 = 0;
loop_272:
                        phi_t0_2 = phi_t0;
                        if (phi_t0 != 0) {
                            temp_v0_10 = (((phi_s0_2 * 4) - phi_s0_2) * 4) + &sUCodeDisasMtxFlags;
                            if ((temp_v0_10->unk0 & (sp2D7 ^ 1)) != 0) {
                                phi_s1_3 = temp_v0_10->unk4;
                            } else {
                                phi_s1_3 = temp_v0_10->unk8;
                            }
                            osSyncPrintf((const char *) "|%s", phi_s1_3);
                            phi_t0_2 = disassembler->enableLog;
                        }
                        temp_s0_6 = phi_s0_2 + 1;
                        phi_t0 = phi_t0_2;
                        phi_s0_2 = temp_s0_6;
                        if (temp_s0_6 != 3) {
                            goto loop_272;
                        }
                        phi_t0_3 = phi_t0_2;
                        if (phi_t0_2 != 0) {
                            osSyncPrintf((const char *) "),", sp2D8);
                            phi_t0_3 = disassembler->enableLog;
                        }
                        phi_t0_5 = phi_t0_3;
                        if (phi_t0_3 >= 2) {
                            MtxConv_L2F((MtxF *) &sp290, temp_s4);
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf((const char *) "\n");
                            }
                            phi_t0_5 = disassembler->enableLog;
                            if (disassembler->enableLog != 0) {
                                osSyncPrintf((const char *) "/ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x \\/ %12.6f %12.6f %12.6f %12.6f \\\n| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x || %12.6f %12.6f %12.6f %12.6f |\n| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x || %12.6f %12.6f %12.6f %12.6f |\n\\ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x /\\ %12.6f %12.6f %12.6f %12.6f /\n", temp_s4->intPart[0][0], temp_s4->fracPart[0][0], temp_s4->intPart[1][0], (?32) temp_s4->fracPart[1][0], (?32) temp_s4->intPart[2][0], (?32) temp_s4->fracPart[2][0], (?32) temp_s4->intPart[3][0], (?32) temp_s4->fracPart[3][0], (f64) sp290, (f64) sp2A0, (f64) sp2B0, (f64) sp2C0, (?32) temp_s4->intPart[0][1], (?32) temp_s4->fracPart[0][1], (?32) temp_s4->intPart[1][1], (?32) temp_s4->fracPart[1][1], (?32) temp_s4->intPart[2][1], (?32) temp_s4->fracPart[2][1], (?32) temp_s4->intPart[3][1], (?32) temp_s4->fracPart[3][1], (f64) sp294, (f64) sp2A4, (f64) sp2B4, (f64) sp2C4, (?32) temp_s4->intPart[0][2], (?32) temp_s4->fracPart[0][2], (?32) temp_s4->intPart[1][2], (?32) temp_s4->fracPart[1][2], (?32) temp_s4->intPart[2][2], (?32) temp_s4->fracPart[2][2], (?32) temp_s4->intPart[3][2], (?32) temp_s4->fracPart[3][2], (f64) sp298, (f64) sp2A8, (f64) sp2B8, (f64) sp2C8, (?32) temp_s4->intPart[0][3], (?32) temp_s4->fracPart[0][3], (?32) temp_s4->intPart[1][3], (?32) temp_s4->fracPart[1][3], (?32) temp_s4->intPart[2][3], (?32) temp_s4->fracPart[2][3], (?32) temp_s4->intPart[3][3], (?32) temp_s4->fracPart[3][3], (f64) sp29C, (f64) sp2AC, (f64) sp2BC, (f64) sp2CC);
                                phi_t0_5 = disassembler->enableLog;
                                goto block_473;
                            case 0: // switch 4
                                temp_s0_8 = ((u32) sp370.unk0 >> 0xC) & 0xFF;
                                temp_s1_7 = ((s32) (&sp370)[3] >> 1) - temp_s0_8;
                                if (disassembler->enableLog != 0) {
                                    osSyncPrintf((const char *) "gsSPVertex(0x%08x(0x%08x), %d, %d),", sp370.unk4, temp_s4, temp_s0_8, temp_s1_7);
                                }
                                disassembler->vtxCnt = disassembler->vtxCnt + temp_s0_8;
                                disassembler->spvtxCnt = disassembler->spvtxCnt + 1;
                                phi_t0_5 = disassembler->enableLog;
                                if (disassembler->enableLog >= 2) {
                                    UCodeDisas_PrintVertices(disassembler, temp_s4, temp_s0_8, temp_s1_7);
                                    phi_t0_5 = disassembler->enableLog;
                                    goto block_473;
                                case 1: // switch 4
                                    if (disassembler->enableLog != 0) {
                                        temp_v0_12 = sp370.unk2;
                                        if (temp_v0_12 == 0x10) {
                                            phi_s1_7 = "G_MWO_POINT_RGBA";
                                        } else {
                                            if (temp_v0_12 == 0x14) {
                                                phi_s0_5 = "G_MWO_POINT_ST";
                                            } else {
                                                if (temp_v0_12 == 0x18) {
                                                    phi_s1_11 = "G_MWO_POINT_XYSCREEN";
                                                } else {
                                                    if (temp_v0_12 == 0x1C) {
                                                        phi_s5_3 = "G_MWO_POINT_ZSCREEN";
                                                    } else {
                                                        phi_s5_3 = "G_MWO_POINT_????";
                                                    }
                                                    phi_s1_11 = phi_s5_3;
                                                }
                                                phi_s0_5 = phi_s1_11;
                                            }
                                            phi_s1_7 = phi_s0_5;
                                        }
                                        osSyncPrintf((const char *) "gsSPModifyVertex(%d, %s, %08x),", (&sp370)[1], phi_s1_7, sp370.unk4);
                                    }
                                    disassembler->vtxCnt = disassembler->vtxCnt + (&sp370)[1];
                                    disassembler->spvtxCnt = disassembler->spvtxCnt + 1;
                                    phi_t0_5 = disassembler->enableLog;
                                    goto block_473;
                                case 4: // switch 4
                                    sp27C.unk0 = (u32) gfxP->words.w0;
                                    sp27C.unk4 = (u32) gfxP->words.w1;
                                    sp278 = (unaligned s32) sp280;
                                    if (disassembler->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP1Triangle(%d, %d, %d),", (s32) sp279 / 2, (s32) sp27A / 2, (s32) sp27B / 2);
                                    }
                                    disassembler->pipeSyncRequired = 1;
                                    disassembler->tri1Cnt = disassembler->tri1Cnt + 1;
                                    goto block_472;
                                case 7: // switch 4
                                    temp_a3 = (&sp370)[3];
                                    temp_t0_38 = disassembler->enableLog;
                                    if (temp_a3 == 0) {
                                        if (temp_t0_38 != 0) {
                                            osSyncPrintf((const char *) "gsSPLine3D(%d, %d),", (&sp370)[1], (&sp370)[2], temp_a3);
                                        }
                                    } else if (temp_t0_38 != 0) {
                                        osSyncPrintf((const char *) "gsSPLineW3D(%d, %d, %d),", (&sp370)[1], (&sp370)[2], temp_a3);
                                    }
                                    disassembler->pipeSyncRequired = 1;
                                    disassembler->lineCnt = disassembler->lineCnt + 1;
                                    goto block_472;
                                case 5: // switch 4
                                    sp270.unk0 = (?32) (unaligned s32) gfxP->texture.cmd;
                                    sp270.unk4 = (?32) (unaligned s32) gfxP->words.w1;
                                    if (disassembler->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP2Triangles(%d, %d, %d, 0, %d, %d, %d, 0),", (s32) sp271 / 2, (s32) sp272 / 2, (s32) sp273 / 2, (s32) sp275 / 2, (s32) sp276 / 2, (s32) sp277 / 2);
                                    }
                                    disassembler->pipeSyncRequired = 1;
                                    disassembler->tri2Cnt = disassembler->tri2Cnt + 1;
                                    goto block_472;
                                case 6: // switch 4
                                    sp250.unk0 = (?32) (unaligned s32) gfxP->texture.cmd;
                                    sp250.unk4 = (?32) (unaligned s32) gfxP->words.w1;
                                    if (disassembler->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP1Quadrangle(%d, %d, %d, %d, 0),", (s32) sp251 / 2, (s32) sp252 / 2, (s32) sp253 / 2, (s32) sp257 / 2);
                                    }
                                    disassembler->pipeSyncRequired = 1;
                                    disassembler->quadCnt = disassembler->quadCnt + 1;
                                    goto block_472;
                                case 2: // switch 4
                                    temp_t0_39 = disassembler->enableLog;
                                    phi_t0_5 = temp_t0_39;
                                    if (temp_t0_39 != 0) {
                                        osSyncPrintf((const char *) "gsSPCullDisplayList(%d, %d),", (s32) sp370.unk2 / 2, (s32) sp370.unk6 / 2);
                                        goto block_472;
                                    case 3: // switch 4
                                        temp_v0_13 = UCodeDisas_TranslateAddr(disassembler, sp384);
                                        if (disassembler->enableLog != 0) {
                                            osSyncPrintf((const char *) "gsSPBranchLessZraw(0x%08x(0x%08x), %d, 0x%08x),", sp384, temp_v0_13, (u32) (sp370.unk0 & 0xFFF) >> 1, sp370.unk4);
                                        }
                                        gfxP = temp_v0_13 - 8;
                                        goto block_473;
                                    case 0: // switch 3
                                        sp238.unk0 = (?32) (unaligned s32) gfxP->texture.cmd;
                                        sp238.unk4 = (?32) (unaligned s32) gfxP->words.w1;
                                        if (sp239 == 0) {
                                            temp_t0_25 = disassembler->enableLog;
                                            phi_t0_5 = temp_t0_25;
                                            if (temp_t0_25 != 0) {
                                                if (sp23B != 0) {
                                                    phi_s1_4 = "G_ON";
                                                } else {
                                                    phi_s1_4 = "G_OFF";
                                                }
                                                osSyncPrintf((const char *) "gsSPTexture(%d, %d, %d, %d, %s),", sp23C, sp23E, (u32) (sp238 << 0x12) >> 0x1D, sp23A & 7, phi_s1_4);
                                                goto block_472;
                                            }
                                        } else {
                                            temp_t0_26 = disassembler->enableLog;
                                            phi_t0_5 = temp_t0_26;
                                            if (temp_t0_26 != 0) {
                                                if (sp23B != 0) {
                                                    phi_s1_5 = "G_ON";
                                                } else {
                                                    phi_s1_5 = "G_OFF";
                                                }
                                                osSyncPrintf((const char *) "gsSPTextureL(%d, %d, %d, %d, %d, %s),", sp23C, sp23E, (u32) (sp238 << 0x12) >> 0x1D, (?32) sp239, sp23A & 7, phi_s1_5);
                                                phi_t0_5 = disassembler->enableLog;
                                                goto block_473;
                                            case 1: // switch 3
                                                sp230.unk0 = (u32) gfxP->words.w0;
                                                sp230.unk4 = (u32) gfxP->words.w1;
                                                temp_a1_5 = sp234 >> 6;
                                                if (temp_a1_5 == 1) {
                                                    temp_t0_27 = disassembler->enableLog;
                                                    phi_t0_5 = temp_t0_27;
                                                    if (temp_t0_27 != 0) {
                                                        osSyncPrintf((const char *) "gsSPPopMatrix(G_MTX_MODELVIEW),", temp_a1_5);
                                                        goto block_472;
                                                    }
                                                } else {
                                                    temp_t0_28 = disassembler->enableLog;
                                                    phi_t0_5 = temp_t0_28;
                                                    if (temp_t0_28 != 0) {
                                                        osSyncPrintf((const char *) "gsSPPopMatrixN(G_MTX_MODELVIEW, %d),", temp_a1_5);
                                                        phi_t0_5 = disassembler->enableLog;
                                                        goto block_473;
                                                    case 2: // switch 3
                                                        temp_t0_29 = disassembler->enableLog;
                                                        temp_s0_7 = sp370.unk0 & 0xFFFFFF;
                                                        temp_s1_6 = sp370.unk4 & 0xFFFFFF;
                                                        if (temp_s0_7 == 0) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPLoadGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(disassembler, temp_s1_6);
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else if (temp_s1_6 == 0) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPClearGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(disassembler, ~temp_s0_7);
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else if (temp_s0_7 == 0xFFFFFF) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPSetGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(disassembler, temp_s1_6);
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(disassembler, ~temp_s0_7);
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) ", ");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(disassembler, temp_s1_6);
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        }
                                                        temp_t7_4 = disassembler->geometryMode & temp_s0_7;
                                                        disassembler->geometryMode = temp_t7_4;
                                                        disassembler->geometryMode = temp_t7_4 | temp_s1_6;
                                                        phi_t0_5 = disassembler->enableLog;
                                                        goto block_473;
                                                    case 4: // switch 3
                                                        sp21C.unk0 = (u32) gfxP->words.w0;
                                                        sp21C.unk4 = (u32) gfxP->words.w1;
                                                        sp214.unk0 = (u32) gfxP->words.w0;
                                                        sp214.unk4 = (u32) gfxP->words.w1;
                                                        sp217 = sp21D;
                                                        sp214 = ((u32) ((sp21E ^ (sp214 >> 8)) << 0x10) >> 8) ^ sp214;
                                                        sp218 = sp220;
                                                        temp_t9 = sp217 - 2;
                                                        if (temp_t9 < 0xDU) {
                                                            goto **(&jtbl_80149364 + (temp_t9 * 4)); // switch 5
                                                        case 4: // switch 5
                                                            if (disassembler->enableLog != 0) {
                                                                osSyncPrintf((const char *) "gsSPSegment(%d, 0x%08x),", (u32) ((u32) (unaligned s32) sp215 >> 0x10) >> 2, sp218);
                                                            }
                                                            disassembler->segments[(u32) ((u32) (unaligned s32) sp215 >> 0x10) >> 2] = (u32) (sp218 & 0xFFFFFF);
                                                            goto block_472;
                                                        case 2: // switch 5
                                                            if (disassembler->enableLog != 0) {
                                                                if (sp218 != 0) {
                                                                    phi_s1_6 = sp218;
                                                                } else {
                                                                    phi_s1_6 = -sp218;
                                                                }
                                                                osSyncPrintf((const char *) "gsSPClipRatio(FRUSTRATIO_%d), ", phi_s1_6);
                                                            }
                                                            gfxP = gfxP + 0x18;
                                                            goto block_473;
                                                        case 0: // switch 5
                                                            temp_t0_30 = disassembler->enableLog;
                                                            phi_t0_5 = temp_t0_30;
                                                            if (temp_t0_30 != 0) {
                                                                osSyncPrintf((const char *) "gsSPNumLights(%d), ", (u32) sp218 / 0x18U);
                                                                goto block_472;
                                                            case 8: // switch 5
                                                                if (disassembler->enableLog != 0) {
                                                                    osSyncPrintf((const char *) "gsSPLightColor(%d, %d), ", ((u32) (((u32) (unaligned s32) sp215 >> 0x10) & 0xF0) >> 5) + 1, sp218);
                                                                }
                                                                gfxP = gfxP + 8;
                                                                goto block_473;
                                                            case 6: // switch 5
                                                                temp_t0_31 = disassembler->enableLog;
                                                                phi_t0_5 = temp_t0_31;
                                                                if (temp_t0_31 != 0) {
                                                                    osSyncPrintf((const char *) "gsSPFogFactor(%d, %d),", (u32) sp218 >> 0x10, sp218 & 0xFFFF);
                                                                    goto block_472;
                                                                case 12: // switch 5
                                                                    temp_t0_32 = disassembler->enableLog;
                                                                    phi_t0_5 = temp_t0_32;
                                                                    if (temp_t0_32 != 0) {
                                                                        osSyncPrintf((const char *) "gsSPPerspNormalize(%d),", sp218);
                                                                        goto block_472;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                        default: // switch 5
                                                            temp_t0_33 = disassembler->enableLog;
                                                            phi_t0_5 = temp_t0_33;
                                                            if (temp_t0_33 != 0) {
                                                                osSyncPrintf((const char *) "gsMoveWd(%d, %d, %d), ", sp217, (u32) (unaligned s32) sp215 >> 0x10, sp218);
                                                                phi_t0_5 = disassembler->enableLog;
                                                                goto block_473;
                                                            case 5: // switch 3
                                                                sp20C.unk0 = (u32) gfxP->words.w0;
                                                                sp20C.unk4 = (u32) gfxP->words.w1;
                                                                if (sp20F != 8) {
                                                                    if (sp20F != 0xA) {
                                                                        if (sp20F != 0xE) {
                                                                            temp_t0_34 = disassembler->enableLog;
                                                                            phi_t0_5 = temp_t0_34;
                                                                            if (temp_t0_34 != 0) {
                                                                                osSyncPrintf((const char *) "gsMoveMem(0x%08x, %d, %d, %d),", sp210, (((u32) sp20D >> 3) * 8) + 8, sp20F, sp20E * 8);
                                                                                phi_t0_5 = disassembler->enableLog;
                                                                            }
                                                                        } else {
                                                                            if (disassembler->enableLog != 0) {
                                                                                osSyncPrintf((const char *) "gsSPForceMatrix(0x%08x),", sp210);
                                                                            }
                                                                            gfxP = gfxP + 8;
                                                                        }
                                                                    } else {
                                                                        temp_v0_11 = sp20E * 8;
                                                                        if (temp_v0_11 != 0) {
                                                                            if (temp_v0_11 != 0x18) {
                                                                                temp_t0_35 = disassembler->enableLog;
                                                                                phi_t0_5 = temp_t0_35;
                                                                                if (temp_t0_35 != 0) {
                                                                                    osSyncPrintf((const char *) "gsSPLight(0x%08x,%d),", sp210, (u32) (temp_v0_11 - 0x18) / 0x18U);
                                                                                    goto block_472;
                                                                                }
                                                                            } else {
                                                                                temp_t0_36 = disassembler->enableLog;
                                                                                phi_t0_5 = temp_t0_36;
                                                                                if (temp_t0_36 != 0) {
                                                                                    osSyncPrintf((const char *) "gsSPLookAtY(0x%08x),", sp210);
                                                                                    goto block_472;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            temp_t0_37 = disassembler->enableLog;
                                                                            phi_t0_5 = temp_t0_37;
                                                                            if (temp_t0_37 != 0) {
                                                                                osSyncPrintf((const char *) "gsSPLookAtX(0x%08x),", sp210);
                                                                                goto block_472;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (disassembler->enableLog != 0) {
                                                                        osSyncPrintf((const char *) "gsSPViewport(0x%08x(0x%08x)),", sp210, temp_s4);
                                                                    }
                                                                    phi_t0_4 = disassembler->enableLog;
                                                                    if (disassembler->enableLog != 0) {
                                                                        osSyncPrintf((const char *) "\t# vscale=[%d %d %d %d], ", (s16) temp_s4->intPart[0][0], (s16) temp_s4->intPart[0][1], (s16) temp_s4->intPart[0][2], (?32) (s16) temp_s4->intPart[0][3]);
                                                                        phi_t0_4 = disassembler->enableLog;
                                                                    }
                                                                    phi_t0_5 = phi_t0_4;
                                                                    if (phi_t0_4 != 0) {
                                                                        osSyncPrintf((const char *) "vtrans=[%d %d %d %d] ", (s16) temp_s4->intPart[1][0], (s16) temp_s4->intPart[1][1], (s16) temp_s4->intPart[1][2], (?32) (s16) temp_s4->intPart[1][3]);
                                                                        goto block_472;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
block_408:
                        temp_t0_40 = disassembler->enableLog;
                        phi_t0_5 = temp_t0_40;
                        if (temp_t0_40 != 0) {
                            osSyncPrintf((const char *) "AnyDisplayList(),");
                            phi_t0_5 = disassembler->enableLog;
                        }
                    }
                } else {
                    goto block_408;
                }
            } else {
                goto block_267;
            }
        }
    } else {
        goto block_12;
    }
    goto block_473;
}
