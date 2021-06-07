// PR c++/49387
// { dg-require-effective-target rtti_enabled }

#include <typeinfo>

struct ResourceMonitorClient { };

template <typename T> struct ResourcePool : public ResourceMonitorClient {
  virtual ~ResourcePool() { }
};

template <typename T> struct BaseWriter {

  BaseWriter() {
    typeid(ResourcePool<int>*);
  }

  virtual void run() {
    ResourcePool<int> pool;
  }

};

BaseWriter<void> b;
