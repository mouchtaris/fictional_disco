# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"
require "./conf_dir_views"
require "./cmake"
require "./file_views"
require "./line_adder"
require "./sagas"
require "./source_details"
require "./component_details"
require "./component_header_details"
require "./component_source_details"
require "./mod_main_source_details"
require "./source"

module Impls
  struct CMake
    include ::CMake
    def initialize(@io, @conf)
    end
  end

  struct Source
    include ::Logging
    include ::Source
    def initialize(
      @conf,
      @source_details : SourceDetails
    )
      @logger = Logging.logger_for "Source"

      path = @source_details.path
      log.info "Initializing #{@source_details.path}"
      if File.exists? path
        @lines = File.read_lines path
      else
        @lines = [] of String
      end
    end
  end

  struct ComponentSourceDetails
    include ::ComponentSourceDetails
    def initialize(@conf, @mod_name, @comp_name)
    end
  end

  struct ComponentHeaderDetails
    include ::ComponentHeaderDetails
    def initialize(@conf, @mod_name, @comp_name)
    end
  end

  struct ModMainSourceDetails
    include ::ModMainSourceDetails
    def initialize(@conf, @mod_name)
    end
  end
end

struct Main
  include ::Logging
  include ::ConfDirViews

  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
    @logger = Logging.logger_for "Main"
  end

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

  def generate_source_files
    conf_each_mod do |mod_name, mod|
      begin
        details = Impls::ModMainSourceDetails.new(@conf, mod_name)
        src = Impls::Source.new(@conf, details)
        src.rewrite!
      end
      conf_each_comp(mod_name) do |comp_name, comp_conf|
        details = Impls::ComponentSourceDetails.new(@conf, mod_name, comp_name)
        src = Impls::Source.new(@conf, details)
        src.rewrite!
      end
    end
  end

  def generate_header_files
    conf_each_mod do |mod_name, mod|
      conf_each_comp(mod_name) do |comp_name, comp|
        details = Impls::ComponentHeaderDetails.new(@conf, mod_name, comp_name)
        src = Impls::Source.new(@conf, details)
      end
    end
  end

  def main
    generate_cmake
    generate_source_files
    generate_header_files
  end

  def self.main
    Main.new(ARGV.dup).main
  end
end

Main.main
