/*
 *  File: log.h
 *  Last Updated: 13/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __LOG_H__
#define __LOG_H__

#include <fstream>
#include <string>
using std::fstream;
using std::string;

namespace Polymorphic {

    class Log {

        public:
            /* @name: LogMessage
             * @desc: Stores a message into the log file.
             * @param01: Type of the log message.
             * @param02: Message to be logged.
             */
            void LogMessage(string title, string msg);

            /* @name: Initialize
             * @descp: Initializes the log system using a
             * specific file.
             * @return: True, if successfuly initialized. False, otherwise.
             */
            bool Initialize(string file_name);

            /* @name: Shutdown
             * @descp: Release resources acquired from the log system.
             */
            void Shutdown();

            /* @name: Initialized
             * @return: Returns true if the log system is initialized. False, otherwise.
             */
            bool Initialized();

        private:
            bool initialized;
            fstream logf;
    };

}
#endif /* __LOG_H__ */
