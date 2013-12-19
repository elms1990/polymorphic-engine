#include "file.h"

using Polymorphic::File;
using Polymorphic::byte;

File::File() {
    mOpened = false;
    mClosed = false;
}

File::~File() {

}

void File::Open(string path, string mode) {
    mStream = SDL_RWFromFile(path.c_str(), mode.c_str());

    if (mStream != NULL) {
        mOpened = true;
        mClosed = false;
    } else {
        mOpened = false;
        mClosed = false;
    }
}

void File::Close() {
    if (mOpened && !mClosed) {
        SDL_RWclose(mStream);
    }
    mOpened = false;
    mClosed = false;
}

int File::Read(byte *dst, int size) {
    return SDL_RWread(mStream, dst, sizeof(byte), size);
}

byte File::ReadByte() {
    byte b[1];
    Read(b, 1);

    return b[0];
}

Sint64 File::Tell() {
    return SDL_RWtell(mStream);
}

Sint64 File::Seek(Sint64 offset, int whence) {
    return SDL_RWseek(mStream, offset, whence);
}

size_t File::Write(byte *buffer, int size) {
    return SDL_RWwrite(mStream, buffer, sizeof(byte), size);
}

size_t File::WriteByte(byte b) {
    return Write(&b, 1);
}
