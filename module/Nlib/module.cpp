#include "elfformat.h"


std::map<int, std::string> FILE_TYPE
{
	decltype(FILE_TYPE)::value_type(ET_NONE, "No file type"),
	decltype(FILE_TYPE)::value_type(ET_REL, "Relocatable file"),
	decltype(FILE_TYPE)::value_type(ET_EXEC, "Executable file"),
	decltype(FILE_TYPE)::value_type(ET_DYN, "Shared object file"),
	decltype(FILE_TYPE)::value_type(ET_CORE, "Core file"),
	decltype(FILE_TYPE)::value_type(ET_LOPROC, "Beginning of processor-specific codes"),
	decltype(FILE_TYPE)::value_type(ET_HIPROC, "Processor-specific"),
};


std::map<int, std::string> OBJECT_FILE_CLASS
{
	decltype(OBJECT_FILE_CLASS)::value_type(ELFCLASSNONE, "NONE"),
	decltype(OBJECT_FILE_CLASS)::value_type(ELFCLASS32, "ELF32"),
	decltype(OBJECT_FILE_CLASS)::value_type(ELFCLASS64, "ELF64"),
};


std::map<int, std::string> OS_ABI
{
	decltype(OS_ABI)::value_type(ELFOSABI_NONE, "UNIX System V ABI"),
	decltype(OS_ABI)::value_type(ELFOSABI_HPUX, "HP-UX operating system"),
	decltype(OS_ABI)::value_type(ELFOSABI_NETBSD, "NetBSD"),
	decltype(OS_ABI)::value_type(ELFOSABI_GNU, "GNU/Linux"),
	decltype(OS_ABI)::value_type(ELFOSABI_LINUX, "Historical alias for ELFOSABI_GNU."),
	decltype(OS_ABI)::value_type(ELFOSABI_HURD, "GNU/Hurd"),
	decltype(OS_ABI)::value_type(ELFOSABI_SOLARIS, "Solaris"),
	decltype(OS_ABI)::value_type(ELFOSABI_AIX, "AIX"),
	decltype(OS_ABI)::value_type(ELFOSABI_IRIX, "IRIX"),
	decltype(OS_ABI)::value_type(ELFOSABI_FREEBSD, "FreeBSD"),
	decltype(OS_ABI)::value_type(ELFOSABI_TRU64, "TRU64 UNIX"),
	decltype(OS_ABI)::value_type(ELFOSABI_MODESTO, "Novell Modesto"),
	decltype(OS_ABI)::value_type(ELFOSABI_OPENBSD, "OpenBSD"),
	decltype(OS_ABI)::value_type(ELFOSABI_OPENVMS, "OpenVMS"),
	decltype(OS_ABI)::value_type(ELFOSABI_NSK, "Hewlett-Packard Non-Stop Kernel"),
	decltype(OS_ABI)::value_type(ELFOSABI_AROS, "AROS"),
	decltype(OS_ABI)::value_type(ELFOSABI_FENIXOS, "FenixOS"),
	decltype(OS_ABI)::value_type(ELFOSABI_C6000_ELFABI, "Bare-metal TMS320C6000"),
	decltype(OS_ABI)::value_type(ELFOSABI_C6000_LINUX, "Linux TMS320C6000"),
	decltype(OS_ABI)::value_type(ELFOSABI_ARM, "ARM"),
	decltype(OS_ABI)::value_type(ELFOSABI_STANDALONE, "Standalone (embedded) application"),
};


