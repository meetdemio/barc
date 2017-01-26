//
//  archive_stream.h
//  barc
//
//  Created by Charley Robinson on 1/26/17.
//  Copyright © 2017 TokBox, Inc. All rights reserved.
//

#ifndef archive_stream_h
#define archive_stream_h

#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

struct archive_stream_t {
    int64_t start_offset;
    int64_t duration;
    AVFormatContext* format_context;
    AVCodecContext* decode_context;
    int video_stream_index;
    int audio_stream_index;
    AVFrame* current_frame;
    char current_frame_valid;
};

int archive_stream_open(struct archive_stream_t* stream, const char* path);
int archive_stream_free(struct archive_stream_t* stream);

int archive_stream_peek_video_frame
(struct archive_stream_t* stream, AVFrame** frame, int64_t* offset_pts);

int archive_stream_pop_video_frame
(struct archive_stream_t* stream, AVFrame** frame, int64_t* offset_pts);


#endif /* archive_stream_h */
