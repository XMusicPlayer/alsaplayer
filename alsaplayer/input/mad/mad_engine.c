/*
 * AlsaPlayer MAD plugin.
 *
 * Copyright (C) 2001 Andy Lo A Foe <andy@alsaplayer.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 *  $Id$
 */ 

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "input_plugin.h"
#include "mad.h"

#define BLOCK_SIZE 4096	/* We can use any block size we like */
#define MAX_NUM_SAMPLES 8192
#define STREAM_BUFFER_SIZE	16384

struct mad_local_data {
		int mad_fd;				
		char path[FILENAME_MAX+1];
		struct mad_synth  synth; 
	  struct mad_stream stream;
 	  struct mad_frame  frame;
		uint8_t stream_buffer[STREAM_BUFFER_SIZE];
		int mad_init;
		int bytes_in_buffer;
		ssize_t offset;
		int sample_rate;
};		


/* utility to scale and round samples to 16 bits */
	
static inline
signed int scale(mad_fixed_t sample)
{
				/* round */
				sample += (1L << (MAD_F_FRACBITS - 16));

				/* clip */
				if (sample >= MAD_F_ONE)
								sample = MAD_F_ONE - 1;
				else if (sample < -MAD_F_ONE)
								sample = -MAD_F_ONE;

				/* quantize */
			return sample >> (MAD_F_FRACBITS + 1 - 16);
}



static int mad_frame_seek(input_object *obj, int frame)
{
	struct mad_local_data *data;
	int64_t pos;
	
	if (!obj)
		return 0;
	data = (struct mad_local_data *)obj->local_data;
	
	return 0;
}

static int mad_frame_size(input_object *obj)
{
	if (!obj || !obj->frame_size) {
				printf("No frame size!!!!\n");
				return 0;
	}
	return obj->frame_size;
}


/* #define MAD_DEBUG */

static int mad_play_frame(input_object *obj, char *buf)
{
	int ret;
	int bytes_read;
	struct mad_local_data *data;
	
	if (!obj)
			return 0;
	data = (struct mad_local_data *)obj->local_data;
	if (!data)
			return 0;
	
	if (data->bytes_in_buffer < 3072) { /* Hmm, this sucks */
					if ((bytes_read = read(data->mad_fd, 
									data->stream_buffer + data->bytes_in_buffer, 
									STREAM_BUFFER_SIZE - data->bytes_in_buffer)) < 
													(STREAM_BUFFER_SIZE - data->bytes_in_buffer)) {
									printf("MAD debug: not enough data read (%d, %d)\n",
																	bytes_read, data->bytes_in_buffer);
					}
					if (bytes_read > 0)
									data->bytes_in_buffer += bytes_read;
	}				
	mad_stream_buffer (&data->stream, data->stream_buffer, data->bytes_in_buffer);
#ifdef MAD_DEBUG
	printf("MAD debug: going to decode frame\n");
#endif
	if (mad_frame_decode(&data->frame, &data->stream) == -1) {
					if (!MAD_RECOVERABLE(data->stream.error)) {
									printf("MAD result: %d\n", data->stream.error);
									mad_frame_mute(&data->frame);
									return 0;
					}	else {
							printf("MAD result: %d\n", data->stream.error);
					}		
	}
#ifdef MAD_DEBUG	
	printf("MAD debug: going to synth frame\n");
#endif	
	mad_synth_frame (&data->synth, &data->frame);
	{
					struct mad_pcm *pcm = &data->synth.pcm;
					mad_fixed_t const *left_ch, *right_ch;
					uint16_t	*output = (uint16_t *)buf;
					int nsamples = pcm->length;
					int nchannels = pcm->channels;
					int num_bytes = data->stream_buffer + 
									data->bytes_in_buffer - data->stream.next_frame;

					left_ch = pcm->samples[0];
					right_ch = pcm->samples[1];
#ifdef MAD_DEBUG					
					printf("MAD debug: going to write out sample data\n");	
#endif					
					while (nsamples--) {
									 *output++ = scale(*left_ch++);
									 if (nchannels == 2) 
													 *output++ = scale(*right_ch++);
					}
#ifdef MAD_DEBUG					
					printf("MAD debug: going to move data (%d -> %d)\n",
													data->bytes_in_buffer, num_bytes);
#endif					
					/* Move data, this is inefficient */
					data->bytes_in_buffer = num_bytes;
					memmove(data->stream_buffer, data->stream.next_frame,
													data->bytes_in_buffer);
	}
	
	return 1;
}