std::map<int, std::string> MACHINE_ARCHITECTURES
{
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_NONE, "No machine"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_M32, "AT&T WE 32100"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SPARC, "SPARC"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_386, "Intel 386"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68K, "Motorola 68000"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_88K, "Motorola 88000"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_486, "Intel 486 (deprecated)"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_860, "Intel 80860"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MIPS, "MIPS R3000"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_S370, "IBM System/370"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MIPS_RS3_LE, "MIPS RS3000 Little-endian"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PARISC, "Hewlett-Packard PA-RISC"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_VPP500, "Fujitsu VPP500"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SPARC32PLUS, "Enhanced instruction set SPARC"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_960, "Intel 80960"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PPC, "PowerPC"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PPC64, "PowerPC64"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_S390, "IBM System/390"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SPU, "IBM SPU/SPC"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_V800, "NEC V800"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_FR20, "Fujitsu FR20"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_RH32, "TRW RH-32"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_RCE, "Motorola RCE"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ARM, "ARM"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ALPHA, "DEC Alpha"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SH, "Hitachi SH"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SPARCV9, "SPARC V9"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TRICORE, "Siemens TriCore"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ARC, "Argonaut RISC Core"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_H8_300, "Hitachi H8/300"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_H8_300H, "Hitachi H8/300H"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_H8S, "Hitachi H8S"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_H8_500, "Hitachi H8/500"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_IA_64, "Intel IA-64 processor architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MIPS_X, "Stanford MIPS-X"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_COLDFIRE, "Motorola ColdFire"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68HC12, "Motorola M68HC12"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MMA, "Fujitsu MMA Multimedia Accelerator"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PCP, "Siemens PCP"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_NCPU, "Sony nCPU embedded RISC processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_NDR1, "Denso NDR1 microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_STARCORE, "Motorola Star*Core processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ME16, "Toyota ME16 processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ST100, "STMicroelectronics ST100 processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TINYJ, "Advanced Logic Corp. TinyJ embedded processor family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_X86_64, "AMD x86-64 architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PDSP, "Sony DSP Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PDP10, "Digital Equipment Corp. PDP-10"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PDP11, "Digital Equipment Corp. PDP-11"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_FX66, "Siemens FX66 microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ST9PLUS, "STMicroelectronics ST9+ 8/16 bit microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ST7, "STMicroelectronics ST7 8-bit microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68HC16, "Motorola MC68HC16 Microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68HC11, "Motorola MC68HC16 Microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68HC08, "Motorola MC68HC16 Microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_68HC05, "Motorola MC68HC16 Microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SVX, "Silicon Graphics SVx"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ST19, "STMicroelectronics ST19 8-bit microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_VAX, "Digital VAX"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CRIS, "Axis Communications 32-bit embedded processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_JAVELIN, "Infineon Technologies 32-bit embedded processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_FIREPATH, "Element 14 64-bit DSP Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ZSP, "LSI Logic 16-bit DSP Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MMIX, "Donald Knuth's educational 64-bit processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_HUANY, "Harvard University machine-independent object files"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PRISM, "SiTera Prism"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_AVR, "Atmel AVR 8-bit microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_FR30, "Fujitsu FR30"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_D10V, "Mitsubishi D10V"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_D30V, "Mitsubishi D30V"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_V850, "NEC v850"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_M32R, "Mitsubishi M32R"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MN10300, "Matsushita MN10300"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MN10200, "Matsushita MN10200"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_PJ, "picoJava"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_OPENRISC, "OpenRISC 32-bit embedded processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ARC_COMPACT, "ARC International ARCompact processor (old spelling/synonym: EM_ARC_A5)"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_XTENSA, "Tensilica Xtensa Architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_VIDEOCORE, "Alphamosaic VideoCore processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TMM_GPP, "Thompson Multimedia General Purpose Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_NS32K, "National Semiconductor 32000 series"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TPC, "Tenor Network TPC processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SNP1K, "Trebia SNP 1000 processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ST200, "STMicroelectronics (www.st.com) ST200"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_IP2K, "Ubicom IP2xxx microcontroller family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MAX, "MAX Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CR, "National Semiconductor CompactRISC microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_F2MC16, "Fujitsu F2MC16"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MSP430, "Texas Instruments embedded microcontroller msp430"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_BLACKFIN, "Analog Devices Blackfin (DSP) processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SE_C33, "S1C33 Family of Seiko Epson processors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SEP, "Sharp embedded microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ARCA, "Arca RISC Microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_UNICORE, "Microprocessor series from PKU-Unity Ltd. and MPRC of Peking University"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_EXCESS, "eXcess: 16/32/64-bit configurable embedded CPU"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_DXP, "Icera Semiconductor Inc. Deep Execution Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ALTERA_NIOS2, "Altera Nios II soft-core processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CRX, "National Semiconductor CompactRISC CRX"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_XGATE, "Motorola XGATE embedded processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_C166, "Infineon C16x/XC16x processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_M16C, "Renesas M16C series microprocessors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_DSPIC30F, "Microchip Technology dsPIC30F Digital Signal Controller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CE, "Freescale Communication Engine RISC core"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_M32C, "Renesas M32C series microprocessors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TSK3000, "Altium TSK3000 core"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_RS08, "Freescale RS08 embedded processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SHARC, "Analog Devices SHARC family of 32-bit DSP processors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ECOG2, "Cyan Technology eCOG2 microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SCORE7, "Sunplus S+core7 RISC processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_DSP24, "New Japan Radio (NJR) 24-bit DSP Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_VIDEOCORE3, "Broadcom VideoCore III processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_LATTICEMICO32, "RISC processor for Lattice FPGA architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SE_C17, "Seiko Epson C17 family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TI_C6000, "The Texas Instruments TMS320C6000 DSP family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TI_C2000, "The Texas Instruments TMS320C2000 DSP family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TI_C5500, "The Texas Instruments TMS320C55x DSP family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MMDSP_PLUS, "STMicroelectronics 64bit VLIW Data Signal Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CYPRESS_M8C, "Cypress M8C microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_R32C, "Renesas R32C series microprocessors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TRIMEDIA, "NXP Semiconductors TriMedia architecture family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_HEXAGON, "Qualcomm Hexagon processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_8051, "Intel 8051 and variants"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_STXP7X, "STMicroelectronics STxP7x family of configurable and extensible RISC processors"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_NDS32, "Andes Technology compact code size embedded RISC processor family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ECOG1, "Cyan Technology eCOG1X family"),
	//decltype(MACHINE_ARCHITECTURES)::value_type(EM_ECOG1X, "Cyan Technology eCOG1X family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MAXQ30, "Dallas Semiconductor MAXQ30 Core Micro-controllers"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_XIMO16, "New Japan Radio (NJR) 16-bit DSP Processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MANIK, "M2000 Reconfigurable RISC Microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CRAYNV2, "Cray Inc. NV2 vector architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_RX, "Renesas RX family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_METAG, "Imagination Technologies META processor architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_MCST_ELBRUS, "MCST Elbrus general purpose hardware architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ECOG16, "Cyan Technology eCOG16 family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CR16, "National Semiconductor CompactRISC CR16 16-bit microprocessor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ETPU, "Freescale Extended Time Processing Unit"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_SLE9X, "Infineon Technologies SLE9X core"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_L10M, "Intel L10M"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_K10M, "Intel K10M"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_AARCH64, "ARM AArch64"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_AVR32, "Atmel Corporation 32-bit microprocessor family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_STM8, "STMicroeletronics STM8 8-bit microcontroller"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TILE64, "Tilera TILE64 multicore architecture family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TILEPRO, "Tilera TILEPro multicore architecture family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CUDA, "NVIDIA CUDA architecture"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_TILEGX, "Tilera TILE-Gx multicore architecture family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_CLOUDSHIELD, "CloudShield architecture family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_COREA_1ST, "KIPO-KAIST Core-A 1st generation processor family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_COREA_2ND, "KIPO-KAIST Core-A 2nd generation processor family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_ARC_COMPACT2, "Synopsys ARCompact V2"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_OPEN8, "Open8 8-bit RISC soft processor core"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_RL78, "Renesas RL78 family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_VIDEOCORE5, "Broadcom VideoCore V processor"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_78KOR, "Renesas 78KOR family"),
	decltype(MACHINE_ARCHITECTURES)::value_type(EM_56800EX, "Freescale 56800EX Digital Signal Controller (DSC)")
};


