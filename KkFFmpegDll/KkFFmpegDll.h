#pragma once

#include "mp4convert/FFMpegUtil.h"
#include "mp4convert/TransCode.hpp"
#include "mp4convert/VideoCoverImage.hpp"

#ifndef DLLEXPORT
#define DLLEXPORT extern "C" __declspec(dllexport)
#endif // !DLLEXPORT

class KKFFmpegDll {
public:
	bool registerFFmpeg();

	bool callTranscode(bool exit[1], const char* inputFilePath, const char* outputFilePath);

	bool callCoverImage(const char* input, const char* output,
		int width, int height);
};
