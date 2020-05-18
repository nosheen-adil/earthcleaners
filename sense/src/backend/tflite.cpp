#include <sense/backend/tflite.hpp>

namespace sense {
namespace backend {

Tflite::Tflite(const std::string filename) {
  LoadModel(filename);
}

void Tflite::LoadModel(const std::string filename) {
  auto opResolver = tflite::ops::builtin::BuiltInOpResolver;
  auto errorReporter = tflite::DefaultErrorReporter();
  auto model = tflite::FlatBufferModel::BuildFromFile(filename.c_str(), errorReporter);
  auto builder = tflite::InterpreterBuilder(model, opResolver);
  builder(&interpreter);
}

} // namespace backend
} // namespace sense