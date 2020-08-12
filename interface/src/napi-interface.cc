#include <iostream>
#include <string>

#include <napi.h>

#include "native.h"

using namespace Napi;


String napiGreet(const CallbackInfo& info) {
  Env env = info.Env();
  std::string name = info[0].ToString();
  return String::New(env, greet(name));
}

Value napiAdd(const CallbackInfo& info) {
  Env env = info.Env();
  std::cout << info.Length() << std::endl;

  if (info.Length() < 2) {
    TypeError::New(env, "It needs two arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    TypeError::New(env, "Arguments must be two numbers").ThrowAsJavaScriptException();
    return env.Null();
  }

  double arg0 = info[0].As<Number>().DoubleValue();
  double arg1 = info[1].As<Number>().DoubleValue();
  double result = add(arg0, arg1);
  Number num = Number::New(env, result);

  return num;
}

Object Init(Env env, Object exports) {
  exports.Set(
    String::New(env, "greet"), Function::New(env, napiGreet)
  );
  exports.Set(
    String::New(env, "add"), Function::New(env, napiAdd)
  );
  return exports;
}

NODE_API_MODULE(addon, Init)
