# vim: et ts=2 sw=2

require "./impls"

struct Main
  include Actions

  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
    @logger = Logging.logger_for "Main"
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
