all:
	as src/boot.S -o boot.o
	gcc -DDEBUG -c src/main.c -o main.o -nostdlib -ffreestanding -lgcc
	ld -Tlinker.lds -o los.elf main.o boot.o
	cp los.elf iso/boot/
	rm -rf os.iso
	grub-mkrescue -o os.iso iso

write: all
	sudo dd if=os.iso of=/dev/sda

run: all
	qemu-system-x86_64 -boot d -cdrom os.iso -d cpu_reset -serial stdio -hda disk.img
