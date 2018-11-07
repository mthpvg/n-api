#include <napi.h>
#include <string>

// using namespace Napi;

Napi::String greeting(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  std::string name = info[0].ToString();
  std::string hello = "Hello ";
  Napi::String result = Napi::String::New(env, hello + name);

  return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(
    Napi::String::New(env, "greeting"),
    Napi::Function::New(env, greeting)
  );
  return exports;
}

NODE_API_MODULE(addon, Init)
