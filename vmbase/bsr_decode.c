int BTESR_DecodeOpcode(BTESR_CpuState *cpu,
	BTESR_Opcode *op, btesr_addr pc)
{
	u16 opw, opw2;
	int i, j, k;
	
	opw=BTESH2_GetAddrWord(cpu, pc);

	if((opw>>13)==7)
	{
		opw2=BTESR_GetAddrWord(cpu, pc+2);

		op->fl=BTESR_OPFL_EXTRAWORD;
		op->opw=opw;
		op->opw2=opw2;
		op->pc=pc;
		
		if(((opw>>12)&15)==0xE)
		{
			i=BTESR_DecodeOpcode_Dec32_E(cpu, op, pc, opw, opw2);
			return(i);
		}
		
		return(-1);
	}

	op->fl=0;
	op->opw=opw;
//	op->opw2=opw2;
	op->pc=pc;
	switch((opw>>12)&15)
	{
	case 0x0: /* 0--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 00nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_ADD_RegReg;
			break;
		case 0x1: /* 01nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SUBI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SUB_RegReg;
			break;
		case 0x2: /* 02nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MULI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MUL_RegReg;
			break;
		case 0x3: /* 03nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ANDI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_AND_RegReg;
			break;
		case 0x4: /* 04nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ORI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_OR_RegReg;
			break;
		case 0x5: /* 05nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_XORI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_XOR_RegReg;
			break;
		case 0x6: /* 06nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SHLI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SHL_RegReg;
			break;
		case 0x7: /* 07nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SARI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SAR_RegReg;
			break;
		case 0x8: /* 08nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_ADDF_RegReg;
			break;
		case 0x9: /* 09nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SUBF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SUBF_RegReg;
			break;
		case 0xA: /* 0Anm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MULF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MULF_RegReg;
			break;
		case 0xB: /* 0Bnm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_DIVF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_DIVF_RegReg;
			break;
		case 0xC: /* 0Cnm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CVTI2F;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CVTI2F_RegReg;
			break;
		case 0xD: /* 0Dnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CVTF2I;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CVTF2I_RegReg;
			break;
		case 0xE: /* 0Enm */
			op->rn=btesr_mkcnr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_LDCR;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MOVQ_RegReg;
			break;
		case 0xF: /* 0Fnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkcnr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_STCR;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MOVQ_RegReg;
			break;
		default:
			break;
		}
		break;
	case 0x1: /* 1--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 10nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVB_RegLdReg;
			break;
		case 0x1: /* 11nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVW_RegLdReg;
			break;
		case 0x2: /* 12nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVI_RegLdReg;
			break;
		case 0x3: /* 13nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVQ_RegLdReg;
			break;
		case 0x4: /* 14nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVB_StRegReg;
			break;
		case 0x5: /* 15nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVW_StRegReg;
			break;
		case 0x6: /* 16nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVI_StRegReg;
			break;
		case 0x7: /* 17nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVQ_StRegReg;
			break;


		case 0x8: /* 18nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVF_RegLdReg;
			break;
		case 0x9: /* 19nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_REGLDREG;
			op->Run=BTESR_Op_MOVQ_RegLdReg;
			break;
		case 0xA: /* 1Anm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVF_StRegReg;
			break;
		case 0xB: /* 1Bnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_STREGREG;
			op->Run=BTESR_Op_MOVQ_StRegReg;
			break;

		case 0xC: /* 1Cnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MOV_RegReg;
			break;
		case 0xD: /* 1Dnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MOVQ_RegReg;
			break;
		case 0xE: /* 1Enm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MOVQ_RegReg;
			break;
		case 0xF: /* 1Fxn */
			switch((opw>>4)&15)
			{
			case 0x0:
				op->rn=BTESR_REG_SP;
				op->rm=btesr_mkgpr(cpu, opw&15);
				op->nmid=BTESR_NMID_PUSHI;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_MOVQ_StDecRegReg;
				break;
			case 0x1:
				op->rn=BTESR_REG_SP;
				op->rm=btesr_mkfpr(cpu, opw&15);
				op->nmid=BTESR_NMID_PUSHF;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_MOVQ_StDecRegReg;
				break;
			case 0x2:
				op->rn=BTESR_REG_SP;
				op->rm=btesr_mkgpr(cpu, opw&15);
				op->nmid=BTESR_NMID_PUSHQ;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_MOVQ_StDecRegReg;
				break;
			case 0x3:
				op->rn=BTESR_REG_SP;
				op->rm=btesr_mkfpr(cpu, opw&15);
				op->nmid=BTESR_NMID_PUSHF;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_MOVV_StDecRegReg;
				break;

			case 0x4:
				op->rn=btesr_mkgpr(cpu, opw&15);
				op->rm=BTESR_REG_SP;
				op->nmid=BTESR_NMID_POPI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_MOVQ_RegLdIncReg;
				break;
			case 0x5:
				op->rn=btesr_mkfpr(cpu, opw&15);
				op->rm=BTESR_REG_SP;
				op->nmid=BTESR_NMID_POPF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_MOVQ_RegLdIncReg;
				break;
			case 0x6:
				op->rn=btesr_mkgpr(cpu, opw&15);
				op->rm=BTESR_REG_SP;
				op->nmid=BTESR_NMID_POPQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_MOVQ_RegLdIncReg;
				break;
			case 0x7:
				op->rn=btesr_mkfpr(cpu, opw&15);
				op->rm=BTESR_REG_SP;
				op->nmid=BTESR_NMID_POPV;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_MOVV_RegLdIncReg;
				break;

			case 0x8:
				op->rn=BTESR_REG_SP;
				op->rm=btesr_mkcnr(cpu, opw&15);
				op->nmid=BTESR_NMID_PUSHC;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_MOVQ_StDecRegReg;
				break;
			case 0x9:
				op->rn=btesr_mkcnr(cpu, opw&15);
				op->rm=BTESR_REG_SP;
				op->nmid=BTESR_NMID_POPC;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_MOVQ_RegLdIncReg;
				break;

			default:
				break;
			}
			break;
		default:
			break;
		}
		break;

	case 0x2: /* 2--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 20dd */
			op->rn=BTESR_REG_SP;
			op->imm=((opw   )&255)*8;
			op->nmid=BTESR_NMID_PUSHNN;
			op->fmid=BTESR_FMID_IMM;
			op->Run=BTESR_Op_SUB_RegImm;
			break;
		case 0x1: /* 21dd */
			op->rn=BTESR_REG_SP;
			op->imm=((opw   )&255)*8;
			op->nmid=BTESR_NMID_PUSHNN;
			op->fmid=BTESR_FMID_IMM;
			op->Run=BTESR_Op_ADD_RegImm;
			break;
		case 0x2: /* 22nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPEQI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPEQ_RegReg;
			break;
		case 0x3: /* 23nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGTI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGT_RegReg;
			break;
		case 0x4: /* 24nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGEI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGE_RegReg;
			break;
		case 0x5: /* 25nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPEQF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPEQF_RegReg;
			break;
		case 0x6: /* 26nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGTF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGTF_RegReg;
			break;
		case 0x7: /* 27nm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGEF;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGEF_RegReg;
			break;

		case 0x8: /* 28xm */
			switch((opw>>4)&15)
			{
			case 0x0:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPZI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPZ_Reg;
				break;
			case 0x1:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPLI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPL_Reg;
				break;
			case 0x2:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPZF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPZF_Reg;
				break;
			case 0x3:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPLF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPLF_Reg;
				break;
			case 0x4:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPZQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPZQ_Reg;
				break;
			case 0x5:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPPLQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPPLQ_Reg;
				break;

			case 0x6:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_JMP;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_JMP_Reg;
				break;
			case 0x7:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_JSR;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_JSR_Reg;
				break;
			case 0x8:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_JMPF;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_JMPF_Reg;
				break;
			case 0x9:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_JSRF;
				op->fmid=BTESR_FMID_REGRM;
				op->Run=BTESR_Op_JSRF_Reg;
				break;

			case 0xA:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTSI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTSI_Reg;
				break;
			case 0xB:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTUI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTUI_Reg;
				break;

			case 0xC:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTSB;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTSB_Reg;
				break;
			case 0xD:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTUB;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTUB_Reg;
				break;
			case 0xE:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTSW;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTSW_Reg;
				break;
			case 0xF:
				op->rm=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_EXTUW;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_EXTUW_Reg;
				break;
			}
			break;

		case 0x9: /* 29xm */
			switch((opw>>4)&15)
			{
			case 0x0:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_NEGI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_NEG_Reg;
				break;
			case 0x1:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_NOTI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_NOT_Reg;
				break;
			case 0x2:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_LNTI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_LNTI_Reg;
				break;
			case 0x3:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_STTI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_STTI_Reg;
				break;
			case 0x4:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_NEGQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_NEGQ_Reg;
				break;
			case 0x5:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_NOTQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_NOTQ_Reg;
				break;
			case 0x6:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_LNTQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_LNTQ_Reg;
				break;
			case 0x7:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_STNTI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_STNTI_Reg;
				break;

			case 0x8:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_NEGF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_NEGF_Reg;
				break;
			case 0x9:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_ABSF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_ABSF_Reg;
				break;
			case 0xA:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_SQRTF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_SQRTF_Reg;
				break;
			case 0xB:
				op->rn=btesr_mkfpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPZF;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPZF_Reg;
				break;
			case 0xC:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPZI;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPZ_Reg;
				break;
			case 0xD:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPZQ;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPZQ_Reg;
				break;
			case 0xE:
				op->rn=btesr_mkgpr(cpu, (opw   )&15);
				op->nmid=BTESR_NMID_CMPZP;
				op->fmid=BTESR_FMID_REGRN;
				op->Run=BTESR_Op_CMPZP_Reg;
				break;
			case 0xF:
				switch(opw&15)
				{
				case 0x0:
					op->nmid=BTESR_NMID_NOP;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_NOP_Z;
					break;
				case 0x1:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_RTS;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_RTS_Z;
					break;
				case 0x2:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_SLEEP;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_SLEEP_Z;
					break;
				case 0x3:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_RTE;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_RTE_Z;
					break;
				case 0x4:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_BREAK;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_BREAK_Z;
					break;
				case 0x5:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_SYNCO;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_SYNCO_Z;
					break;
				case 0x6:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_SYNCI;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_SYNCI_Z;
					break;
				case 0x7:
					op->fl|=BTESR_OPFL_CTRLF;
					op->nmid=BTESR_NMID_LABEL;
					op->fmid=BTESR_FMID_NONE;
					op->Run=BTESR_Op_NOP_Z;
					break;
				default:
					break;
				}
				break;
			}
			break;

		case 0xA: /* 2Anm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_TSTI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_TST_RegReg;
			break;
		case 0xB: /* 2Bnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_TSTQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_TSTQ_RegReg;
			break;

		case 0xC: /* 2Cnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_DIFFPB;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_DIFFPB_RegReg;
			break;
		case 0xD: /* 2Dnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_DIFFPW;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_DIFFPW_RegReg;
			break;
		case 0xE: /* 2Enm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_DIFFPI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_DIFFPI_RegReg;
			break;
		case 0xF: /* 2Fnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_DIFFPQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_DIFFPQ_RegReg;
			break;

		default:
			break;
		}
		break;

	case 0x3: /* 3--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 30nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPEQP;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPEQP_RegReg;
			break;
		case 0x1: /* 31nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGTP;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGTP_RegReg;
			break;
		case 0x2: /* 32nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGEP;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGEP_RegReg;
			break;
		case 0x3: /* 33nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPHII;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPHI_RegReg;
			break;
		case 0x4: /* 34nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPHSI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPHS_RegReg;
			break;
		case 0x5: /* 35nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPEQQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPEQQ_RegReg;
			break;
		case 0x6: /* 36nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGTQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGTQ_RegReg;
			break;
		case 0x7: /* 37nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPGEQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPGEQ_RegReg;
			break;
		case 0x8: /* 38nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPHIQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPHIQ_RegReg;
			break;
		case 0x9: /* 39nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_CMPHSQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_CMPHSQ_RegReg;
			break;

		case 0xA: /* 3Add */
			op->rn=BTESR_REG_OT;
			op->imm=((opw   )&255)*8;
			op->nmid=BTESR_NMID_BRAOT;
			op->fmid=BTESR_FMID_IMM;
			op->Run=BTESR_Op_BRAOT_Imm;
			break;
		case 0xB: /* 3Bdd */
			op->rn=BTESR_REG_OT;
			op->imm=((opw   )&255)*8;
			op->nmid=BTESR_NMID_BSROT;
			op->fmid=BTESR_FMID_IMM;
			op->Run=BTESR_Op_BSROT_Imm;
			break;

		case 0xC: /* 3Cnm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVF_RegLdIncReg;
			break;
		case 0xD: /* 3Dnm */
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVQ_RegLdIncReg;
			break;
		case 0xE: /* 3Enm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVF_StIncRegReg;
			break;
		case 0xF: /* 3Fnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVQ_StIncRegReg;
			break;

		default:
			break;
		}
		break;

	case 0x4: /* 4nii */
		op->rn=(opw>>12)&15;
		op->imm=(sbyte)((opw   )&255);
		op->nmid=BTESR_NMID_LDC8I;
		op->fmid=BTESR_FMID_REGIMM;
		op->Run=BTESR_Op_MOV_RegImm;
		break;
	case 0x5: /* 5nii */
		op->rn=(opw>>12)&15;
		op->imm=(sbyte)((opw   )&255);
		op->nmid=BTESR_NMID_LDCTI;
		op->fmid=BTESR_FMID_REGIMM;
		op->Run=BTESR_Op_LDCTI_RegImm;
		break;

	case 0x6: /* 6edd */
		i=opw&1023;
		j=(((s32)i)<<22)>>22;
		op->imm=j;
		switch((opw>>10)&3)
		{
		case 0:
			op->imm=i;
			op->nmid=BTESR_NMID_LDCTQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDCTQ_RegImm;
			break;
		case 1:
			op->imm=pc+2+(j*2);
			op->nmid=BTESR_NMID_BRA;
			op->fmid=BTESR_FMID_ABS;
			op->Run=BTESR_Op_BRA_Abs;
			break;
		case 2:
			op->imm=pc+2+(j*2);
			op->nmid=BTESR_NMID_BRT;
			op->fmid=BTESR_FMID_ABS;
			op->Run=BTESR_Op_BRT_Abs;
			break;
		case 3:
			op->imm=pc+2+(j*2);
			op->nmid=BTESR_NMID_BRF;
			op->fmid=BTESR_FMID_ABS;
			op->Run=BTESR_Op_BRF_Abs;
			break;
		}
		break;

	case 0x7: /* 7--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 70ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=opw&15;
			op->nmid=BTESR_NMID_ADDI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_ADD_RegImm;
			break;
		case 0x1: /* 71ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=opw&15;
			op->nmid=BTESR_NMID_SUBI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_SUB_RegImm;
			break;
		case 0x2: /* 72ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			i=opw&15; i=(((s32)i)<<28)>>28;
			op->imm=i;
			op->nmid=BTESR_NMID_MULI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_MUL_RegImm;
			break;
		case 0x3: /* 73nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SHRI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SHR_RegReg;
			break;
		case 0x4: /* 74ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=opw&15;
			op->nmid=BTESR_NMID_SHLI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_SHL_RegImm;
			break;
		case 0x5: /* 75ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=16+(opw&15);
			op->nmid=BTESR_NMID_SHLI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_SHL_RegImm;
			break;
		case 0x6: /* 76ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=opw&15;
			op->nmid=BTESR_NMID_SARI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_SAR_RegImm;
			break;
		case 0x7: /* 77ni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->imm=16+(opw&15);
			op->nmid=BTESR_NMID_SARI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_SAR_RegImm;
			break;

		case 0x8: /* 78nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_LEAB;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_LEAB_RegReg;
			break;
		case 0x9: /* 79nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_LEAW;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_LEAW_RegReg;
			break;
		case 0xA: /* 7Anm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_LEAI;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_LEAI_RegReg;
			break;
		case 0xB: /* 7Bnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_LEAQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_LEAQ_RegReg;
			break;

		case 0xC: /* 7Cni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			i=opw&15; i=(((s32)i)<<28)>>28;
			op->imm=i;
			op->nmid=BTESR_NMID_LEAB;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LEAB_RegImm;
			break;
		case 0xD: /* 7Dni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			i=opw&15; i=(((s32)i)<<28)>>28;
			op->imm=i;
			op->nmid=BTESR_NMID_LEAW;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LEAW_RegImm;
			break;
		case 0xE: /* 7Eni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			i=opw&15; i=(((s32)i)<<28)>>28;
			op->imm=i;
			op->nmid=BTESR_NMID_LEAI;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LEAI_RegImm;
			break;
		case 0xF: /* 7Fni */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			i=opw&15; i=(((s32)i)<<28)>>28;
			op->imm=i;
			op->nmid=BTESR_NMID_LEAQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LEAQ_RegImm;
			break;

		default:
			break;
		}
		break;

	case 0x8: /* 8ned */
		i=opw&63;
		j=(((s32)i)<<26)>>26;
		op->imm=j;
		op->rn=btesr_mkgpr(cpu, (opw>>8)&15);
		op->rm=op->rn;
		switch((opw>>6)&3)
		{
		case 0:
			op->nmid=BTESR_NMID_LDSPQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDSPQ_RegImm;
			break;
		case 1:
			op->nmid=BTESR_NMID_STSPQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_STSPQ_RegImm;
			break;
		case 2:
			op->nmid=BTESR_NMID_LDSPF;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDSPF_RegImm;
			break;
		case 3:
			op->nmid=BTESR_NMID_STSPF;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_STSPF_RegImm;
			break;
		}
		break;

	case 0x9: /* 9--- */
		switch((opw>>8)&15)
		{
		case 0x0: /* 90nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVB_RegLdIncReg;
			break;
		case 0x1: /* 91nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVW_RegLdIncReg;
			break;
		case 0x2: /* 92nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVI_RegLdIncReg;
			break;
		case 0x3: /* 93nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_REGLDINCREG;
			op->Run=BTESR_Op_MOVQ_RegLdIncReg;
			break;
		case 0x4: /* 94nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVB_StIncRegReg;
			break;
		case 0x5: /* 95nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVW_StIncRegReg;
			break;
		case 0x6: /* 96nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVI_StIncRegReg;
			break;
		case 0x7: /* 97nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_STINCREGREG;
			op->Run=BTESR_Op_MOVQ_StIncRegReg;
			break;

		case 0x8: /* 98nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_REGLDDECREG;
			op->Run=BTESR_Op_MOVB_RegLdDecReg;
			break;
		case 0x9: /* 99nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_REGLDDECREG;
			op->Run=BTESR_Op_MOVW_RegLdDecReg;
			break;
		case 0xA: /* 9Anm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_REGLDDECREG;
			op->Run=BTESR_Op_MOVI_RegLdDecReg;
			break;
		case 0xB: /* 9Bnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_REGLDDECREG;
			op->Run=BTESR_Op_MOVQ_RegLdDecReg;
			break;
		case 0xC: /* 9Cnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_STDECREGREG;
			op->Run=BTESR_Op_MOVB_StDecRegReg;
			break;
		case 0xD: /* 9Dnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_STDECREGREG;
			op->Run=BTESR_Op_MOVW_StDecRegReg;
			break;
		case 0xE: /* 9Enm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_STDECREGREG;
			op->Run=BTESR_Op_MOVI_StDecRegReg;
			break;
		case 0xF: /* 9Fnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_STDECREGREG;
			op->Run=BTESR_Op_MOVQ_StDecRegReg;
			break;
		}
		break;

	case 0xA: /* A--- */
		switch((opw>>8)&15)
		{
		case 0x8: /* A8nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_ADDQ_RegReg;
			break;
		case 0x9: /* A9nm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SUBQ_RegReg;
			break;
		case 0xA: /* AAnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_MULQ_RegReg;
			break;
		case 0xB: /* ABnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ADDQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_ANDQ_RegReg;
			break;
		case 0xC: /* ACnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_ORQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_ORQ_RegReg;
			break;
		case 0xD: /* ADnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_XORQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_XORQ_RegReg;
			break;
		case 0xE: /* AEnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SHLQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SHLQ_RegReg;
			break;
		case 0xF: /* AFnm */
			op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
			op->rm=btesr_mkgpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_SARQ;
			op->fmid=BTESR_FMID_REGREG;
			op->Run=BTESR_Op_SARQ_RegReg;
			break;
		}
		break;

	case 0xB: /* Bned */
		i=opw&63;
		j=(((s32)i)<<26)>>26;
		op->imm=j;
		op->rn=btesr_mkgpr(cpu, (opw>>8)&15);
		op->rm=op->rn;
		switch((opw>>6)&3)
		{
		case 0:
			op->nmid=BTESR_NMID_LDOTQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDOTQ_RegImm;
			break;
		case 1:
			op->nmid=BTESR_NMID_LDCTQ;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDCTQ_RegImm;
			break;
		case 2:
			op->nmid=BTESR_NMID_LDCTF;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDCTF_RegImm;
			break;
		case 3:
			op->nmid=BTESR_NMID_LDCTD;
			op->fmid=BTESR_FMID_REGIMM;
			op->Run=BTESR_Op_LDCTD_RegImm;
			break;
		}
		break;

	default:
		break;
	}
	
	return(0);
}
