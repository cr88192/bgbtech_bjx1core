/*

Floating Point Registers

Doesn't perform any conversion.

 */

`include "CoreDefs.v"

module RegFPR2(
	/* verilator lint_off UNUSED */
	clock, reset,
	regIdRs, regValRs,
	regIdRt, regValRt,
	regIdRn, regValRn,
	regIdRo, regValRo,
	regMode, regCsFl,
	regStMode,
	ctlInFpul,	ctlOutFpul
	);

input clock;
input reset;

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRn;
input[6:0]		regIdRo;

output[63:0]	regValRs;
output[63:0]	regValRt;
output[63:0]	regValRn;
input[63:0]		regValRo;

input[1:0]		regMode;			//get mode
input[15:0]		regCsFl;
input[1:0]		regStMode;			//set mode

input[31:0]		ctlInFpul;		//FPUL in
output[31:0]	ctlOutFpul;		//FPUL out


// reg[31:0]		regFprH[15:0];		//FR0, FR2, FR4, ...
// reg[31:0]		regFprL[15:0];		//FR1, FR3, FR5, ...

reg[31:0]		regFprFR00;
reg[31:0]		regFprFR01;
reg[31:0]		regFprFR02;
reg[31:0]		regFprFR03;
reg[31:0]		regFprFR04;
reg[31:0]		regFprFR05;
reg[31:0]		regFprFR06;
reg[31:0]		regFprFR07;
reg[31:0]		regFprFR08;
reg[31:0]		regFprFR09;
reg[31:0]		regFprFR10;
reg[31:0]		regFprFR11;
reg[31:0]		regFprFR12;
reg[31:0]		regFprFR13;
reg[31:0]		regFprFR14;
reg[31:0]		regFprFR15;

reg[31:0]		regFprXF00;
reg[31:0]		regFprXF01;
reg[31:0]		regFprXF02;
reg[31:0]		regFprXF03;
reg[31:0]		regFprXF04;
reg[31:0]		regFprXF05;
reg[31:0]		regFprXF06;
reg[31:0]		regFprXF07;
reg[31:0]		regFprXF08;
reg[31:0]		regFprXF09;
reg[31:0]		regFprXF10;
reg[31:0]		regFprXF11;
reg[31:0]		regFprXF12;
reg[31:0]		regFprXF13;
reg[31:0]		regFprXF14;
reg[31:0]		regFprXF15;

reg[31:0]		nxtRegFprFR00;
reg[31:0]		nxtRegFprFR01;
reg[31:0]		nxtRegFprFR02;
reg[31:0]		nxtRegFprFR03;
reg[31:0]		nxtRegFprFR04;
reg[31:0]		nxtRegFprFR05;
reg[31:0]		nxtRegFprFR06;
reg[31:0]		nxtRegFprFR07;
reg[31:0]		nxtRegFprFR08;
reg[31:0]		nxtRegFprFR09;
reg[31:0]		nxtRegFprFR10;
reg[31:0]		nxtRegFprFR11;
reg[31:0]		nxtRegFprFR12;
reg[31:0]		nxtRegFprFR13;
reg[31:0]		nxtRegFprFR14;
reg[31:0]		nxtRegFprFR15;

reg[31:0]		nxtRegFprXF00;
reg[31:0]		nxtRegFprXF01;
reg[31:0]		nxtRegFprXF02;
reg[31:0]		nxtRegFprXF03;
reg[31:0]		nxtRegFprXF04;
reg[31:0]		nxtRegFprXF05;
reg[31:0]		nxtRegFprXF06;
reg[31:0]		nxtRegFprXF07;
reg[31:0]		nxtRegFprXF08;
reg[31:0]		nxtRegFprXF09;
reg[31:0]		nxtRegFprXF10;
reg[31:0]		nxtRegFprXF11;
reg[31:0]		nxtRegFprXF12;
reg[31:0]		nxtRegFprXF13;
reg[31:0]		nxtRegFprXF14;
reg[31:0]		nxtRegFprXF15;


reg[63:0]		tRegValRs;
reg[63:0]		tRegValRt;
reg[63:0]		tRegValRn;

assign			regValRs = tRegValRs;
assign			regValRt = tRegValRt;
assign			regValRn = tRegValRn;

reg[31:0]		tFpul;
assign			ctlOutFpul = tFpul;

reg		regGet64;
reg		regSet64;

always @*
begin

	nxtRegFprFR00 = regFprFR00;		nxtRegFprFR01 = regFprFR01;
	nxtRegFprFR02 = regFprFR02;		nxtRegFprFR03 = regFprFR03;
	nxtRegFprFR04 = regFprFR04;		nxtRegFprFR05 = regFprFR05;
	nxtRegFprFR06 = regFprFR06;		nxtRegFprFR07 = regFprFR07;
	nxtRegFprFR08 = regFprFR08;		nxtRegFprFR09 = regFprFR09;
	nxtRegFprFR10 = regFprFR10;		nxtRegFprFR11 = regFprFR11;
	nxtRegFprFR12 = regFprFR12;		nxtRegFprFR13 = regFprFR13;
	nxtRegFprFR14 = regFprFR14;		nxtRegFprFR15 = regFprFR15;

	nxtRegFprXF00 = regFprXF00;		nxtRegFprXF01 = regFprXF01;
	nxtRegFprXF02 = regFprXF02;		nxtRegFprXF03 = regFprXF03;
	nxtRegFprXF04 = regFprXF04;		nxtRegFprXF05 = regFprXF05;
	nxtRegFprXF06 = regFprXF06;		nxtRegFprXF07 = regFprXF07;
	nxtRegFprXF08 = regFprXF08;		nxtRegFprXF09 = regFprXF09;
	nxtRegFprXF10 = regFprXF10;		nxtRegFprXF11 = regFprXF11;
	nxtRegFprXF12 = regFprXF12;		nxtRegFprXF13 = regFprXF13;
	nxtRegFprXF14 = regFprXF14;		nxtRegFprXF15 = regFprXF15;

	tRegValRs=0;
	tRegValRt=0;
	tRegValRn=0;
	
	regGet64 = regMode[0];
	regSet64 = regStMode[0];
	
	tFpul = ctlInFpul;

	if(regGet64)
	begin

		case(regIdRs)
			UREG_FR0:	tRegValRs = {regFprFR00, regFprFR01};
			UREG_FR1:	tRegValRs = {regFprXF00, regFprXF01};
			UREG_FR2:	tRegValRs = {regFprFR02, regFprFR03};
			UREG_FR3:	tRegValRs = {regFprXF02, regFprXF03};
			UREG_FR4:	tRegValRs = {regFprFR04, regFprFR05};
			UREG_FR5:	tRegValRs = {regFprXF04, regFprXF05};
			UREG_FR6:	tRegValRs = {regFprFR06, regFprFR07};
			UREG_FR7:	tRegValRs = {regFprXF06, regFprXF07};
			UREG_FR8:	tRegValRs = {regFprFR08, regFprFR09};
			UREG_FR9:	tRegValRs = {regFprXF08, regFprXF09};
			UREG_FR10:	tRegValRs = {regFprFR10, regFprFR11};
			UREG_FR11:	tRegValRs = {regFprXF10, regFprXF11};
			UREG_FR12:	tRegValRs = {regFprFR12, regFprFR13};
			UREG_FR13:	tRegValRs = {regFprXF12, regFprXF13};
			UREG_FR14:	tRegValRs = {regFprFR14, regFprFR15};
			UREG_FR15:	tRegValRs = {regFprXF14, regFprXF15};
			UREG_FPUL:	tRegValRs = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

		case(regIdRt)
			UREG_FR0:	tRegValRt = {regFprFR00, regFprFR01};
			UREG_FR1:	tRegValRt = {regFprXF00, regFprXF01};
			UREG_FR2:	tRegValRt = {regFprFR02, regFprFR03};
			UREG_FR3:	tRegValRt = {regFprXF02, regFprXF03};
			UREG_FR4:	tRegValRt = {regFprFR04, regFprFR05};
			UREG_FR5:	tRegValRt = {regFprXF04, regFprXF05};
			UREG_FR6:	tRegValRt = {regFprFR06, regFprFR07};
			UREG_FR7:	tRegValRt = {regFprXF06, regFprXF07};
			UREG_FR8:	tRegValRt = {regFprFR08, regFprFR09};
			UREG_FR9:	tRegValRt = {regFprXF08, regFprXF09};
			UREG_FR10:	tRegValRt = {regFprFR10, regFprFR11};
			UREG_FR11:	tRegValRt = {regFprXF10, regFprXF11};
			UREG_FR12:	tRegValRt = {regFprFR12, regFprFR13};
			UREG_FR13:	tRegValRt = {regFprXF12, regFprXF13};
			UREG_FR14:	tRegValRt = {regFprFR14, regFprFR15};
			UREG_FR15:	tRegValRt = {regFprXF14, regFprXF15};
			UREG_FPUL:	tRegValRt = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

		case(regIdRn)
			UREG_FR0:	tRegValRn = {regFprFR00, regFprFR01};
			UREG_FR1:	tRegValRn = {regFprXF00, regFprXF01};
			UREG_FR2:	tRegValRn = {regFprFR02, regFprFR03};
			UREG_FR3:	tRegValRn = {regFprXF02, regFprXF03};
			UREG_FR4:	tRegValRn = {regFprFR04, regFprFR05};
			UREG_FR5:	tRegValRn = {regFprXF04, regFprXF05};
			UREG_FR6:	tRegValRn = {regFprFR06, regFprFR07};
			UREG_FR7:	tRegValRn = {regFprXF06, regFprXF07};
			UREG_FR8:	tRegValRn = {regFprFR08, regFprFR09};
			UREG_FR9:	tRegValRn = {regFprXF08, regFprXF09};
			UREG_FR10:	tRegValRn = {regFprFR10, regFprFR11};
			UREG_FR11:	tRegValRn = {regFprXF10, regFprXF11};
			UREG_FR12:	tRegValRn = {regFprFR12, regFprFR13};
			UREG_FR13:	tRegValRn = {regFprXF12, regFprXF13};
			UREG_FR14:	tRegValRn = {regFprFR14, regFprFR15};
			UREG_FR15:	tRegValRn = {regFprXF14, regFprXF15};
			UREG_FPUL:	tRegValRn = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

	end else begin

		case(regIdRs)
			UREG_FR0:	tRegValRs = {UV32_XX, regFprFR00};
			UREG_FR1:	tRegValRs = {UV32_XX, regFprFR01};
			UREG_FR2:	tRegValRs = {UV32_XX, regFprFR02};
			UREG_FR3:	tRegValRs = {UV32_XX, regFprFR03};
			UREG_FR4:	tRegValRs = {UV32_XX, regFprFR04};
			UREG_FR5:	tRegValRs = {UV32_XX, regFprFR05};
			UREG_FR6:	tRegValRs = {UV32_XX, regFprFR06};
			UREG_FR7:	tRegValRs = {UV32_XX, regFprFR07};
			UREG_FR8:	tRegValRs = {UV32_XX, regFprFR08};
			UREG_FR9:	tRegValRs = {UV32_XX, regFprFR09};
			UREG_FR10:	tRegValRs = {UV32_XX, regFprFR10};
			UREG_FR11:	tRegValRs = {UV32_XX, regFprFR11};
			UREG_FR12:	tRegValRs = {UV32_XX, regFprFR12};
			UREG_FR13:	tRegValRs = {UV32_XX, regFprFR13};
			UREG_FR14:	tRegValRs = {UV32_XX, regFprFR14};
			UREG_FR15:	tRegValRs = {UV32_XX, regFprFR15};

			UREG_XF0:	tRegValRs = {UV32_XX, regFprXF00};
			UREG_XF1:	tRegValRs = {UV32_XX, regFprXF01};
			UREG_XF2:	tRegValRs = {UV32_XX, regFprXF02};
			UREG_XF3:	tRegValRs = {UV32_XX, regFprXF03};
			UREG_XF4:	tRegValRs = {UV32_XX, regFprXF04};
			UREG_XF5:	tRegValRs = {UV32_XX, regFprXF05};
			UREG_XF6:	tRegValRs = {UV32_XX, regFprXF06};
			UREG_XF7:	tRegValRs = {UV32_XX, regFprXF07};
			UREG_XF8:	tRegValRs = {UV32_XX, regFprXF08};
			UREG_XF9:	tRegValRs = {UV32_XX, regFprXF09};
			UREG_XF10:	tRegValRs = {UV32_XX, regFprXF10};
			UREG_XF11:	tRegValRs = {UV32_XX, regFprXF11};
			UREG_XF12:	tRegValRs = {UV32_XX, regFprXF12};
			UREG_XF13:	tRegValRs = {UV32_XX, regFprXF13};
			UREG_XF14:	tRegValRs = {UV32_XX, regFprXF14};
			UREG_XF15:	tRegValRs = {UV32_XX, regFprXF15};

			UREG_FPUL:	tRegValRs = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

		case(regIdRt)
			UREG_FR0:	tRegValRt = {UV32_XX, regFprFR00};
			UREG_FR1:	tRegValRt = {UV32_XX, regFprFR01};
			UREG_FR2:	tRegValRt = {UV32_XX, regFprFR02};
			UREG_FR3:	tRegValRt = {UV32_XX, regFprFR03};
			UREG_FR4:	tRegValRt = {UV32_XX, regFprFR04};
			UREG_FR5:	tRegValRt = {UV32_XX, regFprFR05};
			UREG_FR6:	tRegValRt = {UV32_XX, regFprFR06};
			UREG_FR7:	tRegValRt = {UV32_XX, regFprFR07};
			UREG_FR8:	tRegValRt = {UV32_XX, regFprFR08};
			UREG_FR9:	tRegValRt = {UV32_XX, regFprFR09};
			UREG_FR10:	tRegValRt = {UV32_XX, regFprFR10};
			UREG_FR11:	tRegValRt = {UV32_XX, regFprFR11};
			UREG_FR12:	tRegValRt = {UV32_XX, regFprFR12};
			UREG_FR13:	tRegValRt = {UV32_XX, regFprFR13};
			UREG_FR14:	tRegValRt = {UV32_XX, regFprFR14};
			UREG_FR15:	tRegValRt = {UV32_XX, regFprFR15};

			UREG_XF0:	tRegValRt = {UV32_XX, regFprXF00};
			UREG_XF1:	tRegValRt = {UV32_XX, regFprXF01};
			UREG_XF2:	tRegValRt = {UV32_XX, regFprXF02};
			UREG_XF3:	tRegValRt = {UV32_XX, regFprXF03};
			UREG_XF4:	tRegValRt = {UV32_XX, regFprXF04};
			UREG_XF5:	tRegValRt = {UV32_XX, regFprXF05};
			UREG_XF6:	tRegValRt = {UV32_XX, regFprXF06};
			UREG_XF7:	tRegValRt = {UV32_XX, regFprXF07};
			UREG_XF8:	tRegValRt = {UV32_XX, regFprXF08};
			UREG_XF9:	tRegValRt = {UV32_XX, regFprXF09};
			UREG_XF10:	tRegValRt = {UV32_XX, regFprXF10};
			UREG_XF11:	tRegValRt = {UV32_XX, regFprXF11};
			UREG_XF12:	tRegValRt = {UV32_XX, regFprXF12};
			UREG_XF13:	tRegValRt = {UV32_XX, regFprXF13};
			UREG_XF14:	tRegValRt = {UV32_XX, regFprXF14};
			UREG_XF15:	tRegValRt = {UV32_XX, regFprXF15};

			UREG_FPUL:	tRegValRt = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

		case(regIdRn)
			UREG_FR0:	tRegValRn = {UV32_XX, regFprFR00};
			UREG_FR1:	tRegValRn = {UV32_XX, regFprFR01};
			UREG_FR2:	tRegValRn = {UV32_XX, regFprFR02};
			UREG_FR3:	tRegValRn = {UV32_XX, regFprFR03};
			UREG_FR4:	tRegValRn = {UV32_XX, regFprFR04};
			UREG_FR5:	tRegValRn = {UV32_XX, regFprFR05};
			UREG_FR6:	tRegValRn = {UV32_XX, regFprFR06};
			UREG_FR7:	tRegValRn = {UV32_XX, regFprFR07};
			UREG_FR8:	tRegValRn = {UV32_XX, regFprFR08};
			UREG_FR9:	tRegValRn = {UV32_XX, regFprFR09};
			UREG_FR10:	tRegValRn = {UV32_XX, regFprFR10};
			UREG_FR11:	tRegValRn = {UV32_XX, regFprFR11};
			UREG_FR12:	tRegValRn = {UV32_XX, regFprFR12};
			UREG_FR13:	tRegValRn = {UV32_XX, regFprFR13};
			UREG_FR14:	tRegValRn = {UV32_XX, regFprFR14};
			UREG_FR15:	tRegValRn = {UV32_XX, regFprFR15};

			UREG_XF0:	tRegValRn = {UV32_XX, regFprXF00};
			UREG_XF1:	tRegValRn = {UV32_XX, regFprXF01};
			UREG_XF2:	tRegValRn = {UV32_XX, regFprXF02};
			UREG_XF3:	tRegValRn = {UV32_XX, regFprXF03};
			UREG_XF4:	tRegValRn = {UV32_XX, regFprXF04};
			UREG_XF5:	tRegValRn = {UV32_XX, regFprXF05};
			UREG_XF6:	tRegValRn = {UV32_XX, regFprXF06};
			UREG_XF7:	tRegValRn = {UV32_XX, regFprXF07};
			UREG_XF8:	tRegValRn = {UV32_XX, regFprXF08};
			UREG_XF9:	tRegValRn = {UV32_XX, regFprXF09};
			UREG_XF10:	tRegValRn = {UV32_XX, regFprXF10};
			UREG_XF11:	tRegValRn = {UV32_XX, regFprXF11};
			UREG_XF12:	tRegValRn = {UV32_XX, regFprXF12};
			UREG_XF13:	tRegValRn = {UV32_XX, regFprXF13};
			UREG_XF14:	tRegValRn = {UV32_XX, regFprXF14};
			UREG_XF15:	tRegValRn = {UV32_XX, regFprXF15};

			UREG_FPUL:	tRegValRn = {UV32_XX, ctlInFpul};
			default:	begin end
		endcase

	end

	if(regSet64)
	begin

		case(regIdRo)
			UREG_FR0:	{nxtRegFprFR00, nxtRegFprFR01} = regValRo;
			UREG_FR1:	{nxtRegFprXF00, nxtRegFprXF01} = regValRo;
			UREG_FR2:	{nxtRegFprFR02, nxtRegFprFR03} = regValRo;
			UREG_FR3:	{nxtRegFprXF02, nxtRegFprXF03} = regValRo;
			UREG_FR4:	{nxtRegFprFR04, nxtRegFprFR05} = regValRo;
			UREG_FR5:	{nxtRegFprXF04, nxtRegFprXF05} = regValRo;
			UREG_FR6:	{nxtRegFprFR06, nxtRegFprFR07} = regValRo;
			UREG_FR7:	{nxtRegFprXF06, nxtRegFprXF07} = regValRo;
			UREG_FR8:	{nxtRegFprFR08, nxtRegFprFR09} = regValRo;
			UREG_FR9:	{nxtRegFprXF08, nxtRegFprXF09} = regValRo;
			UREG_FR10:	{nxtRegFprFR10, nxtRegFprFR11} = regValRo;
			UREG_FR11:	{nxtRegFprXF10, nxtRegFprXF11} = regValRo;
			UREG_FR12:	{nxtRegFprFR12, nxtRegFprFR13} = regValRo;
			UREG_FR13:	{nxtRegFprXF12, nxtRegFprXF13} = regValRo;
			UREG_FR14:	{nxtRegFprFR14, nxtRegFprFR15} = regValRo;
			UREG_FR15:	{nxtRegFprXF14, nxtRegFprXF15} = regValRo;

			UREG_FPUL:	tFpul = regValRo[31:0];

			default:	begin end
		endcase

	end
	else
	begin

		case(regIdRo)
			UREG_FR0:	nxtRegFprFR00 = regValRo[31:0];
			UREG_FR1:	nxtRegFprFR01 = regValRo[31:0];
			UREG_FR2:	nxtRegFprFR02 = regValRo[31:0];
			UREG_FR3:	nxtRegFprFR03 = regValRo[31:0];
			UREG_FR4:	nxtRegFprFR04 = regValRo[31:0];
			UREG_FR5:	nxtRegFprFR05 = regValRo[31:0];
			UREG_FR6:	nxtRegFprFR06 = regValRo[31:0];
			UREG_FR7:	nxtRegFprFR07 = regValRo[31:0];
			UREG_FR8:	nxtRegFprFR08 = regValRo[31:0];
			UREG_FR9:	nxtRegFprFR09 = regValRo[31:0];
			UREG_FR10:	nxtRegFprFR10 = regValRo[31:0];
			UREG_FR11:	nxtRegFprFR11 = regValRo[31:0];
			UREG_FR12:	nxtRegFprFR12 = regValRo[31:0];
			UREG_FR13:	nxtRegFprFR13 = regValRo[31:0];
			UREG_FR14:	nxtRegFprFR14 = regValRo[31:0];
			UREG_FR15:	nxtRegFprFR15 = regValRo[31:0];

			UREG_XF0:	nxtRegFprXF00 = regValRo[31:0];
			UREG_XF1:	nxtRegFprXF01 = regValRo[31:0];
			UREG_XF2:	nxtRegFprXF02 = regValRo[31:0];
			UREG_XF3:	nxtRegFprXF03 = regValRo[31:0];
			UREG_XF4:	nxtRegFprXF04 = regValRo[31:0];
			UREG_XF5:	nxtRegFprXF05 = regValRo[31:0];
			UREG_XF6:	nxtRegFprXF06 = regValRo[31:0];
			UREG_XF7:	nxtRegFprXF07 = regValRo[31:0];
			UREG_XF8:	nxtRegFprXF08 = regValRo[31:0];
			UREG_XF9:	nxtRegFprXF09 = regValRo[31:0];
			UREG_XF10:	nxtRegFprXF10 = regValRo[31:0];
			UREG_XF11:	nxtRegFprXF11 = regValRo[31:0];
			UREG_XF12:	nxtRegFprXF12 = regValRo[31:0];
			UREG_XF13:	nxtRegFprXF13 = regValRo[31:0];
			UREG_XF14:	nxtRegFprXF14 = regValRo[31:0];
			UREG_XF15:	nxtRegFprXF15 = regValRo[31:0];

			UREG_FPUL:	tFpul = regValRo[31:0];

			default:	begin end
		endcase

	end
end

always @ (posedge clock)
begin

	regFprFR00 <= nxtRegFprFR00;
	regFprFR01 <= nxtRegFprFR01;
	regFprFR02 <= nxtRegFprFR02;
	regFprFR03 <= nxtRegFprFR03;
	regFprFR04 <= nxtRegFprFR04;
	regFprFR05 <= nxtRegFprFR05;
	regFprFR06 <= nxtRegFprFR06;
	regFprFR07 <= nxtRegFprFR07;
	regFprFR08 <= nxtRegFprFR08;
	regFprFR09 <= nxtRegFprFR09;
	regFprFR10 <= nxtRegFprFR10;
	regFprFR11 <= nxtRegFprFR11;
	regFprFR12 <= nxtRegFprFR12;
	regFprFR13 <= nxtRegFprFR13;
	regFprFR14 <= nxtRegFprFR14;
	regFprFR15 <= nxtRegFprFR15;

	regFprXF00 <= nxtRegFprXF00;
	regFprXF01 <= nxtRegFprXF01;
	regFprXF02 <= nxtRegFprXF02;
	regFprXF03 <= nxtRegFprXF03;
	regFprXF04 <= nxtRegFprXF04;
	regFprXF05 <= nxtRegFprXF05;
	regFprXF06 <= nxtRegFprXF06;
	regFprXF07 <= nxtRegFprXF07;
	regFprXF08 <= nxtRegFprXF08;
	regFprXF09 <= nxtRegFprXF09;
	regFprXF10 <= nxtRegFprXF10;
	regFprXF11 <= nxtRegFprXF11;
	regFprXF12 <= nxtRegFprXF12;
	regFprXF13 <= nxtRegFprXF13;
	regFprXF14 <= nxtRegFprXF14;
	regFprXF15 <= nxtRegFprXF15;

end


endmodule