static unsigned long mad_frame_to_sec(input_object *obj, int frame)
{
	struct mad_local_data *data;
	int64_t l = 0;
	unsigned long sec = 0;

	if (!obj)
			return 0;
	data = (struct mad_local_data *)obj->local_data;
	return sec;
}


static int mad_nr_frames(input_object *obj)
{
		struct mad_local_data *data;
		int frames = 10000;		
		if (!obj)
				return 0;
		data = (struct mad_local_data *)obj->local_data;
		
		return frames;
}


int mad_stream_info(input_object *obj, stream_info *info)
{
	struct mad_local_data *data;	
	
	if (!obj || !info)
			return 0;
	data = (struct mad_local_data *)obj->local_data;

	strcpy(info->stream_type, "Please note: file info / seeking not done yet");				
	return 1;
}


static int mad_sample_rate(input_object *obj)
{
		struct mad_local_data *data;
		
		if (!obj)
				return 44100;
		data = (struct mad_local_data *)obj->local_data;
		if (data)	
			return data->sample_rate;
		return 44100;
}

static int mad_init() 
{
		return 1;
}		


static int mad_channels(input_object *obj)
{
		struct mad_local_data *data;

		if (!obj)
				return 2; /* Default to 2, this is flaky at best! */
		data = (struct mad_local_data *)obj->local_data;
		
		return obj->nr_channels;
}


static float mad_can_handle(const char *path)
{
	char *ext;      
	ext = strrchr(path, '.');

	if (!ext)
					return 0.0;
	ext++;
	if (!strcasecmp(ext, "mp3") ||
									!strcasecmp(ext, "mp2") ||
									strstr(path, "http://")) {
					return 0.9;
	} else {
					return 0.0;
	}
}


static ssize_t find_initial_frame(uint8_t *buf, int size)
{
	uint8_t *data = buf;			

	int pos = 0;
	ssize_t header_size = 0;
	while (pos < (size - 10)) {
					if ((data[pos] == 0x49 && data[pos+1] == 0x44 && data[pos+2] == 0x33)) {
									printf("-----------------------\nMAD debug: skipping ID3v2 header (%x %x %x)\n",
																	data[pos], data[pos+1], data[pos+2]);
									
									header_size = (data[pos + 6] << 21) + 
																(data[pos + 7] << 14) +
																(data[pos + 8] << 7) +
																data[pos + 9]; /* syncsafe integer */
									if (data[pos + 5] & 0x10) {
													printf("MAD debug: extended header found\n");
													header_size += 10; /* 10 byte extended header */
									}
									header_size += 10;
									printf("MAD debug: header size = %d (%x %x %x %x)\n", header_size,
																	data[pos + 6], data[pos + 7], data[pos + 8],
																	data[pos + 9]);
									return header_size;
					} else if (data[pos] == 'R' && data[pos+1] == 'I' &&
										 data[pos+2] == 'F' && data[pos+3] == 'F') {
									printf("-----------------------\nMAD debug: skipping RIFF header\n");
									pos+=4;
									while (pos < size) {
												if (data[pos] == 'd' && data[pos+1] == 'a' &&
														data[pos+2] == 't' && data[pos+3] == 'a') {
																pos += 8; /* skip 'data' and ignore size */
																return pos;
												} else
																pos++;
									}
									printf("MAD debug: invalid header\n");
									return -1;
					} else {
									pos++;
					}				
	}
	if (data[0] != 0xff) {
		printf("MAD debug: potential problem file, first 4 bytes =  %x %x %x %x\n",
			data[0], data[1], data[2], data[3]);
	}
	return 0;
}

