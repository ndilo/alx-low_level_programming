#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* ELF header structure */
typedef struct {
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf64_Ehdr;

/* Function to display ELF header information */
void display_elf_header(const Elf64_Ehdr *header)
{
	/* Displaying the ELF header information */
	printf("Magic: ");
	for (int i = 0; i < 16; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class: %d-bit\n", header->e_ident[4] == 1 ? 32 : 64);

	printf("Data: ");
	switch (header->e_ident[5]) {
	case 1:
		printf("2's complement, little endian\n");
		break;
	case 2:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
		return;
	}

	printf("Version: %d\n", header->e_ident[6]);

	printf("OS/ABI: ");
	switch (header->e_ident[7]) {
	case 0:
		printf("System V\n");
		break;
	case 1:
		printf("HP-UX\n");
		break;
	case 2:
		printf("NetBSD\n");
		break;
	case 3:
		printf("Linux\n");
		break;
	case 6:
		printf("Solaris\n");
		break;
	case 7:
		printf("AIX\n");
		break;
	case 8:
		printf("IRIX\n");
		break;
	case 9:
		printf("FreeBSD\n");
		break;
	case 10:
		printf("Tru64\n");
		break;
	case 11:
		printf("Novell Modesto\n");
		break;
	case 12:
		printf("OpenBSD\n");
		break;
	case 13:
		printf("OpenVMS\n");
		break;
	case 14:
		printf("NonStop Kernel\n");
		break;
	case 15:
		printf("AROS\n");
		break;
	case 16:
		printf("Fenix OS\n");
		break;
	case 17:
		printf("CloudABI\n");
		break;
	case 18:
		printf("OpenVOS\n");
		break;
	default:
		printf("Unknown OS/ABI\n");
		return;
	}

	printf("ABI Version: %d\n", header->e_ident[8]);

	printf("Type: ");
	switch (header->e_type) {
	case 0:
		printf("No file type\n");
		break;
	case 1:
		printf("Relocatable file\n");
		break;
	case 2:
		printf("Executable file\n");
		break;
	case 3:
		printf("Shared object file\n");
		break;
	case 4:
		printf("Core file\n");
		break;
	default:
		printf("Unknown file type\n");
		return;
	}

	printf("Entry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 1;
	}

	/* Open the ELF file */
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		return 98;
	}

	/* Read the ELF header */
	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header)) {
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		return 98;
	}

	/* Check if the file is an ELF file */
	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
	    header.e_ident[2] != 'L' || header.e_ident[3] != 'F') {
		fprintf(stderr, "Not an ELF file: %s\n", argv[1]);
		close(fd);
		return 98;
	}

	/* Display the ELF header information */
	display_elf_header(&header);

	/* Close the file */
	close(fd);

	return 0;
}
