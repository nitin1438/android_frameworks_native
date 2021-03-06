#ifndef ANDROID_DVR_INTERNAL_H_
#define ANDROID_DVR_INTERNAL_H_

#include <sys/cdefs.h>

#include <memory>

extern "C" {

typedef struct DvrBuffer DvrBuffer;
typedef struct DvrReadBuffer DvrReadBuffer;
typedef struct DvrWriteBuffer DvrWriteBuffer;

}  // extern "C"

namespace android {
namespace dvr {

class BufferProducer;
class BufferConsumer;
class IonBuffer;

DvrBuffer* CreateDvrBufferFromIonBuffer(
    const std::shared_ptr<IonBuffer>& ion_buffer);

DvrReadBuffer* CreateDvrReadBufferFromBufferConsumer(
    const std::shared_ptr<BufferConsumer>& buffer_consumer);
DvrWriteBuffer* CreateDvrWriteBufferFromBufferProducer(
    const std::shared_ptr<BufferProducer>& buffer_producer);

}  // namespace dvr
}  // namespace android

extern "C" {

struct DvrWriteBuffer {
  std::shared_ptr<android::dvr::BufferProducer> write_buffer;
};

struct DvrReadBuffer {
  std::shared_ptr<android::dvr::BufferConsumer> read_buffer;
};

struct DvrBuffer {
  std::shared_ptr<android::dvr::IonBuffer> buffer;
};

}  // extern "C"

#endif  // ANDROID_DVR_INTERNAL_H_
