#include "flash.h"

static int flash_serial_fd = -1;

int flash_open(const char *path, unsigned long baudrate)
{
	flash_serial_fd = serial_open(path, baudrate);

	if (flash_serial_fd < 0)
		return -1;

	return 0;
}

int flash_write(const char *romfile, void (*log)(const char *))
{
	int romfd;
	ssize_t written;

	struct stat romst;
	struct flash_blk head;

	uint8_t *buffer = malloc(FLASH_BLOCK_SIZE);

	romfd = open(romfile, O_RDONLY);

	if (fstat(romfd, &romst) != 0)
		goto exit_romfd;

	while ((head.size = read(romfd, buffer, FLASH_BLOCK_SIZE))) {
        if (head.size < 0) {
            log("[!] Error while reading from file\n");
            break;
        }

		head.addr = (uint16_t) lseek(romfd, 0, SEEK_CUR);

		written = write(flash_serial_fd, &head, sizeof(struct flash_blk));
		if (written != sizeof(struct flash_blk)) {
            log("[!] Some bytes of flash_blk haven't been written\n");
		}

		written = write(flash_serial_fd, buffer, head.size);		
		if (written != head.size) {
            log("[#] Some bytes might not have been written\n");
		}

        char logbuf[64];
		sprintf(logbuf, "[@] Written %d bytes at address %d\n", head.size, head.addr);
		log(logbuf);
	}

exit_romfd:
	close(romfd);

	free(buffer);
	return 0;
}

void flash_close(void)
{
	if (flash_serial_fd >= 0) 
		close(flash_serial_fd);
}