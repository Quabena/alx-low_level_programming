#include "main.h"

/**
 * validate_elf - Validates if the file is an ELF file
 * @identifier: A pointer to an array containing the ELF magic numbers
 */
void validate_elf(unsigned char *identifier)
{
	if (identifier[0] != 0x7f || identifier[1] != 'E' ||
	    identifier[2] != 'L' || identifier[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic_bytes - Prints the magic bytes of the ELF header
 * @identifier: A pointer to an array containing the ELF magic numbers
 */
void print_magic_bytes(unsigned char *identifier)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", identifier[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class_type - Prints the class type of the ELF file (32-bit or 64-bit)
 * @identifier: A pointer to an array containing the ELF class type
 */
void print_class_type(unsigned char *identifier)
{
	printf("  Class:                             ");
	switch (identifier[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", identifier[EI_CLASS]);
	}
}

/**
 * print_data_encoding - Prints the data encoding of the ELF file (little or big endian)
 * @identifier: A pointer to an array containing the ELF data encoding
 */
void print_data_encoding(unsigned char *identifier)
{
	printf("  Data:                              ");
	switch (identifier[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", identifier[EI_DATA]);
	}
}

/**
 * print_version_info - Prints the version of the ELF file
 * @identifier: A pointer to an array containing the ELF version
 */
void print_version_info(unsigned char *identifier)
{
	printf("  Version:                           %d",
	       identifier[EI_VERSION]);

	switch (identifier[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * print_osabi_info - Prints the OS/ABI of the ELF file
 * @identifier: A pointer to an array containing the ELF OS/ABI info
 */
void print_osabi_info(unsigned char *identifier)
{
	printf("  OS/ABI:                            ");
	switch (identifier[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", identifier[EI_OSABI]);
	}
}

/**
 * print_abi_version - Prints the ABI version of the ELF file
 * @identifier: A pointer to an array containing the ELF ABI version
 */
void print_abi_version(unsigned char *identifier)
{
	printf("  ABI Version:                       %d\n",
	       identifier[EI_ABIVERSION]);
}

/**
 * print_file_type - Prints the type of the ELF file (executable, relocatable, etc.)
 * @file_type: The ELF file type
 */
void print_file_type(uint16_t file_type)
{
	printf("  Type:                              ");
	switch (file_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", file_type);
	}
}

/**
 * print_entry_address - Prints the entry point address of the ELF file
 * @entry_address: The entry point address of the ELF file
 * @identifier: A pointer to an array containing the ELF class type
 */
void print_entry_address(uint64_t entry_address, unsigned char *identifier)
{
	printf("  Entry point address:               ");
	if (identifier[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry_address);
	else
		printf("%#lx\n", entry_address);
}

/**
 * close_elf_file - Closes the ELF file descriptor
 * @elf_file_descriptor: The file descriptor of the ELF file
 */
void close_elf_file(int elf_file_descriptor)
{
	if (close(elf_file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
			elf_file_descriptor);
		exit(98);
	}
}

/**
 * main - Entry point for the program
 * @argc: The number of arguments
 * @argv: The arguments vector
 *
 * Return: 0 on success, otherwise 98 on failure
 */
int main(int argc, char *argv[])
{
	int elf_file_descriptor;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	elf_file_descriptor = open(argv[1], O_RDONLY);
	if (elf_file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	bytes_read = read(elf_file_descriptor, &header, sizeof(header));
	if (bytes_read == -1 || (size_t)bytes_read < sizeof(Elf64_Ehdr))
	{
		close_elf_file(elf_file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read ELF header from file %s\n", argv[1]);
		exit(98);
	}

	validate_elf(header.e_ident);
	printf("ELF Header:\n");
	print_magic_bytes(header.e_ident);
	print_class_type(header.e_ident);
	print_data_encoding(header.e_ident);
	print_version_info(header.e_ident);
	print_osabi_info(header.e_ident);
	print_abi_version(header.e_ident);
	print_file_type(header.e_type);
	print_entry_address(header.e_entry, header.e_ident);

	close_elf_file(elf_file_descriptor);
	return (0);
}
