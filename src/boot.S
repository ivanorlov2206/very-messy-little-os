.set MAGIC, 0xE85250D6
.set FLAGS, 3
.set CHECKSUM, -(MAGIC + 36)

.extern _stack_end
.extern _bootstrap_pages
.extern kernel_main

.section .multiboot.data, "aw"
.align 8
.long MAGIC
.long 0
.long 36
.long CHECKSUM

.align 8
.short 5
.short 0
.long 20
.long 0
.long 0
.long 0

.section .multiboot.text, "aw"
.global _start
.type _start, @function
.code32

_start:
	mov %ebx, boot_info
	lea _bootstrap_pages, %edi
	mov $4096, %ecx
	xor %eax, %eax
	cli
	rep stosl
	lea _bootstrap_pages, %edi

	mov $0x3, %ecx

	xor %eax, %eax

fill_table_layers:
	mov %edi, %eax
	add $0x1003, %eax
	mov %eax, (%edi)
	add $0x1000, %edi
	loop fill_table_layers

	mov $512, %ecx
	mov $0x3, %ebx
map_first_2M:
	movl %ebx, (%edi)
	add $0x1000, %ebx
	add $0x08, %edi
	loop map_first_2M

	lidt idt
	lgdt gdt_struct

	lea _bootstrap_pages, %eax
	mov %eax, %cr3

	mov $0x20, %eax
	or $0x80, %eax
	mov %eax, %cr4

	mov $0xC0000080, %ecx
	rdmsr
	
	or $0x100, %eax
	wrmsr

	mov %cr0, %ebx
	or $0x80000001, %ebx
	mov %ebx, %cr0

	jmp $0x08,$in_long_mode

idt:
	.short 0
	.word 0
gdt_segs:
	.quad 0
	.quad 0x00209A0000000000
	.quad 0x0000920000000000
.align 4
gdt_struct:
.short . - gdt_segs - 1
.quad gdt_segs

.code64
in_long_mode:
lea _stack_end, %rsp
lea _stack_end, %rbp
call kernel_main
hlt

.data
.global boot_info
boot_info:
.quad 0
