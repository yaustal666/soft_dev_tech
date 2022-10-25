class BufferedReader {
 public:
  explicit BufferedReader(PackageStream* stream);
  int32_t Read(char* output_buffer, int32_t buffer_len);
};

class PackageStream {
 public:
  PackageStream(std::string source, int32_t package_len) {
    this->source = source;
    this->package_len = package_len;
  };

  int32_t PackageLen() const { return this->package_len; };
  int32_t ReadPackage(char* output_package);

 private:
  std::string source;
  int32_t package_len;
};