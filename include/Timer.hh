/*
**
** Made by MisterAlex
** And also Applelo (but a little)
**
*/

#ifndef TIMER_HH_
# define TIMER_HH_

# include "Utils.h"

class Timer {
private:
	uint64_t _time;
	bool _playing;

public:
	Timer();
	virtual ~Timer();

	const int getTime() const;
	const bool isPlaying() const;

	void startTimer();
	int resumeTimer();
	int pauseTimer();
	void resetTimer();
};

#endif /* !TIMER_HH_ */
