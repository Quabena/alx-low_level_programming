#include "main.h"

/**
 * verify_elf_signature - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void verify_elf_signature(unsigned char *e_ident)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (e_ident[i] != 127 && e_ident[i] != 'E' &&
            e_ident[i] != 'L' && e_ident[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * display_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void display_magic(unsigned char *e_ident)
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
 * display_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_class(unsigned char *e_ident)
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
 * display_data_encoding - Prints the data encoding of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_data_encoding(unsigned char *e_ident)
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
 * display_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * display_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void display_osabi(unsigned char *e_ident)
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
 * display_abi_version - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void display_abi_version(unsigned char *e_ident)
{
    printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * display_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_type(unsigned int e_type, unsigned char *e_ident)
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
        printf("<unknown: %```c
x>\n", e_type);
    }
}

/**
 * display_entry_point - Prints the entry point address of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_entry_point(unsigned long int e_entry, unsigned char *e_ident)
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
 * close_elf_file - Closes an ELF file descriptor.
 * @elf_fd: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf_file(int elf_fd)
{
    if (close(elf_fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf_fd);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or exit code 98 on failure.
 */
int main(int argc, char *argv[])
{
    Elf64_Ehdr *header;
    int elf_fd;
    ssize_t bytes_read;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    elf_fd = open(argv[1], O_RDONLY);
    if (elf_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_elf_file(elf_fd);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    bytes_read = read(elf_fd, header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1 || bytes_read < (ssize_t)sizeof(Elf64_Ehdr))
    {
        free(header);
        close_elf_file(elf_fd);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    verify_elf_signature(header->e_ident);
    printf("ELF Header:\n");
    display_magic(header->e_ident);
    display_class(header->e_ident);
    display_data_encoding(header->e_ident);
    display_version(header->e_ident);
    display_osabi(header->e_ident);
    display_abi_version(header->e_ident);
    display_type(header->e_type, header->e_ident);
    display_entry_point(header->e_entry, header->e_ident);

    free(header);
    close_elf_file(elf_fd);
    return (0);
}
