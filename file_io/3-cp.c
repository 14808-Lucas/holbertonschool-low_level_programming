#include "main.h"

#define BUFFER_SIZE 1024

/**
 * close_fd - closes a file descriptor, exiting with code 100 on error
 * @fd: the file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_source - opens file_from for reading
 * @file_from: name of the file to open
 *
 * Return: the file descriptor on success
 */
int open_source(char *file_from)
{
	int fd;

	fd = open(file_from, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - opens (creating/truncating if needed) file_to for writing
 * @file_to: name of the file to open
 *
 * Return: the file descriptor on success
 */
int open_dest(char *file_to)
{
	int fd;

	fd = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - copies the content of fd_from into fd_to
 * @fd_from: file descriptor to read from
 * @fd_to: file descriptor to write to
 * @file_from: name of the source file (for error messages)
 * @file_to: name of the destination file (for error messages)
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(argv[1]);
	fd_to = open_dest(argv[2]);

	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
