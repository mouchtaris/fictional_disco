# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"
require "./conf_dir_views"
require "./cmake"
require "./file_views"
require "./source"
require "./source_details"
require "./component_source_details"

module Impls
  struct CMake
    include ::CMake
    def initialize(@io, @conf)
    end
  end

  class Source
    include ::Logging
    include ::Source
    def initialize(
      @conf,
      @source_details : SourceDetails
    )
      @logger = Logging.logger_for "Source"

      path_ = @source_details.path
      log.info "Initializing #{@mod_name}::#{@comp_name} with #{path_}"
      if File.exists? path
        @lines = File.read_lines path_
      else
        @lines = [] of String
      end
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
      mod.subconf(:comps).list.each do |comp_name|
        details = ComponentSourceDetails.new(mod_name, comp_name)
        src = Impls::Source.new(@conf, details)
        src.rewrite!
      end
    end
  end

  def main
    generate_cmake
    generate_source_files
  end

  def self.main
    Main.new(ARGV.dup).main
  end
end

Main.main
