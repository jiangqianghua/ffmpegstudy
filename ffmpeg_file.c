#include<stdio.h>
#include<libavformat/avformat.h>
#include<libavutil/log.h>
// 文件操纵
// run
//clang -g -o ffmpeg_del ffmpeg_file.c -lavutil -lavformat
int main(int argc , char* argv[])
{
	av_log_set_level(AV_LOG_DEBUG);
	int ret ; 
	//更改名字
	ret = avpriv_io_move("111.txt","mytestfile.txt");
	if(ret < 0){
		av_log(NULL,AV_LOG_ERROR,"Failed to move file 111.txt");
		return -1;
	}
	// 删除文件
	ret = avpriv_io_delete("./mytestfile.txt");
	if(ret < 0){
		av_log(NULL,AV_LOG_ERROR,"Failed to delete file mytestfile.txt\n");
		return -1 ;
	}

	return 0 ;
}