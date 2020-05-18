
namespace sense {
namespace backend {

// load model and run given inputs
// provide tf tensor outputs
class Tflite : public Base {
 public:
  Tflite(const std::string filename);

  void Run() override;
 
 protected:
  void LoadModel(const std::string filename) override;

 private:
  std::unique_ptr<tflite::Interpreter> interpreter;
};

} // namespace backend
} // namespace sense