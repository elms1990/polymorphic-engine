/*
 *  File: timer.h
 *  Last Updated: 14/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __TIMER_H__
#define __TIMER_H__

namespace Polymorphic {

    class Timer {

        public:
            Timer();
            ~Timer() {};
            void Start();
            void Stop();
            void Pause();
            void Unpause();

            unsigned int GetTicks();
            bool IsStarted() { return started; }
            bool IsPaused() { return paused; }

        private:

            unsigned int startTicks;
            unsigned int pauseTicks;

            bool paused;
            bool started;
    };

}
#endif /* __TIMER_H__ */