static int mad_open(input_object *obj, char *path)
{
		struct mad_local_data *data;
		int bytes_read;
		
		if (!obj)
				return 0;
	
		obj->local_data = malloc(sizeof(struct mad_local_data));
		if (!obj->local_data) {
				printf("failed to allocate local data\n");		
				return 0;
		}
		data = (struct mad_local_data *)obj->local_data;
		memset(data, 0, sizeof(struct mad_local_data));
		
		if ((data->mad_fd = open(path, O_RDONLY)) < 0) {
					fprintf(stderr, "mad_open() failed\n");
					return 0;
		}
		if ((bytes_read = read(data->mad_fd,
					data->stream_buffer, STREAM_BUFFER_SIZE)) < 1024) {
				// Not enough data available
				fprintf(stderr, "mad_open() can't read enough initial data\n");
				close(data->mad_fd);
				return 0;
		}		
		mad_synth_init  (&data->synth);
		mad_stream_init (&data->stream);
		mad_frame_init  (&data->frame);
		data->mad_init = 1;
		data->offset = find_initial_frame(data->stream_buffer, bytes_read);

		if (data->offset < 0) {
						fprintf(stderr, "mad_open() couldn't find valid MPEG header\n");
						close(data->mad_fd);
						return 0;
		} else {
						memmove(data->stream_buffer, data->stream_buffer + data->offset, 
														bytes_read - data->offset);
						data->bytes_in_buffer -= data->offset;
		}				
		
		mad_stream_buffer(&data->stream, data->stream_buffer, bytes_read);
				
		if ((mad_frame_decode(&data->frame, &data->stream) != 0)) {
					int num_bytes;	
					if (data->stream.next_frame) {
						num_bytes = data->stream_buffer + bytes_read - data->stream.next_frame;
						printf("MAD debug: num_bytes = %d\n", num_bytes);
						memmove(data->stream_buffer, data->stream.next_frame, num_bytes);
					}
					
					switch (data->stream.error) {
										case	MAD_ERROR_BUFLEN:
														printf("MAD_ERROR_BUFLEN...\n");
														close(data->mad_fd);
														break;
										default:
														printf("MAD debug: no valid frame found at start\n");
					}
					close(data->mad_fd);
					return 0;
		} else {
					int mode = (data->frame.header.mode == MAD_MODE_SINGLE_CHANNEL) ?
									1 : 2;
					data->sample_rate = data->frame.header.samplerate;
					
					mad_synth_frame (&data->synth, &data->frame);
					
					{
						struct mad_pcm *pcm = &data->synth.pcm;			
						
						obj->nr_channels = pcm->channels;
						obj->frame_size = 4608;
						printf("MAD debug: %d HZ, %d channel mp3. Lets play it!\n", 
														data->sample_rate, obj->nr_channels);
					}
		}

		/* Reset decoder */
		data->mad_init = 0;
		mad_synth_finish (&data->synth);
		mad_frame_finish (&data->frame);
		mad_stream_finish(&data->stream);
		
		lseek(data->mad_fd, data->offset, SEEK_SET);
		
		mad_synth_init  (&data->synth);
		mad_stream_init (&data->stream);
		mad_frame_init  (&data->frame);
		data->mad_init = 1;
		
		data->bytes_in_buffer = 0;	
		return 1;
}
		
static void mad_close(input_object *obj)
{
	struct mad_local_data *data;
	
	if (!obj)
			return;
	data = (struct mad_local_data *)obj->local_data;

	if (data) {
					if (data->mad_fd)
									close(data->mad_fd);
					if (data->mad_init) {
						mad_synth_finish (&data->synth);
						mad_frame_finish (&data->frame);
						mad_stream_finish(&data->stream);
					}	
					free(obj->local_data);
					obj->local_data = NULL;
	}				
}


input_plugin mad_plugin =
{
	INPUT_PLUGIN_VERSION,
	0,
	{ "MAD MPEG audio plugin v0.91" },
	{ "Andy Lo A Foe" },
	NULL,
	mad_init,
	NULL,
	NULL,
	mad_can_handle,
	mad_open,
	mad_close,
	mad_play_frame,
	mad_frame_seek,
	mad_frame_size,
	mad_nr_frames,
	mad_frame_to_sec,
	mad_sample_rate,
	mad_channels,
	mad_stream_info,
	NULL,
	NULL
};

input_plugin *input_plugin_info (void)
{
	return &mad_plugin;
}
