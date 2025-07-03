
; kelvar unREAL engine	version 0.2.3
; Copyright (c) 2000-2001, Tomasz Grysztar.
; All rights reserved.

	format	MZ
	heap	0
	entry	main:start
	stack	main_data:stack_frame

	include 'system\unreal.inc'

segment main

  start:
	use16				; entry point in real mode
	call	unreal:init		; now switch to 32-bit unreal mode
	use32				; 32-bit code!

	mov	ax,main_data
	mov	ds,ax
	mov	es,ax

	call	init_console		; initialize text console
	call	init_memory		; initialize extended memory
	call	init_clock		; initialize clock interrupt
	call	init_keyboard		; initialize keyboard interrupt
	call	init_sound		; initialize sound card

	call	startup_messages	; display startup messages
	call	close_console		; close text console

	mov	ax,20			; 20 times per second
	call	set_clock_frequency

	mov	esi,font_file
	call	load_font
	jc	out_of_memory
	mov	[simple_font],ebp

	mov	ax,101h 		; 640x480x256
	call	set_VESA_mode
	jc	video_error

	mov	esi,world_file
	call	init_world

	mov	ebx,[images]
	mov	esi,[ebx+image.file]
	add	esi,[world]
	call	load_palette
	call	set_palette

	mov	esi,music_file
	call	load_sample
	mov	[music_data],eax
	mov	[music_length],ecx

	call	play

  exit_program:

	push	main_data
	pop	ds
	call	return_console
	call	end_sound
	call	free_memory
	call	reset_clock
	call	reset_keyboard

	mov	ax,4C00h		; ...and exit
	int	21h

  include 'system\console.inc'
  include 'system\memory.inc'
  include 'system\video.inc'
  include 'system\irq.inc'
  include 'system\clock.inc'
  include 'system\keyboard.inc'
  include 'system\mouse.inc'
  include 'system\sound.inc'

  include 'engine\gif87a.inc'
  include 'engine\riffwave.inc'
  include 'engine\kelvar.inc'
  include 'engine\loader.inc'
  include 'engine\text.inc'

  include 'play.inc'
  include 'objects.inc'
  include 'texts.inc'

segment main_data

  world_file db 'data\world.dat',0
  font_file db 'data\mazovia.gif',0
  music_file db 'data\belong.wav',0

  move_keys db 50h,51h,4Dh,49h,48h,47h,4Bh,4Fh

  sound_card db 0			; sound card type
  null dd 0				; zero value

  console_status db ?			; status of text console
  console_cursor dw ?			; cursor position on console screen

  memory_start dd ?			; start of extended memory block
  memory_end dd ?			; end of extended memory block
  memory_current dd ?			; start of free extended memory
  memory_current_end dd ?		; end of free extended memory
  memory_method db ?			; method of memory allocation

  dos_memory_start dd ? 		; start of conventional memory block
  dos_memory_end dd ?			; end of conventional memory block
  dos_memory_current dd ?		; start of free conventional memory

  clock dd ?				; number of clock ticks
  keyboard rb 80h			; status of all keys
  file_path rb 80h			; buffer for file path
  mouse_x dd ?				; mouse horizontal position
  mouse_y dd ?				; mouse vertical position

  video_pitch dd ?			; bytes per line in video memory
  video_width dd ?			; width of video screen
  video_height dd ?			; height of video screen
  video_granularity dw ?		; granularity of video memory
  video_window dw ?			; number of video memory window
  video_window_select dd ?		; window positioning function
  video_linear dd ?			; address of video linear memory
  mode_info rb 256			; VESA video mode information

  source_pitch dd ?			; source picture bytes per line
  destination_pitch dd ?		; destination screen bytes per line
  destination_width dd ?		; destination screen width
  destination_height dd ?		; destination screen height
  current_x dd ?			; horizontal position storage
  current_y dd ?			; vertical position storage
  window_x dd ? 			; horizontal window position
  window_y dd ? 			; vertical window position

  sound_buffer dd ?			; base address of sound buffer
  sound_offset dd ?			; offset in sound buffer
  sound_frequency dd ?			; sound player frequency
  sample_data dd ?			; address of sample to play
  sample_length dd ?			; length of sample to play
  SB_port dw ?				; Sound Blaster base port
  SB_IRQ db ?				; Sound Blaster IRQ
  SB_DMA db ?				; Sound Blaster DMA channel

  picture dd ?				; address of loaded picture
  picture_width dd ?			; width of loaded picture
  picture_height dd ?			; height of loaded picture
  palette rb 768			; palette data

  LZW_bits db ? 			; LZW decompressor bits counter
  LZW_table rd 0F00h*2			; LZW decompressor table

  simple_font dd ?			; default font for text displaying
  world dd ?				; world definition
  images dd ?				; list of images
  images_data dd ?			; start of memory for images data
  place_memory dd ?			; end of memory for current place
  place_zones dd ?			; pointer to list of zones

  direction db ?			; current direction of player move
  rotation db ? 			; last direction of player rotation

  music_length dd ?			; number of music samples
  music_data dd ?			; address of music data

  stack_data rb 1000h			; stack data
  stack_frame = $

segment interrupts

  rb 100h*4				; buffer for interrupt vectors

segment console_screen

  rb 4000h				; buffer for console screen

segment buffer

  rb 30000h				; buffer for disk operations

segment main_plane

  rb plane.size 			; main game plane
  rb 1000h				; buffer for main plane objects

segment control_plane

  rb plane.size 			; control bar plane
  rb 1000h				; buffer for control plane objects