std::map<int, std::string> PROGRAM_TYPE
{
	decltype(PROGRAM_TYPE)::value_type(PT_NULL, "NULL"),
	decltype(PROGRAM_TYPE)::value_type(PT_LOAD, "LOAD"),
	decltype(PROGRAM_TYPE)::value_type(PT_DYNAMIC, "DYNAMIC"),
	decltype(PROGRAM_TYPE)::value_type(PT_INTERP, "INTERP"),
	decltype(PROGRAM_TYPE)::value_type(PT_NOTE, "NOTE"),
	decltype(PROGRAM_TYPE)::value_type(PT_SHLIB, "SHLIB"),
	decltype(PROGRAM_TYPE)::value_type(PT_PHDR, "PHDR"),
	decltype(PROGRAM_TYPE)::value_type(PT_TLS, "TLS"),
	decltype(PROGRAM_TYPE)::value_type(PT_LOOS, "LOOS"),
	decltype(PROGRAM_TYPE)::value_type(PT_HIOS, "HIOS"),
	decltype(PROGRAM_TYPE)::value_type(PT_LOPROC, "LOPROC"),
	decltype(PROGRAM_TYPE)::value_type(PT_HIPROC, "HIPROC"),
	decltype(PROGRAM_TYPE)::value_type(PT_SUNW_EH_FRAME, "SUNW_EH_FRAME"),
	decltype(PROGRAM_TYPE)::value_type(PT_SUNW_UNWIND, "SUNW_UNWIND"),
	decltype(PROGRAM_TYPE)::value_type(PT_GNU_STACK, "GNU_STACK"),
	decltype(PROGRAM_TYPE)::value_type(PT_GNU_RELRO, "GNU_RELRO"),
	decltype(PROGRAM_TYPE)::value_type(PT_ARM_ARCHEXT, "ARM_ARCHEXT"),
	decltype(PROGRAM_TYPE)::value_type(PT_ARM_EXIDX, "ARM_EXIDX"),
	decltype(PROGRAM_TYPE)::value_type(PT_ARM_UNWIND, "ARM_UNWIND"),
	decltype(PROGRAM_TYPE)::value_type(PT_MIPS_REGINFO, "MIPS_REGINFO"),
	decltype(PROGRAM_TYPE)::value_type(PT_MIPS_RTPROC, "MIPS_RTPROC"),
	decltype(PROGRAM_TYPE)::value_type(PT_MIPS_OPTIONS, "MIPS_OPTIONS")
};


