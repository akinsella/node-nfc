#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;


struct Nfc: ObjectWrap {
  static Handle<Value> New(const Arguments& args);
  static Handle<Value> Ping(const Arguments& args);
};

Handle<Value> Nfc::New(const Arguments& args) {
  HandleScope scope;

  assert(args.IsConstructCall());
  Nfc* self = new Nfc();
  self->Wrap(args.This());

  return scope.Close(args.This());
}

// emits ping event
Handle<Value> Nfc::Ping(const Arguments& args) {
  HandleScope scope;

  Handle<Value> argv[2] = {
    String::New("ping"), // event name
    args[0]->ToString()  // argument
  };

  MakeCallback(args.This(), "emit", 2, argv);

  return Undefined();
}

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("Hello World"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"), FunctionTemplate::New(Method)->GetFunction());

  HandleScope scope;

    Local<FunctionTemplate> nfc = FunctionTemplate::New(Nfc::New);
    nfc->InstanceTemplate()->SetInternalFieldCount(1);
    nfc->SetClassName(String::New("Nfc"));
    NODE_SET_PROTOTYPE_METHOD(nfc, "ping", Nfc::Ping);

    exports->Set(String::NewSymbol("Nfc"), nfc->GetFunction());
}

NODE_MODULE(nfc, init)