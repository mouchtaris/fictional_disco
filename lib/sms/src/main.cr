# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"
require "./conf_dir_views"
require "./cmake"
require "./file_views"
require "./source"

module Impls
  class Conf
    include ConfDirViews
    def initialize(@conf)
    end
  end

  class CMake
    include ::CMake
    def initialize(@io, @conf)
    end
  end

  class Source
    include ::Source
    def initialize(@conf)
      @mod_name = "Tpf"
      @comp_name = "def"
      @lines = File.read_lines "../../src/Tpf/def.cpp"
    end
  end
end

struct Main
  include ::Logging

  def initialize(argv)
    super()
    sms_root = argv[0]
    @conf = Impls::Conf.new(ConfDirStorage.new(sms_root))
  end

  def generate_cmake
    path = File.join(
      @conf.conf_sms_root,
      @conf.conf_project_root,
      "CMakeLists.txt"
    )
    log.info "Writing cmake lists file to #{path}"
    File.open(path, "w") do |fout|
      Impls::CMake.new(fout, @conf.conf).call
    end
  end

  def main
    generate_cmake
    pp Impls::Source.new(@conf.conf).header_generated_lines_count
  end

  def self.main
    Main.new(ARGV.dup).main
  end
end

Main.main
