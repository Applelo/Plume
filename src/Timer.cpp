/*
 **
 ** Made by MisterAlex
 ** And also Applelo (but a little)
 **
 */

#include "../include/Timer.hh"

Timer::Timer()
{}

Timer::~Timer()
{}

// Getter
const int Timer::getTime() const {
	if (_playing)
		return ((sceKernelGetProcessTimeWide() / 1000) - _time);
	else
		return _time;
}
const bool Timer::isPlaying() const {
	return _playing;
}


// Setter
int Timer::resumeTimer() {
	if (!_playing) {
		_playing = true;
		return 0;
	}
	else
		return -1;
}

int Timer::pauseTimer() {
	if (_playing) {
		_playing = false;
		return 0;
	}
	else
		return -1;
}

void Timer::resetTimer() {
	_time = (sceKernelGetProcessTimeWide() / 1000);
	_playing = true;
}

void Timer::startTimer() {
	_time = (sceKernelGetProcessTimeWide() / 1000);
	_playing = true;
}
