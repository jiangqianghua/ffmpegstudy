#include<stdio.h>
#include<libavformat/avformat.h>
#include<libavutil/log.h>
#include <libavformat/avio.h>

// 抽取音频数据
// run
//clang -g -o extra_h264 extra_h264.c -lavutil -lavformat
// ./extra_audio input output
int main(int argc, char* argv[])
{

	int ret = 0 ;
	int video_stream_index ;
	int len ;
	char* src = NULL;
	char* dst = NULL;

	AVPacket pkt ;
	AVFormatContext *fmt_ctx = NULL;
	av_log_set_level(AV_LOG_INFO);
	av_register_all();

	//1 read two params from console
	if(argc < 3){
		av_log(NULL,AV_LOG_ERROR,"the count of params should be more than three!\n");
		return -1 ;
	}

	src = argv[1];
	dst = argv[2];

	if(!src || !dst){
		av_log(NULL,AV_LOG_ERROR,"src or dst is NULL\n");
		return -1 ;
	}
	// 打开目标文件
	FILE* dst_df = fopen(dst,"wb");
	if(!dst_df){
		av_log(NULL,AV_LOG_ERROR,"Can not open out file!\n");
		avformat_close_input(&fmt_ctx);
		return -1 ;
	}
	// 打开多媒体文件
	ret = avformat_open_input(&fmt_ctx , src,NULL,NULL);
	if(ret < 0){
		av_log(NULL,AV_LOG_ERROR,"can not open file: %s\n",av_err2str(ret));
		return -1 ;
	}
	//  打印多媒体信息
	av_dump_format(fmt_ctx,0,src , 0);

	// ret = avformat_find_stream_info(fmt_ctx,NULL);
	// if(ret < 0){
	// 	av_log(NULL,AV_LOG_ERROR,"can not find stream!\n");
	// 	avformat_close_input(&fmt_ctx);
	// 	fclose(dst_df);
	// 	return -1;
	// }

	av_init_packet(&pkt);
	pkt.data = NULL;
	pkt.size = 0 ;

	video_stream_index = av_find_best_stream(fmt_ctx,AVMEDIA_TYPE_VIDEO,-1,-1,NULL,0);

	if(video_stream_index < 0){
		av_log(NULL,AV_LOG_ERROR,"can not find video stream in input file %s\n",av_err2str(ret));
		return -1 ;
	}
	return 0 ;
}