std::map<int, std::string> PROGRAM_FLAG
{
	decltype(PROGRAM_FLAG)::value_type(PF_X, "X"),
	decltype(PROGRAM_FLAG)::value_type(PF_W, "W"),
	decltype(PROGRAM_FLAG)::value_type(PF_R, "R"),
	decltype(PROGRAM_FLAG)::value_type(PF_MASKOS, "MASKOS"),
	decltype(PROGRAM_FLAG)::value_type(PF_MASKPROC, "MASKPROC"),
	decltype(PROGRAM_FLAG)::value_type(3, " WX"),
	decltype(PROGRAM_FLAG)::value_type(5, "R X"),
	decltype(PROGRAM_FLAG)::value_type(6, "RW"),
	decltype(PROGRAM_FLAG)::value_type(7, "RWX"),
};


std::map<int, std::string> SECTION_TYPE
{
	decltype(SECTION_TYPE)::value_type(SHT_NULL, "NULL"),
	decltype(SECTION_TYPE)::value_type(SHT_PROGBITS, "PROGBITS"),
	decltype(SECTION_TYPE)::value_type(SHT_SYMTAB, "SYMTAB"),
	decltype(SECTION_TYPE)::value_type(SHT_STRTAB, "STRTAB"),
	decltype(SECTION_TYPE)::value_type(SHT_RELA, "RELA"),
	decltype(SECTION_TYPE)::value_type(SHT_HASH, "HASH"),
	decltype(SECTION_TYPE)::value_type(SHT_DYNAMIC, "DYNAMIC"),
	decltype(SECTION_TYPE)::value_type(SHT_NOTE, "NOTE"),
	decltype(SECTION_TYPE)::value_type(SHT_NOBITS, "NOBITS"),
	decltype(SECTION_TYPE)::value_type(SHT_REL, "REL"),
	decltype(SECTION_TYPE)::value_type(SHT_SHLIB, "SHLIB"),
	decltype(SECTION_TYPE)::value_type(SHT_DYNSYM, "DYNSYM"),
	decltype(SECTION_TYPE)::value_type(SHT_INIT_ARRAY, "INIT_ARRAY"),
	decltype(SECTION_TYPE)::value_type(SHT_FINI_ARRAY, "FINI_ARRAY"),
	decltype(SECTION_TYPE)::value_type(SHT_PREINIT_ARRAY, "PREINIT_ARRAY"),
	decltype(SECTION_TYPE)::value_type(SHT_GROUP, "GROUP"),
	decltype(SECTION_TYPE)::value_type(SHT_SYMTAB_SHNDX, "SYMTAB_SHNDX"),
	decltype(SECTION_TYPE)::value_type(SHT_LOOS, "LOOS"),
	decltype(SECTION_TYPE)::value_type(SHT_GNU_ATTRIBUTES, "GNU_ATTRIBUTES"),
	decltype(SECTION_TYPE)::value_type(SHT_GNU_HASH, "GNU_HASH"),
	decltype(SECTION_TYPE)::value_type(SHT_GNU_verdef, "GNU_verdef"),
	decltype(SECTION_TYPE)::value_type(SHT_GNU_verneed, "GNU_verneed"),
	decltype(SECTION_TYPE)::value_type(SHT_GNU_versym, "GNU_versym"),
	decltype(SECTION_TYPE)::value_type(SHT_HIOS, "HIOS"),
	decltype(SECTION_TYPE)::value_type(SHT_LOPROC, "LOPROC"),
	decltype(SECTION_TYPE)::value_type(SHT_ARM_EXIDX, "ARM_EXIDX"),
	decltype(SECTION_TYPE)::value_type(SHT_ARM_PREEMPTMAP, "ARM_PREEMPTMAP"),
	decltype(SECTION_TYPE)::value_type(SHT_ARM_ATTRIBUTES, "ARM_ATTRIBUTES"),
	decltype(SECTION_TYPE)::value_type(SHT_ARM_DEBUGOVERLAY, "ARM_DEBUGOVERLAY"),
	decltype(SECTION_TYPE)::value_type(SHT_ARM_OVERLAYSECTION, "ARM_OVERLAYSECTION"),
	decltype(SECTION_TYPE)::value_type(SHT_HEX_ORDERED, "HEX_ORDERED"),
	decltype(SECTION_TYPE)::value_type(SHT_X86_64_UNWIND, "X86_64_UNWIND"),
	decltype(SECTION_TYPE)::value_type(SHT_MIPS_REGINFO, "MIPS_REGINFO"),
	decltype(SECTION_TYPE)::value_type(SHT_MIPS_OPTIONS, "MIPS_OPTIONS"),
	decltype(SECTION_TYPE)::value_type(SHT_HIPROC, "HIPROC"),
	decltype(SECTION_TYPE)::value_type(SHT_LOUSER, "LOUSER"),
	decltype(SECTION_TYPE)::value_type(SHT_HIUSER, "HIUSER")
};
