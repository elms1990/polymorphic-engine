#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <SDL2/SDL.h>

using std::string;

namespace Polymorphic {
    typedef unsigned char byte;

    class File {
        public:
            File();
            virtual ~File();

            void Open(string path, string mode);
            void Close();
            int Read(byte *dst, int size);
            byte ReadByte();
            Sint64 Tell();
            Sint64 Seek(Sint64 offset, int whence);
            size_t Write(byte *buffer, int size);
            size_t WriteByte(byte b);

        private:
            SDL_RWops *mStream;
            bool mOpened;
            bool mClosed;
    };

}

#endif
