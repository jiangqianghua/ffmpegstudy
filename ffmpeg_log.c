#include<stdio.h>
#include<libavutil/log.h>
// run
// clang -g -o ffmpeg_log ffmpeg_log.c -lavutil
// 注意，需要把ffmpeg编译出的include 和lib放到／usr／local对应的目录下
int main(int argc, char* argv[])
{
	av_log_set_level(AV_LOG_DEBUG);
	av_log(NULL,AV_LOG_INFO,"hello ffpeg info! %s\n","test");
	return 0 ;
}