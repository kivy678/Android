#define PY_SSIZE_T_CLEAN

//////////////////////////////////////////////////////////////////////////////////

#include "elfformat.h"

#define STRING_SIZE						20

//////////////////////////////////////////////////////////////////////////////////

int DynParser(unsigned char* 			pchBuffer,
			  struct Elf32_Ehdr*		e32_ehdr,
			  struct Elf32_Dyn_Linker* 	e32_dyn_linker,
			  char* 					pchDynBuffer)
{

	//////////////////////////////////////////////////////////////////////////////////

	struct Elf32_Dyn_Linker* e32_dyn_Node 		= e32_dyn_linker;
	struct Elf32_Dyn_Linker* e32_dyn_NextNode   = NULL;

	Elf32_Off StartProcessHeaderTable 	= e32_ehdr->e_phoff;
	Elf32_Half ProcessHeaderTableSize 	= e32_ehdr->e_phentsize;
	Elf32_Half ProcessHeaderTableNumber = e32_ehdr->e_phnum;

	struct Elf32_Phdr e32_phdr 			= {0};
	struct Elf32_Dyn  e32_dyn 			= {0};

	Elf32_Off TableOffset 				= 0;
	Elf32_Word TableSize				= 0;

	int numberOfTable					= 0;
	int i 								= 0;

	char* tmpStrBuffer					= (char*) malloc(sizeof(char) * 150);
	memset(tmpStrBuffer, 0, sizeof(char) * 150);

	//////////////////////////////////////////////////////////////////////////////////

	for(int i=0; i<ProcessHeaderTableNumber; i++)
	{
		TableOffset = StartProcessHeaderTable + (i*ProcessHeaderTableSize);

		memcpy(&e32_phdr,
				pchBuffer + TableOffset,
				sizeof(struct Elf32_Phdr));

		if (strcmp(PROGRAM_TYPE[e32_phdr.p_type].c_str(), "DYNAMIC") == 0)
		{
			TableOffset 	= e32_phdr.p_offset;
			TableSize  		= e32_phdr.p_filesz;
			numberOfTable 	= TableSize / sizeof(struct Elf32_Dyn);
			//printf("%08x, %08x, %d\n", TableOffset, TableSize, numberOfTable);

			break;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////

	sprintf(pchDynBuffer,
			"Dynamic section at offset 0x%x contains %d entries:\n"
			"Type                       Name/Value\n", TableOffset, numberOfTable);
	do
	{
		memcpy(&e32_dyn_Node->e32_Dyn,
				pchBuffer + TableOffset,
				sizeof(struct Elf32_Dyn));

		//printf("%s, 0x%08x\n", DYNAMIC_TAG[e32_dyn_Node->e32_Dyn.d_tag].c_str(), e32_dyn_Node->e32_Dyn.d_un.d_ptr);


		if (strcmp(DYNAMIC_ENTRY[e32_dyn_Node->e32_Dyn.d_tag].c_str(), "ptr") == 0)
		{
			sprintf(tmpStrBuffer, "%-25s 0x%08x\n", DYNAMIC_TAG[e32_dyn_Node->e32_Dyn.d_tag].c_str(),
										e32_dyn_Node->e32_Dyn.d_un.d_ptr);
		}
		else
		{
			sprintf(tmpStrBuffer, "%-25s %d (bytes)\n", DYNAMIC_TAG[e32_dyn_Node->e32_Dyn.d_tag].c_str(),
										e32_dyn_Node->e32_Dyn.d_un.d_val);			
		}

		strcat(pchDynBuffer, tmpStrBuffer);
		

		e32_dyn_NextNode = (struct Elf32_Dyn_Linker*) malloc(sizeof(struct Elf32_Dyn_Linker));
		memset(e32_dyn_NextNode, 0, sizeof(struct Elf32_Dyn_Linker));

		e32_dyn_Node->nextPoint = e32_dyn_NextNode;
		e32_dyn_Node = e32_dyn_NextNode;

		TableOffset = TableOffset + (Elf32_Off) sizeof(struct Elf32_Dyn);

		i++;

	} while (i<numberOfTable);


/*	////////// Debug Code //////////
	e32_dyn_Node = e32_dyn_linker;

	while(e32_dyn_Node->nextPoint != NULL)
	{
		printf("%s, 0x%08x\n", DYNAMIC_TAG[e32_dyn_Node->e32_Dyn.d_tag].c_str(), e32_dyn_Node->e32_Dyn.d_un.d_ptr);
		e32_dyn_Node = e32_dyn_Node->nextPoint;
	}
*/
	//////////////////////////////////////////////////////////////////////////////////


	free(tmpStrBuffer);

	return 0;
}


char* GetSetionName(unsigned char*		pchBuffer,
				    struct Elf32_Ehdr*	e32_ehdr,
				    Elf32_Word  		SectionHeaderName)
{

	//////////////////////////////////////////////////////////////////////////////////

	Elf32_Off TableOffset 		= e32_ehdr->e_shoff + (e32_ehdr->e_shentsize * e32_ehdr->e_shstrndx);

	struct Elf32_Shdr e32_shdr 	= {0};

	memcpy(&e32_shdr,
			pchBuffer + TableOffset,
			sizeof(struct Elf32_Shdr));

	TableOffset = e32_shdr.sh_offset + SectionHeaderName;


	char* pchStrBuffer = (char*) malloc(sizeof(char) * STRING_SIZE);
	strcpy(pchStrBuffer, (char*)(pchBuffer + TableOffset));

	//////////////////////////////////////////////////////////////////////////////////

	return pchStrBuffer;

}

int ShrParser(unsigned char* 				pchBuffer,
			  struct Elf32_Ehdr* 			e32_ehdr,
			  struct Elf32_Section_Linker* 	e32_section_linker,
			  char* 						pchShrBuffer)
{

	//////////////////////////////////////////////////////////////////////////////////

	struct Elf32_Section_Linker* e32_section_Node 		= e32_section_linker;
	struct Elf32_Section_Linker* e32_section_NextNode   = NULL;


	Elf32_Off StartSetionHeaderTable 	= e32_ehdr->e_shoff;
	Elf32_Half SetionHeaderTableSize 	= e32_ehdr->e_shentsize;
	Elf32_Half SetionHeaderTableNumber 	= e32_ehdr->e_shnum;

	struct Elf32_Shdr e32_shdr 			= {0};

	char* 	tmpStrBuffer				= NULL;
	char*  	pchShrTmpBuffer 			= (char*) malloc(sizeof(char) * 150);
	memset(pchShrTmpBuffer, 0, sizeof(char) * 150);

	Elf32_Off TableOffset 				= 0;

	strcpy(pchShrBuffer,
			"Section Headers:\n"
			"[Nr] Name                   Type            Addr     Off    Size   Al\n");

	//////////////////////////////////////////////////////////////////////////////////

	for(int i=0; i<SetionHeaderTableNumber; i++)
	{
		TableOffset = StartSetionHeaderTable + (i*SetionHeaderTableSize);

		memcpy(&e32_shdr,
				pchBuffer + TableOffset,
				sizeof(struct Elf32_Shdr));

		tmpStrBuffer = GetSetionName(pchBuffer, e32_ehdr, e32_shdr.sh_name);

		sprintf(pchShrTmpBuffer,
			"[%2d] %-22s %-15s %08x %06x %06x %2d\n",

			i,
			tmpStrBuffer,
			SECTION_TYPE[e32_shdr.sh_type].c_str(),
			e32_shdr.sh_addr,
			e32_shdr.sh_offset,
			e32_shdr.sh_size,
			e32_shdr.sh_addralign
		);

		strcat(pchShrBuffer, pchShrTmpBuffer);
		free(tmpStrBuffer);
	}

	//////////////////////////////////////////////////////////////////////////////////

	for(int i=0; i<SetionHeaderTableNumber; i++)
	{
		TableOffset = StartSetionHeaderTable + (i*SetionHeaderTableSize);

		memcpy(&e32_section_Node->e32_shdr,
				pchBuffer + TableOffset,
				sizeof(struct Elf32_Shdr));

		e32_section_NextNode = (struct Elf32_Section_Linker*) malloc(sizeof(struct Elf32_Section_Linker));
		memset(e32_section_NextNode, 0, sizeof(struct Elf32_Section_Linker));

		e32_section_Node->nextPoint = e32_section_NextNode;
		e32_section_Node = e32_section_NextNode;

		TableOffset = TableOffset + (Elf32_Off) sizeof(struct Elf32_Shdr);

	}

/*
	////////// Debug Code //////////
	e32_section_Node 		= e32_section_linker;

	for(int i=0; i<SetionHeaderTableNumber; i++)
	{
		tmpStrBuffer = GetSetionName(pchBuffer, e32_ehdr, e32_section_Node->e32_shdr.sh_name);

		sprintf(pchShrTmpBuffer,
			"[%2d] %-22s %-15s %08x %06x %06x %2d\n",

			i,
			tmpStrBuffer,
			SECTION_TYPE[e32_section_Node->e32_shdr.sh_type].c_str(),
			e32_section_Node->e32_shdr.sh_addr,
			e32_section_Node->e32_shdr.sh_offset,
			e32_section_Node->e32_shdr.sh_size,
			e32_section_Node->e32_shdr.sh_addralign
		);

		e32_section_Node = e32_section_Node->nextPoint;

		strcat(pchShrBuffer, pchShrTmpBuffer);
		free(tmpStrBuffer);
	}
*/
	//////////////////////////////////////////////////////////////////////////////////

	free(pchShrTmpBuffer);

	//////////////////////////////////////////////////////////////////////////////////

	return 0;
}


int PhrParser(unsigned char* 		pchBuffer,
			  struct Elf32_Ehdr* 	e32_ehdr,
			  struct Elf32_Phdr* 	e32_phdr,
			  char* 				pchPhrBuffer)
{

	//////////////////////////////////////////////////////////////////////////////////

	Elf32_Off StartProcessHeaderTable 	= e32_ehdr->e_phoff;
	Elf32_Half ProcessHeaderTableSize 	= e32_ehdr->e_phentsize;
	Elf32_Half ProcessHeaderTableNumber = e32_ehdr->e_phnum;

	char*  pchPhrTmpBuffer 				= (char*) malloc(sizeof(char) * 150);
	memset(pchPhrTmpBuffer, 0, sizeof(char) * 150);

	Elf32_Off TableOffset 				= 0;

	strcpy(pchPhrBuffer,
			"Program Headers:\n"
			"Type\t\tOffset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align\n");

	//////////////////////////////////////////////////////////////////////////////////

	for(int i=0; i<ProcessHeaderTableNumber; i++)
	{
		TableOffset = StartProcessHeaderTable + (i*ProcessHeaderTableSize);

		memcpy(e32_phdr,
				pchBuffer + TableOffset,
				sizeof(struct Elf32_Phdr));

		sprintf(pchPhrTmpBuffer,
				"%-8s\t0x%06x 0x%08x 0x%08x 0x%05x 0x%05x %-3s 0x%x\n",

				PROGRAM_TYPE[e32_phdr->p_type].c_str(),
				e32_phdr->p_offset,
				e32_phdr->p_vaddr,
				e32_phdr->p_paddr,
				e32_phdr->p_filesz,
				e32_phdr->p_memsz,
				PROGRAM_FLAG[e32_phdr->p_flags].c_str(),
				e32_phdr->p_align
		);

		strcat(pchPhrBuffer, pchPhrTmpBuffer);
	}

	//////////////////////////////////////////////////////////////////////////////////

	free(pchPhrTmpBuffer);

	//////////////////////////////////////////////////////////////////////////////////

	return 0;
}


int EhrParser(unsigned char* 		pchBuffer,
			  struct Elf32_Ehdr* 	e32_ehdr,
			  char* 				pchEhrBuffer)
{

	//////////////////////////////////////////////////////////////////////////////////

	//memset(e32_ehdr, 0, 		sizeof(struct Elf32_Ehdr));
	memcpy(e32_ehdr, pchBuffer, sizeof(struct Elf32_Ehdr));

	sprintf(pchEhrBuffer, "Elf Header:\n"
						"  Magic:\t\t\t\t%02x %02x %02x %02x\n"
						"  Class:\t\t\t\t%s\n"
						"  OS/ABI:\t\t\t\t%s\n"
						"  Machine:\t\t\t\t%s\n"
						"  Type:\t\t\t\t\t%s\n"
						"  Entry point address:\t\t\t0x%02x\n"
						"  Start of program headers:\t\t%d (bytes into file)\n"
						"  Start of section headers:\t\t%d (bytes into file)\n"
						"  Size of this header:\t\t\t%d (bytes)\n"
						"  Size of program headers:\t\t%d (bytes)\n"
						"  Number of program headers:\t\t%d\n"
						"  Size of section headers:\t\t%d (bytes)\n"
						"  Number of section headers:\t\t%d\n"
						"  Section header string table index:\t%d\n",

			e32_ehdr->e_ident[EI_MAG0],
			e32_ehdr->e_ident[EI_MAG1],
			e32_ehdr->e_ident[EI_MAG2],
			e32_ehdr->e_ident[EI_MAG3],

			OBJECT_FILE_CLASS[e32_ehdr->e_ident[EI_CLASS]].c_str(),
			OS_ABI[e32_ehdr->e_ident[EI_OSABI]].c_str(),
			MACHINE_ARCHITECTURES[e32_ehdr->e_machine].c_str(),
			FILE_TYPE[e32_ehdr->e_type].c_str(),

			e32_ehdr->e_entry,
			e32_ehdr->e_phoff,
			e32_ehdr->e_shoff,
			e32_ehdr->e_ehsize,
			e32_ehdr->e_phentsize,
			e32_ehdr->e_phnum,
			e32_ehdr->e_shentsize,
			e32_ehdr->e_shnum,
			e32_ehdr->e_shstrndx
	);

	//////////////////////////////////////////////////////////////////////////////////

	return 0;
}
