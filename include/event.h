/*
 *  File: event.h
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

using std::string;

namespace Polymorphic {
    class GameObject;
    
    class Event {
        public:
            Event();
            
            string Message;
            GameObject *Sender;
            GameObject *Receiver;

            union {
                char charValue;
                short shortValue;
                void *ptrValue;
                long longValue;
                double doubleValue;
                float floatValue;
                int intValue;
            } Data;
    };

}

#endif /* __EVENT_H__ */
