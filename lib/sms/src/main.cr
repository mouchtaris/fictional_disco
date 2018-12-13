# vim: et ts=2 sw=2

require "./impls"

struct Main
  include Actions

  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
    @logger = Logging.logger_for "Main"
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
      # TODO mod main header file
      conf_each_comp(mod_name) do |comp_name, comp|
        details = Impls::ComponentHeaderDetails.new(@conf, mod_name, comp_name)
        src = Impls::Source.new(@conf, details)
        src.rewrite!
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
