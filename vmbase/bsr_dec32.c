int BTESR_DecodeOpcode_Dec32_E(BTESR_CpuState *cpu,
	BTESR_Opcode *op, btesr_addr pc, u16 opw, u16 opw2)
{
	s32 i, j, k;
	switch((opw>>8)&15)
	{
	case 0x0: /* E0-- */
		switch((opw>>4)&15)
		{
		case 0x0: /* E00x */
			switch((opw>>4)&15)
			{
			case 0x0: /* E000 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVB;
				op->fmid=BTESR_FMID_REGLDREG2DISP;
				op->Run=BTESR_Op_MOVB_RegLdReg2Disp;
				break;
			case 0x1: /* E001 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVW;
				op->fmid=BTESR_FMID_REGLDREG2DISP;
				op->Run=BTESR_Op_MOVW_RegLdReg2Disp;
				break;
			case 0x2: /* E002 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVI;
				op->fmid=BTESR_FMID_REGLDREG2DISP;
				op->Run=BTESR_Op_MOVI_RegLdReg2Disp;
				break;
			case 0x3: /* E003 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVQ;
				op->fmid=BTESR_FMID_REGLDREG2DISP;
				op->Run=BTESR_Op_MOVQ_RegLdReg2Disp;
				break;

			case 0x4: /* E004 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVB;
				op->fmid=BTESR_FMID_STREG2DISPREG;
				op->Run=BTESR_Op_MOVB_StReg2DispReg;
				break;
			case 0x5: /* E005 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVW;
				op->fmid=BTESR_FMID_STREG2DISPREG;
				op->Run=BTESR_Op_MOVW_StReg2DispReg;
				break;
			case 0x6: /* E006 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVI;
				op->fmid=BTESR_FMID_STREG2DISPREG;
				op->Run=BTESR_Op_MOVI_StReg2DispReg;
				break;
			case 0x7: /* E007 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVQ;
				op->fmid=BTESR_FMID_STREG2DISPREG;
				op->Run=BTESR_Op_MOVQ_StReg2DispReg;
				break;

			case 0x8: /* E008 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(sbyte)(opw2&255);
				op->nmid=BTESR_NMID_ADDI;
				op->fmid=BTESR_FMID_REGREGIMM;
				op->Run=BTESR_Op_ADD_RegRegImm;
				break;
			case 0x9: /* E009 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(sbyte)(opw2&255);
				op->nmid=BTESR_NMID_MULI;
				op->fmid=BTESR_FMID_REGREGIMM;
				op->Run=BTESR_Op_MUL_RegRegImm;
				break;
			case 0xA: /* E00A */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(byte)(opw2&255);
				op->nmid=BTESR_NMID_ANDI;
				op->fmid=BTESR_FMID_REGREGIMM;
				op->Run=BTESR_Op_AND_RegRegImm;
				break;
			case 0xB: /* E00B */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(byte)(opw2&255);
				op->nmid=BTESR_NMID_ORI;
				op->fmid=BTESR_FMID_REGREGIMM;
				op->Run=BTESR_Op_OR_RegRegImm;
				break;
			case 0xC: /* E00C */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(byte)(opw2&255);
				op->nmid=BTESR_NMID_XORI;
				op->fmid=BTESR_FMID_REGREGIMM;
				op->Run=BTESR_Op_XOR_RegRegImm;
				break;
			case 0xD: /* E00D */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=opw2&63;
				switch((opw>>6)&3)
				{
				case 0:
				case 1:
					op->nmid=BTESR_NMID_SHLI;
					op->fmid=BTESR_FMID_REGREGIMM;
					op->Run=BTESR_Op_SHL_RegRegImm;
					break;
				case 2:
					op->nmid=BTESR_NMID_SHRI;
					op->fmid=BTESR_FMID_REGREGIMM;
					op->Run=BTESR_Op_SHR_RegRegImm;
					break;
				case 3:
					op->nmid=BTESR_NMID_SARI;
					op->fmid=BTESR_FMID_REGREGIMM;
					op->Run=BTESR_Op_SAR_RegRegImm;
					break;
				}
				break;

			case 0xE: /* E00E */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=opw2&2047;
				if(!(opw2&0x0800))
				{
					op->nmid=BTESR_NMID_LDCTI;
					op->fmid=BTESR_FMID_REGIMM;
					op->Run=BTESR_Op_LDCTI_RegImm;
				}else
				{
					op->nmid=BTESR_NMID_LDCTQ;
					op->fmid=BTESR_FMID_REGIMM;
					op->Run=BTESR_Op_LDCTQ_RegImm;
				}
				break;
			case 0xF: /* E00E */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=opw2&2047;
				if(!(opw2&0x0800))
				{
					op->nmid=BTESR_NMID_LDCTF;
					op->fmid=BTESR_FMID_REGIMM;
					op->Run=BTESR_Op_LDCTF_RegImm;
				}else
				{
					op->nmid=BTESR_NMID_LDCTD;
					op->fmid=BTESR_FMID_REGIMM;
					op->Run=BTESR_Op_LDCTD_RegImm;
				}
				break;
			}
			break;

		case 0x1: /* E01x */
			switch((opw>>4)&15)
			{
			case 0x0: /* E010 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_ADDQ;
					op->Run=BTESR_Op_ADDQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_ADDI;
					op->Run=BTESR_Op_ADD_RegRegReg;		}
				break;

			case 0x1: /* E011 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_SUBQ;
					op->Run=BTESR_Op_SUBQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_SUBI;
					op->Run=BTESR_Op_SUB_RegRegReg;		}
				break;
			case 0x2: /* E012 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_MULQ;
					op->Run=BTESR_Op_MULQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_MULI;
					op->Run=BTESR_Op_MUL_RegRegReg;		}
				break;
			case 0x3: /* E013 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_ANDQ;
					op->Run=BTESR_Op_ANDQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_ANDI;
					op->Run=BTESR_Op_AND_RegRegReg;		}
				break;
			case 0x4: /* E014 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_ORQ;
					op->Run=BTESR_Op_ORQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_ORI;
					op->Run=BTESR_Op_OR_RegRegReg;		}
				break;
			case 0x5: /* E015 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_XORQ;
					op->Run=BTESR_Op_XORQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_XORI;
					op->Run=BTESR_Op_XOR_RegRegReg;		}
				break;
			case 0x6: /* E016 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_SHLQ;
					op->Run=BTESR_Op_SHLQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_SHLI;
					op->Run=BTESR_Op_SHL_RegRegReg;		}
				break;
			case 0x7: /* E017 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				if(opw2&0x0800)
				{	op->nmid=BTESR_NMID_SARQ;
					op->Run=BTESR_Op_SARQ_RegRegReg;	}
				else
				{	op->nmid=BTESR_NMID_SARI;
					op->Run=BTESR_Op_SAR_RegRegReg;		}
				break;

			case 0x8: /* E018 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				op->nmid=BTESR_NMID_ADDF;
				op->Run=BTESR_Op_ADDF_RegRegReg;
				break;
			case 0x9: /* E019 */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				op->nmid=BTESR_NMID_SUBF;
				op->Run=BTESR_Op_SUBF_RegRegReg;
				break;
			case 0xA: /* E01A */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				op->nmid=BTESR_NMID_MULF;
				op->Run=BTESR_Op_MULF_RegRegReg;
				break;
			case 0xB: /* E01B */
				op->ro=btesr_mkgpr(cpu, ((opw2>>8)&15)|((opw>>10)&0x10));
				op->rn=btesr_mkgpr(cpu, ((opw2>>4)&15)|((opw>> 9)&0x10));
				op->rm=btesr_mkgpr(cpu, ((opw2>>0)&15)|((opw>> 8)&0x10));
				op->fmid=BTESR_FMID_REGREGREG;
				op->nmid=BTESR_NMID_DIVF;
				op->Run=BTESR_Op_DIVF_RegRegReg;
				break;
			}
			break;

		case 0x2: /* E02x */
			switch((opw>>4)&15)
			{
			case 0x0: /* E020 */
				op->rn=btesr_mkgpr(cpu, (opw2>>4)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>>0)&15);
				op->fmid=BTESR_FMID_REGREG;
				switch((opw2>>8)&0xFF)
				{
				case 0x07:
					op->nmid=BTESR_NMID_SHRQ;
					op->Run=BTESR_Op_SHRQ_RegReg;
					break;
				case 0x08:
					op->nmid=BTESR_NMID_SDIVI;
					op->Run=BTESR_Op_SDIV_RegReg;
					break;
				case 0x09:
					op->nmid=BTESR_NMID_UDIVI;
					op->Run=BTESR_Op_UDIV_RegReg;
					break;
				case 0x0A:
					op->nmid=BTESR_NMID_SMODI;
					op->Run=BTESR_Op_SMOD_RegReg;
					break;
				case 0x0B:
					op->nmid=BTESR_NMID_UMODI;
					op->Run=BTESR_Op_UMOD_RegReg;
					break;
				case 0x0C:
					op->nmid=BTESR_NMID_SDIVQ;
					op->Run=BTESR_Op_SDIVQ_RegReg;
					break;
				case 0x0D:
					op->nmid=BTESR_NMID_UDIVQ;
					op->Run=BTESR_Op_UDIVQ_RegReg;
					break;
				case 0x0E:
					op->nmid=BTESR_NMID_SMODQ;
					op->Run=BTESR_Op_SMODQ_RegReg;
					break;
				case 0x0F:
					op->nmid=BTESR_NMID_UMODQ;
					op->Run=BTESR_Op_UMODQ_RegReg;
					break;

				case 0x10:
					op->nmid=BTESR_NMID_LDIOI;
					op->Run=BTESR_Op_LDIOI_RegReg;
					break;
				case 0x11:
					op->nmid=BTESR_NMID_LDIOQ;
					op->Run=BTESR_Op_LDIOQ_RegReg;
					break;
				case 0x12:
					op->nmid=BTESR_NMID_STIOI;
					op->Run=BTESR_Op_STIOI_RegReg;
					break;
				case 0x13:
					op->nmid=BTESR_NMID_STIOQ;
					op->Run=BTESR_Op_STIOQ_RegReg;
					break;
				}
				break;
			}
			break;

		case 0x3: /* E03x */
			switch((opw>>4)&15)
			{
			case 0x0: /* E030 */
				i=opw2&4095;
				i=((s32)(i<<20))>>20;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ADDI;
				op->Run=BTESR_Op_ADD_RegImm;
				break;
			case 0x1: /* E031 */
				i=opw2&4095;
				i=((s32)(i<<20))>>20;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_MULI;
				op->Run=BTESR_Op_MUL_RegImm;
				break;
			case 0x2: /* E032 */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ANDI;
				op->Run=BTESR_Op_AND_RegImm;
				break;
			case 0x3: /* E033 */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ORI;
				op->Run=BTESR_Op_OR_RegImm;
				break;
			case 0x4: /* E034 */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_XORI;
				op->Run=BTESR_Op_XOR_RegImm;
				break;

			case 0x6: /* E036 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVV;
				op->fmid=BTESR_FMID_REGLDREG2DISP;
				op->Run=BTESR_Op_MOVV_RegLdReg2Disp;
				break;
			case 0x7: /* E037 */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->ro=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 4)&15);
				op->imm=opw2&15;
				op->nmid=BTESR_NMID_MOVV;
				op->fmid=BTESR_FMID_STREG2DISPREG;
				op->Run=BTESR_Op_MOVV_StReg2DispReg;
				break;

			case 0x8: /* E038 */
				i=opw2&4095;
				i=((s32)(i<<20))>>20;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=(s64)i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ADDQ;
				op->Run=BTESR_Op_ADDQ_RegImm;
				break;
			case 0x9: /* E039 */
				i=opw2&4095;
				i=((s32)(i<<20))>>20;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=(s64)i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_MULQ;
				op->Run=BTESR_Op_MULQ_RegImm;
				break;
			case 0xA: /* E03A */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ANDQ;
				op->Run=BTESR_Op_ANDQ_RegImm;
				break;
			case 0xB: /* E03B */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_ORQ;
				op->Run=BTESR_Op_ORQ_RegImm;
				break;
			case 0xC: /* E03C */
				i=opw2&4095;
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->imm=i;
				op->fmid=BTESR_FMID_REGIMM;
				op->nmid=BTESR_NMID_XORQ;
				op->Run=BTESR_Op_XORQ_RegImm;
				break;

			case 0xE: /* E03E */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(s64)((sbyte)opw2);
				op->fmid=BTESR_FMID_REGLDREGDISP;
				op->nmid=BTESR_NMID_MOVV;
				op->Run=BTESR_Op_MOVV_RegLdRegDisp;
				break;
			case 0xF: /* E03F */
				op->rn=btesr_mkgpr(cpu, (opw2>>12)&15);
				op->rm=btesr_mkgpr(cpu, (opw2>> 8)&15);
				op->imm=(s64)((sbyte)opw2);
				op->fmid=BTESR_FMID_STREGDISPREG;
				op->nmid=BTESR_NMID_MOVV;
				op->Run=BTESR_Op_MOVV_StRegDispReg;
				break;
			}
			break;
		}
		break;
	case 0x1: /* E1ni-iiii */
		i=(((opw   )&15)<<16)|(opw2&65535);
		i=((s32)(i<<12))>>12;
		op->rn=(opw>>12)&15;
		op->imm=i;
		op->nmid=BTESR_NMID_LDC20I;
		op->fmid=BTESR_FMID_REGIMM;
		op->Run=BTESR_Op_MOV_RegImm;
		break;
	case 0x2: /* E2nm-xddd */
		op->rn=btesr_mkgpr(cpu, (opw>>4)&15);
		op->rm=btesr_mkgpr(cpu, (opw   )&15);
		i=opw2&4095;
		i=((s32)(i<<20))>>20;
		op->imm=i;

		switch((opw2>>12)&15)
		{
		case 0x0:
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVB_RegLdRegDisp;
			break;
		case 0x1:
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVW_RegLdRegDisp;
			break;
		case 0x2:
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVI_RegLdRegDisp;
			break;
		case 0x3:
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVQ_RegLdRegDisp;
			break;
		case 0x4:
			op->nmid=BTESR_NMID_MOVB;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVB_StRegDispReg;
			break;
		case 0x5:
			op->nmid=BTESR_NMID_MOVW;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVW_StRegDispReg;
			break;
		case 0x6:
			op->nmid=BTESR_NMID_MOVI;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVI_StRegDispReg;
			break;
		case 0x7:
			op->nmid=BTESR_NMID_MOVQ;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVQ_StRegDispReg;
			break;
		case 0x8:
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVF_RegLdRegDisp;
			break;
		case 0x9:
			op->rn=btesr_mkfpr(cpu, (opw>>4)&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_MOVQ_RegLdRegDisp;
			break;
		case 0xA:
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVF;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVF_StRegDispReg;
			break;
		case 0xB:
			op->rm=btesr_mkfpr(cpu, (opw   )&15);
			op->nmid=BTESR_NMID_MOVD;
			op->fmid=BTESR_FMID_STREGDISPREG;
			op->Run=BTESR_Op_MOVQ_StRegDispReg;
			break;

		case 0xC:
			op->nmid=BTESR_NMID_LEAB;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_LEAB_RegLdRegDisp;
			break;
		case 0xD:
			op->nmid=BTESR_NMID_LEAW;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_LEAW_RegLdRegDisp;
			break;
		case 0xE:
			op->nmid=BTESR_NMID_LEAI;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_LEAI_RegLdRegDisp;
			break;
		case 0xF:
			op->nmid=BTESR_NMID_LEAQ;
			op->fmid=BTESR_FMID_REGLDREGDISP;
			op->Run=BTESR_Op_LEAQ_RegLdRegDisp;
			break;
		}
		break;
	}
	return(0);
}
