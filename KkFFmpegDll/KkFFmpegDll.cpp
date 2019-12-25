#include "KkFFmpegDll.h"

DLLEXPORT bool registerFFmpeg() {
	try {
		FFMpegUtil::Register();
	} catch (exception e) {
		return false;
	}
	return true;
}

 DLLEXPORT bool callTranscode(bool exit[1],
	const char* inputFilePath, const char* outputFilePath) {
	TransCode transCode(exit[0]);
	transCode.Initial(inputFilePath, outputFilePath);
	int ret = transCode.TranscodeStep();
	if (ret < 0) {
		return false;
	}
	return true;
}

DLLEXPORT bool callCoverImage(const char* input, const char* output,
	int width, int height) {
	VideoCoverImage hikVideoCoverImage(input, output, width, height);
	int ret = hikVideoCoverImage.CoverImageStep();
	if (ret < 0) {
		return false;
	}
	return true;
}