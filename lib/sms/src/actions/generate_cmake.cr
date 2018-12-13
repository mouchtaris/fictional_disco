# vim: et ts=2 sw=2

module Actions
  module GenerateCMake
    include Action

    def generate_cmake
      path = File.join(
        conf_sms_root,
        conf_project_root,
        "CMakeLists.txt"
      )
      log.info "Writing cmake lists file to #{path}"
      File.open(path, "w") do |fout|
        Impls::CMake.new(fout, @conf).call
      end
    end
  end
end
