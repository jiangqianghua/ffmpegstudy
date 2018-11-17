#include<stdio.h>
#include<libavformat/avformat.h>
#include<libavutil/log.h>
// 打印文件meta信息
// run
//clang -g -o metainfo metainfo.c -lavutil -lavformat
int main(int argc, char* argv[])
{

	AVFormatContext *fmt_ctx = NULL;
	av_log_set_level(AV_LOG_INFO);
	
	av_register_all();

	int ret = 0 ;
	ret = avformat_open_input(&fmt_ctx , "./input.mp4",NULL,NULL);
	if(ret < 0){
		av_log(NULL,AV_LOG_ERROR,"can not open file: %s\n",av_err2str(ret));
		return -1 ;
	}
	av_dump_format(fmt_ctx,0,"./input.mp4" , 0);

	avformat_close_input(&fmt_ctx);
	return 0 ;
}