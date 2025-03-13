PROG        ?= firmware
ARCH        ?= esp32
CFLAGS      ?= -W -Wall -Wextra -Werror -Wundef -Wshadow -pedantic \
               -Wdouble-promotion -fno-common -Wconversion \
               -mlongcalls -mtext-section-literals \
               -Os -ffunction-sections -fdata-sections \
               -I.
LINKFLAGS   ?= -T sdk/ld/link.ld -nostdlib -nostartfiles -Wl,--gc-sections
TOOLCHAIN   ?= xtensa-esp32-elf
SRCS        ?= main.c sdk/*.c

build: $(PROG).bin

$(PROG).elf: $(SRCS)
	mkdir -p build
	source ~/esp/esp-idf/export.sh
	$(TOOLCHAIN)-gcc  $(CFLAGS) $(SRCS) $(LINKFLAGS) -o build/$@

$(PROG).bin: $(PROG).elf

flash: $(PROG).bin
	esptool.py --chip esp32 elf2image --flash_mode="dio" --flash_freq "40m" --flash_size "4MB" -o build/$(PROG).bin build/$(PROG).elf
	esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x1000 build/$(PROG).bin

erase:
	esptool.py --chip esp32 erase_flash

clean:
	@rm -rf build/ $(PROG)*
