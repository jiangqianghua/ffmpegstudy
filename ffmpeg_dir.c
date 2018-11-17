#include<stdio.h>
#include<libavformat/avformat.h>
#include<libavutil/log.h>
// 文件操纵
// run
//clang -g -o ffmpeg_dir ffmpeg_dir.c -lavutil -lavformat
int main(int argc , char* argv[])
{
	av_log_set_level(AV_LOG_DEBUG);

	AVIODirContext *ctx = NULL;
	AVIODirEntry *entry = NULL;
	int ret ;
	ret = avio_open_dir(&ctx,"./",NULL);
	if(ret < 0){
		av_log(NULL,AV_LOG_ERROR,"Cant open dir :s\n",av_err2str(ret));
		goto __fail;
	}

	while(1){
		ret = avio_read_dir(ctx,&entry);
		if(ret < 0){
			av_log(NULL,AV_LOG_ERROR,"Cant red dir :s\n",av_err2str(ret));
			goto __fail;
		}
		if(!entry){
			//读到文件末尾
			break;
		}

		av_log(NULL,AV_LOG_INFO,"%12"PRId64" %s \n",
			entry->size,
			entry->name);
		avio_free_directory_entry(&entry);
	}
__fail:
	avio_close_dir(&ctx);
	return 0 ;
}