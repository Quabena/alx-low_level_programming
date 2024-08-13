#include "main.h"

/**
 * verify_elf_header - Verifies if the file is an ELF file.
 * @e_ident: Pointer to the array containing ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exits with code 98.
 */
void verify_elf_header(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * show_magic_numbers - Displays the ELF magic numbers.
 * @e_ident: Pointer to the array containing ELF magic numbers.
 */
void show_magic_numbers(unsigned char *e_ident)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * show_class_type - Displays the ELF class type.
 * @e_ident: Pointer to the array containing the ELF class.
 */
void show_class_type(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * show_data_encoding - Displays the data encoding of the ELF header.
 * @e_ident: Pointer to the array containing the ELF data encoding.
 */
void show_data_encoding(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * show_version_info - Displays the version of the ELF header.
 * @e_ident: Pointer to the array containing the ELF version.
 */
void show_version_info(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * show_osabi_info - Displays the OS/ABI information of the ELF header.
 * @e_ident: Pointer to the array containing the ELF OS/ABI info.
 */
void show_osabi_info(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * show_abi_version - Displays the ABI version of the ELF header.
 * @e_ident: Pointer to the array containing the ELF ABI version.
 */
void show_abi_version(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * show_file_type - Displays the type of the ELF file.
 * @e_type: The type of the ELF file.
 * @e_ident: Pointer to the array containing the ELF class.
 */
void show_file_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * show_entry_point - Displays the entry point address of the ELF file.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: Pointer to the array containing the ELF class.
 */
void show_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_file_descriptor - Closes an ELF file descriptor.
 * @fd: The file descriptor to be closed.
 *
 * Description: Exits with code 98 if the file descriptor cannot be closed.
 */
void close_file_descriptor(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * main - Displays the ELF header information from a specified file.
 * @argc: The number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 98 if the file is not an ELF file or if an error occurs.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, bytes_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(97);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_file_descriptor(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	bytes_read = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(header);
		close_file_descriptor(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	verify_elf_header(header->e_ident);
	printf("ELF Header:\n");
	show_magic_numbers(header->e_ident);
	show_class_type(header->e_ident);
	show_data_encoding(header->e_ident);
	show_version_info(header->e_ident);
	show_osabi_info(header->e_ident);
	show_abi_version(header->e_ident);
	show_file_type(header->e_type, header->e_ident);
	show_entry_point(header->e_entry, header->e_ident);

	free(header);
	close_file_descriptor(fd);
	return (0);
}
